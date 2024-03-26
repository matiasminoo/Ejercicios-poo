#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    int num;
    printf("Que ejercicio queres utilizar? \n");
    printf("1 \n");
    printf("2 \n");
    printf("3 \n");
    printf("4 \n");
    scanf("%d", &num);

    int a = 0;
    int b = 0;
    int c = 0;
    switch(num) {
    case 1:
        printf("Ingrese un numero a \n");
        scanf("%d", &a);
            if(a >= 0) {
                printf("a es positivo \n");
            }
            else{
                printf("a es negativo\n");
            }
             break;
            case 2:
        printf("Ingrese un numero a \n");
        scanf("%d", &a);
        if (a % 2 == 0) {
            printf("a es par \n");
        }
        else {
            printf("a es impar \n");
        }
         break;
            case 3:
                printf("Ingrese un numero a \n");
                scanf("%d", &a);
                if (a % 2 == 0 && a % 3 == 0) {
                        printf("a es multiplo de 2 y multiplo de 3 \n");
                }
                else if (a % 2 == 0) {
                    printf("a es multiplo de 2 \n");
                }
                else if (a % 3 == 0) {
                    printf("a es multiplo de 3 \n");
                }
                break;
            case 4:
                printf("ingrese los tres numeros que quiera comparar \n");
                scanf("%d %d %d", &a, &b, &c);
                if (a == b && a == c) {
                    printf("Los tres numeros son iguales \n");
                }
                else if (a > b && a > c) {
                    printf("%d es el numero mayor \n",a);
                }
                else if (b > a && b > c) {
                    printf("%d es el numero mayor \n", b);
                }
                else {
                    printf("%d es el numero mayor \n", c);
                }
                break;
                   
        }
           return 0;
}
