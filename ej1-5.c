#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int desicion;

    printf("A que ejercicio quiere acceder? \n");
    printf("1 \n");
    printf("2 \n");
    printf("3 \n");
    printf("4 \n");
    printf("5 \n");
    scanf("%d", &desicion);
//Ejercicio 1
    int num1;
    int num2;
    int num3;
//Ejercicio 2
    int prom1 = 60;
    int prom2 = 40;
    int prom3 = 80;
//Ejercicio 3
    int pos;
//Ejercicio 4
    int exam1, exam2, exam3, exam4;
    int tarea;
//Ejercicio 5
    int eval;

    switch(desicion) {
    case 1:
        num1 = (87/3) +1;
        num2 = (87/3) -1;
        num3 = (87/3);
        printf("%d + %d + %d =87 \n", num1, num2, num3);

        break;

    case 2: 
        int promedio = (prom1 + prom2 + prom3) / 3;
        printf("La media de los tres numeros es: %d", promedio);

        break;
    case 3:
        printf("Ingrese numero positivo mayor a 0 \n");
        scanf("%d", &pos);

        if (pos % 2 == 0) {
            printf("El numero es par \n");
        }
        else {
            printf("El numero es impar \n");
        }
        
        break;
    case 4:
        printf("Ingrese las notas de las cuatro pruebas \n");
        scanf("%d %d %d %d", &exam1, &exam2, &exam3, &exam4);
        printf("Ingrese la nota de la tarea \n");
        scanf("%d", &tarea);

        int promedio2 = (exam1 + exam2 + exam3 + exam4 + tarea) / 5;
        
        if(promedio2 >= 6) {
            printf("El alumno aprobo la materia, nota final: %d \n", promedio2);
        }
        else {
            printf("El alumno desaprobo la materia, nota final: %d \n", promedio2);
        }
        
        break;
    case 5:
        printf("Ingrese la nota de la evaluacion \n");
        scanf("%d", &eval);

        if(eval >= 6) {
            printf("Aprobaste \n");
                if (eval >= 8) {
                    printf("Felicitaciones \n");
                }
        }
        else if (eval < 6) {
            printf("Desaprobaste \n");
                if (eval == 1) {
                    printf("Debes esforzarte mas \n");
                }      
        }
        break;

            
        }

    }
    return 0;
}
