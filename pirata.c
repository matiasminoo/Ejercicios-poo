#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void tutorial (){
	printf("El objetivo  del juego es encontrar el tesoro tan deseado, pero no sera tan facil, ya que tienes que tener cuidado de\n");
	printf("no caerte al agua ni cansarte, por lo que tendras intentos limitados \n \nComo iniciar el juego?\nAl inicio del juego se pedira al jugador");
	printf("que ingrese el largo y ancho del tablero, ingresando primero las filas y luego  las columnas, designando asi el tamanio de la isla. \n");
	printf("Cuando se genere el tablero, veras como aparece una P, que indica el posicionamiento del pirata, y para que este se \nmueva, el jugador tendra ");
	printf("que ingresar hacia donde desea mover al bucanero. El sistema de movimiento se basa en \nuna rosa de los vientos (Norte, Sur, Este y Oeste) ");
	printf("ingresando las iniciales de cada direccion se movera el pirata\n \n");
	menu ();
}

void menu(){
	printf("Bienvenido a \nPIRATAS EN LATZINA\n \n");
	puts("1. Iniciar el juego");
	puts("2. Como se juega?");
	printf("que opcion desea realizar?: \n");
	int desicion;
	scanf("%d" , &desicion);
	if (desicion == 2){
		tutorial();
	}
}

void tabla(){
	int numf;
	int numc;
	menu();
	printf("Cuantas filas queres? \n");
    scanf("%d",&numf);
    printf("Cuantas columnas queres? \n");
    scanf("%d", &numc);
    char *tabla[numf][numc];
    int pfila;
    int pcol;
    int tfila;
    int tcol;
    int decision;
    for(int i = 0; i < numf;i++){
    	for(int j = 0; j < numc;j++){
    		if(i == 0 && j == numc - 1 || i == numf - 1 && j == 0){
    		tabla[i][j] = "|B|";	
			}else if(i == 0 || i == numf - 1 || j == 0 || j == numc - 1){
    		tabla[i][j] = "|A|";	
			}else{
    		tabla[i][j] = "|-|";
			}
		}
	}
	do{
    pfila = (rand() % (numf - 2)) + 1;
    pcol = (rand() % (numc - 2)) + 1;
    tfila = (rand() % (numf - 2)) + 1;
	tcol = (rand() % (numc - 2)) + 1;	
	} while(pfila == tfila && pcol == tcol);
	tabla[pfila][pcol] = "|P|";

	moverse(numf, numc, tabla, pcol, pfila, tcol, tfila);



}

void imprimir(int numf, int numc,char *tabla[numf][numc]){
for(int i = 0; i < numf;i++){
	for(int j = 0; j < numc;j++){
		printf("%s",tabla[i][j]);
	}
	printf("\n");
}	
}

void buscar(int numf, int numc, char *tabla[numf][numc], int pcol, int pfila, int tcol, int tfila) {
	int encontrado = 0;
	for(int var = 0; var <= 50 && encontrado == 0; var++ ) {
	imprimir(numf, numc,tabla);
	
	printf("la posicion  es %d %d\n", tfila + 1, tcol + 1);
	printf("El pirata esta en la fila %d columna %d\n", pfila, pcol);
	
	tabla[pfila][pcol] = "|-|";
	printf("Elija la fila en la que quiere posicionarse: \n");
	scanf("%d",&pfila);
	
	printf("Elija la columna en la que quiere posicionarse: \n");
	scanf("%d",&pcol);
	
	tabla[pfila][pcol] = "|P|";
		if(pcol - 1 == tcol && pfila - 1 == tfila) {
			printf("GANASTE\n");
			tabla[tfila][tcol] = "|T|";
			imprimir(numf, numc, tabla);
			encontrado = 1;
		}
    }
}

void moverse(int numf, int numc, char *tabla[numf][numc], int pcol, int pfila, int tcol, int tfila){
	int encontrado = 0;
	char movimiento;
	for(int var = 0; var <= 50 && encontrado == 0; var++ ) {
	imprimir(numf, numc,tabla);
	printf("Para donde??? (N, S, E, O)\n");
	//printf("%d %d\n", tfila + 1, tcol + 1);
	scanf(" %c",&movimiento);
	if(movimiento == 'N' || movimiento == 'n'){
		tabla[pfila][pcol] = "|x|";
		pfila--;
	}else if(movimiento == 'S' || movimiento == 's'){
		tabla[pfila][pcol] = "|x|";
		pfila++;
	}else if(movimiento == 'O' || movimiento == 'o'){
		tabla[pfila][pcol] = "|x|";
		pcol--;
	}else if(movimiento == 'E' || movimiento == 'e'){
		tabla[pfila][pcol] = "|x|";	
		pcol++;
	}
	tabla[pfila][pcol] = "|P|";
	if(pcol - 1 == tcol && pfila - 1 == tfila) {
			printf("Ganaste bestia\n");
			tabla[tfila][tcol] = "|T|";
			imprimir(numf, numc, tabla);
			encontrado = 1;
		}
	else if(pfila == 0 || pfila == numf - 1 || pcol == 0 || pcol == numc - 1) {
			printf("Te caiste al agua boludin\n");
			encontrado = 1;
		}

	
}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	tabla();
	return 0;
}
