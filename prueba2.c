#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROJO "\x1b[31m"




int main()
{
    srand(time(NULL)); //Se inicializa la semilla para que cambie el valor random a cada segundo
    //Numero de jugador (dice que hay que utilizar del 1 a 30)
    int njugador[7];
    //Numero de juegos (dice que hay que utilizar del 1 al 7)
    int njuego[7];
    //calificacion para el jugador
    int cal[7];
    //Monto de premio para el top 7
    int premio[7];
    
    //Se inicia un ciclo for para asignar valor a los premios por puesto
    printf("Ingrese el valor de premio por puesto (1/7): \n");
    for(int i = 0; i < 7; i++) {
        printf("Puesto n°%d: \n", i + 1);
        scanf("%d", &premio[i]); //Se lee y guarda el valor ingresado por entrada
    }
   for(int i = 0; i < 7; i++) {
        njugador[i] = rand() % 30 + 1; //Se le asigna numero al jugador
        if (njugador == 0) { //Se verifica que el numero de jugador no sea igual a 0
       return 1;
   }
   }
    
    //Se inicia un ciclo for para asignar valor a juego
    for (int i = 0; i < 7; i++) {
        njuego[i] = rand() % 7 + 1; //Se le asigna numero al juego
        if (njuego == 0) { //Se verifica que el numero de juego no sea igual a 0
       return 1;
        }
   }
   for(int i = 0; i < 7; i++) {
    cal[i] = rand() % 10 + 1; //Se asigna una calificacion
    if (cal == 0) { //Se verifica que el numero de calificacion no sea igual a 0
        return 1;
    }
   }

   for(int i = 0; i < 7; i++) {
       printf("El premio del jugador n°%d es: %d", njugador[i], premio[i]); //Se imprime el premio del jugador por su top
   }
   printf("El promedio de calificaciones es: %d \n", promedio(cal[7])); //Se llama a la funcion promedio y se imprime el promedio
   
    return 0;
}
int promedio(int cal[7]) {
    int prom;
    for (int i = 0; i < 7; i++) {
        prom += cal[i] % 7; //Se calcula el promedio
    }
    return prom;
}
