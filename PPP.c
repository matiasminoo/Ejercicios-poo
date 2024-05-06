#include <stdio.h>
#include <stdlib.h>



int main() {
	// declaraciones
	
	int Persona;
	int Maquina;
	int elecc1;
	
	puts("¡Bienvenido a Piedra, Papel o Tijera!\n");
	
	printf("Queres aprender como jugar? \n");
	puts("1. Ver como se juega");
	puts("2. Comenzar juego");
	
	printf("Ingrese la opcion deseada: ");
	
	scanf("%d" , &elecc1);
	
	if(elecc1 == 1){
		puts("El objetivo es vencer al oponente seleccionando el arma que gana, segun las siguientes reglas:");
		puts("La piedra aplasta la tijera. (Gana la piedra.)");
		puts("La tijera corta el papel. (Gana la tijera.)");
		puts("El papel envuelve la piedra. (Gana el papel.)");
		puts("En caso de empate (que dos jugadores elijan el mismo elemento o que tres jugadores elijan cada uno un objeto distinto), se juega otra vez.");
		
	} else if (elecc1 != 2 || elecc1 !=1){
		
		puts("ingrese una opcion valida");
			
	}
	
	puts("Ahora si, ¡A comenzar el juego!");
	
	//Cambiamos la semilla a null para que los numeros random varien cada segundo
	srand(time(NULL));
	//Declaraciones
	int maquina;
	int persona;
	int vuelta_jugador = 0;
	int vuelta_maquina = 0;
	int ronda_jugador = 0;
	int ronda_maquina = 0;
	char *ppp[] = "piedra", "papel", "tijera";
	//Instrucciones
	puts("Bienvenido a piedra, papel o tijera \n");
	

	//Juego
	for (int i = 0; ronda_jugador < 3 && ronda_maquina < 3; i++ ){
		for (int j = 0; vuelta_jugador < 2 && vuelta_maquina < 2; j++) {
			//Se le asigna un valor por vuelta a maquina (piedra, papel o tijera)
			maquina = rand() % 3 + 1; 
				//Eleccion de jugador
				printf("Ingresa un numero (1 = piedra, 2 = papel, 3 = tijera): \n");
				scanf("%d", &persona);
				
				printf("El jugador eligio %s \n", ppp[persona - 1]);
				printf("La maquina eligio %s \n", ppp[maquina - 1]);
				
				if (maquina == 1 && persona == 2 || maquina == 2 && persona == 3 || maquina == 3 && persona == 1) {    //Gana el jugador
					printf("Gana la vuelta el jugador(persona) \n");
					vuelta_jugador++;
				}
				else if (maquina == 1 && persona == 3 || maquina == 2 && persona == 1 || maquina == 3 && persona == 2) {   //Gana la maquina
					printf("Gana la vuelta la maquina \n");
					vuelta_maquina++;
				}
				else if (maquina == persona)     //Empata la vuelta
				{   
					printf("Empata la vuelta \n");
					j--;
				}
			}
				if (vuelta_jugador > vuelta_maquina) {
					printf("Gana la ronda el jugador \n");
					ronda_jugador++;
				}
				else {
					printf("Gana la ronda la maquina \n");
					ronda_maquina++;
				}
			vuelta_jugador = 0;
			vuelta_maquina = 0;
		}
			if (ronda_jugador > ronda_maquina) {
				printf("El jugador gana la partida \n");
			}
			else {
				printf("La maquina gana la partida \n");
			}
		
return 0;
}
