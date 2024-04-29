#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {
	//Cambiamos la semilla a null para que los numeros random varien cada segundo
	srand(time(NULL));
	//Declaraciones
	int maquina;
	int persona;
	char *ppp[] = "piedra", "papel", "tijera";
	//Instrucciones
	puts("Bienvenido a piedra, papel o tijera \n");
	

	//Juego
	for (int i = 0; i < 5; i++ ){
		for (int j = 0; i < 3; j++) {
			maquina = rand() % 3 + 1; 
				printf("Ingresa un numero (1 = piedra, 2 = papel, 3 = tijera): \n");
				//Eleccion de jugador
				scanf("%d", &persona);
				
				printf("El jugador eligio %s", ppp[persona - 1]);
				printf("La maquina eligio %s", ppp[persona - 1]);
				
				if (maquina == 1 && persona == 2 || maquina == 2 && persona == 3 || maquina == 3 && persona == 1) {
					printf("Gana el jugador(persona)");
				}
				else if (maquina == 1 && persona == 3 || maquina == 2 && persona == 1 || maquina == 3 && persona == 2) {
					printf("Gana la maquina");
				}
				else {
					printf("Empate");
				}
			j++;
		}
	}
		
	
	

	
	
	
	
	
	return 0;
}
