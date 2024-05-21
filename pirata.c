#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void tablero(){
	int num;
	printf("Escribi el numero del tamanio del tablero\n");
    scanf("%d",&num);
    char *tabla[num][num];
    int piratafila;
    int piratacol;
    int tesorofila;
    int tesorocol;
    for(int i = 0; i < num;i++){
    	for(int j = 0; j < num;j++){
    		if(i == 0 && j == num - 1 || i == num - 1 && j == 0){
    		tabla[i][j] = "|B|";	
			}
            else if(i == 0 || i == num - 1 || j == 0 || j == num - 1){
    		tabla[i][j] = "|A|";	
			}
            else{
    		tabla[i][j] = "|-|";
			}
		}
	}
	do{
    piratafila = (rand() % (num - 2)) + 1;
    piratacol = (rand() % (num - 2)) + 1;
    tesorofila = (rand() % (num - 2)) + 1;
	tesorocol = (rand() % (num - 2)) + 1;	
	} 
        while(piratafila == tesorofila && piratacol == tesorocol);
	tabla[piratafila][piratacol] = "|P|";
	buscar(num, tabla, piratacol, piratafila, tesorocol, tesorofila);	
    tabla[tesorofila][tesorocol] = "|T|";
}

void imprimir(int num,char *tabla[num][num]){
for(int i = 0; i < num;i++){
	for(int j = 0; j < num;j++){
		printf("%s",tabla[i][j]);
	}
	printf("\n");
}	
}

void buscar(int num, char *tabla[num][num], int piratacol, int piratafila, int tesorocol, int tesorofila) {
	int encontrado = 0;
	for(int var = 0; var <= 50 && encontrado == 0; var++ ) {
	imprimir(num,tabla);
	printf("%d %d", tesorofila + 1, tesorocol + 1);
	printf("El pirata esta en la fila %d columna %d\n", piratafila, piratacol);
	tabla[piratafila][piratacol] = "|-|";
	printf("Elija la fila en la que quiere posicionarse: ");
	scanf("%d",&piratafila);
	printf("Elija la columna en la que quiere posicionarse: ");
	scanf("%d",&piratacol);
	tabla[piratafila][piratacol] = "|P|";
		if(piratac - 1 == tesorocol && piratafila - 1 == tesorofila) {
			printf("GANASTE\n");
			tabla[tesorofila][tesorocol] = "|T|";
			imprimir(num, tabla);
			encontrado = 1;
		}

	}
}



int main(int argc, char *argv[]) {
	srand(time(NULL));
	tablero();
	return 0;
}
