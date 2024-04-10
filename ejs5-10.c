#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int desicion;

    printf("A que ejercicio quiere acceder? \n");
    printf("1 \n");
    printf("2 \n");
    printf("3 \n");
    printf("4 \n");
    printf("5 \n");
    scanf("%d", &desicion);

//Ejercicio 6
    int sueldo;
//Ejercicio 7
    int hh;
    int mm;
//Ejercicio 8
    int capital;
//Ejercicio 9
    int edadP = 50;
    int edadH = 20;
//Ejercicio 10
    int horas;
    int min;
    int segundos;
    int tiempo;

    switch(desicion) {
    case 1:
        printf("Ingrese su sueldo: \n");
        scanf("%d", &sueldo);

        if (sueldo <= 202) {
            printf("Tu sueldo despues de impuestos: %d \n", sueldo);
        }
        else if (sueldo > 202 && sueldo <= 607) {
            sueldo = sueldo * 0.95;
            printf("Tu sueldo despues de impuestos: %d \n", sueldo);
        }       
        else if (sueldo > 607 && sueldo <= 1013) {
            sueldo = sueldo * 0.90;
            printf("Tu sueldo despues de impuestos: %d", sueldo);
        }
        else if (sueldo > 1013 && sueldo <= 1418) {
            sueldo = sueldo * 0.85;
            printf("Tu sueldo despues de impuestos: %d", sueldo);
        }
        else if (sueldo > 1418) {
            sueldo = sueldo * 0.75;
            printf("Tu sueldo despues de impuestos: %d", sueldo);
        }
        break;

    case 2:
        printf("Ingrese una hora (hh:mm) en formato 24hs: \n");
        scanf("%d %d", &hh, &mm);

        if (hh >= 12) {
            hh = hh - 12;
            if (hh == 12) {
                printf("La hora es: 12:%d", mm);
            }
            else {
            printf("La hora es: %d:%d", hh, mm);
        }
        }
        
        break;

    case 3:
        printf("Ingrese su capital: \n");
        scanf("%d", &capital);
        
        capital = capital * 1.02;
        printf("Su capital + la ganancia es de: %d \n", capital);
        break;

    case 4:
        for (edadP; edadP != 60; edadP++)
        {
            edadH++;
        }
        printf("La edad del padre sera el doble (%d) que la del hijo cuando el hijo tenga %d años. \n",edadP, edadH);
        break;
    case 5:
        printf("Ingrese el tiempo deseado: \n");
        scanf("%d", &segundos);

        while (segundos >= 60) {
            if (segundos >= 60) {
                min = min + 1;
                segundos = segundos - 60;
            }
            if (min >= 60) {
                horas = horas + 1;
                min = min - 60;
            }
        }
        printf("El tiempo sera %d H %d Min %d Seg", horas, min, segundos);
        break;
    }

    return 0;
}
