#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define YELLOW "\x1b[33m"
#define YELLOWBACK "\x1b[43m"
#define BLUE "\x1b[34m"
#define BLUEBACK  "\x1b[44m"
#define BROWN "\x1b[38;5;94m"
#define BROWNBACK "\x1b[48;5;94m"
#define RED "\x1b[31m"
#define BLACK "\x1b[30m"
#define RETURN "\x1b[0m"



void tutorial (){
	system("cls");
	printf("El objetivo  del juego es encontrar el tesoro tan deseado, pero no sera tan facil, ya que tienes que tener cuidado de\n");
	printf("no caerte al agua ni cansarte, por lo que tendras intentos limitados \n \nComo iniciar el juego?\nAl inicio del juego se pedira al jugador");
	printf("que ingrese el largo y ancho del tablero, ingresando primero las filas y luego  las columnas, designando asi el tamanio de la isla. \n");
	printf("Cuando se genere el tablero, veras como aparece una P, que indica el posicionamiento del pirata, y para que este se \nmueva, el jugador tendra ");
	printf("que ingresar hacia donde desea mover al bucanero. El sistema de movimiento se basa en \nuna rosa de los vientos (Norte, Sur, Este y Oeste) ");
	printf("ingresando las iniciales de cada direccion se movera el pirata\n \n");
	menu ();
}

void menu(){
	
	puts("1. Iniciar la busqueda del tesoro YAAARRRRR");
	puts("2. Como se juega?");
	printf("que opcion desea realizar?: \n");
	int desicion;
	scanf("%d" , &desicion);
	if (desicion == 2){
		tutorial();
	} else if (desicion == 1){
		tabla();
	} else if(desicion != 1 || desicion != 2 ){
		printf("ingrese una opcion valida");
		menu();
	}
}

void tabla(){
	int numf;
	int numc;

	system("cls");

	puts("YARRRRR Bucanero, bienvenido a la busqueda del tesoro, antes que nada, debes elegir a que isla nos dirijiremos");

	printf("Cuantas filas desea que sea de alto sea la isla (5 minimo)? \n");
    scanf("%d",&numf);
    printf("Cuantas columnas desea que sea de largo la isla (5 minimo)?  \n");
    scanf("%d", &numc);
    char *tabla[numf][numc];
    int pfila;
    int pcol;
    int tfila;
    int tcol;
    //int decision;
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
	system("cls");
for(int i = 0; i < numf;i++){
	for(int j = 0; j < numc;j++){
		if(tabla[i][j] == "|-|"){
			printf( YELLOW YELLOWBACK "%s" RETURN,tabla[i][j]);
		} else if(tabla[i][j] == "|A|"){
			printf( BLUE BLUEBACK "%s" RETURN ,tabla[i][j]);
		} else if(tabla[i][j] == "|B|"){
			printf( BROWN BROWNBACK "%s" RETURN ,tabla[i][j]);
		} else if (tabla[i][j] == "|P|"){
			printf( BLACK YELLOWBACK "%s" RETURN ,tabla[i][j]);
		} else if (tabla[i][j] == "|x|"){
			printf( RED YELLOWBACK "%s" RETURN ,tabla[i][j]);
		} else if (tabla[i][j] == "|T|"){
			printf( BLACK YELLOWBACK "%s" RETURN ,tabla[i][j]);
		}
		
		
	}
	printf("\n");
}	
}

void moverse(int numf, int numc, char *tabla[numf][numc], int pcol, int pfila, int tcol, int tfila){
	int encontrado = 0;
	char movimiento;
	for(int var = 0; var <= 50 && encontrado == 0; var++ ) {
	imprimir(numf, numc,tabla);
	printf("Hacia que direccion desea moverse??? (N, S, E, O)\n");
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
			tabla[pfila][pcol] = "|T|";
			imprimir(numf, numc, tabla);
			encontrado = 1;
		}
	else if(pfila == 0 || pfila == numf - 1 || pcol == 0 || pcol == numc - 1) {
			printf("Te caiste al agua boludin\n");
			//return 0;
			char SyN;
			printf ("quieres volver a intentar (S o N)?");
			scanf("%c" , &SyN);
			if (SyN == "S" || SyN == "s"){
				printf("desea estar en la misma isla (S para permanecer o N para irte)?: ");
				scanf("%c" , &SyN);
				if(SyN == "S" || SyN == "s"){
					
				}
			}
		}

	
}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	printf("Hola bucanero, bienvenido a \nPIRATAS EN LATZINA\n \n");
	menu();
	return 0;
}
