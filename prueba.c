#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int desicion;

    printf("Elegi el ejercicio al que queres acceder: \n");
    printf("1 \n");
    printf("2 \n");
    printf("3 \n");
    printf("4 \n");
    printf("5 \n");
    scanf("%d", &desicion);

//Ejercicio 1
    int Hentrada;
    int Hsalida;
    int precio = 500;
//Ejercicio 2
    int num, num2;
    int producto;
//Ejercicio 3
    int km;
    int precioC;
    int h, m;
    int TotalP;
//Ejercicio 4
    int CantidadEntradas;
    int ValorEntradas;
//Ejercicio 5
    int personas;
    int total = 0;


    switch (desicion) {
    case 1:
        printf("Ingresa hora de entrada (en formato militar): \n");
        scanf("%d", &Hentrada);
        printf("Ingrese hora de salida (en formato militar): \n");
        scanf("%d", &Hsalida);
        
        

        printf("El total a pagar es de: %d", precio);
    
        
        break;
    case 2:
        printf("Ingresa dos numeros positivos y enteros: \n");
        scanf("%d %d", &num, &num2);

        if (num < 0 || num2 < 0) {
            printf("Ingresa dos numeros POSITIVOS Y ENTEROS: \n");
            return 1;
        }
        if (num < num2) {
        for (int i = 0; i < num2; i++)
        {
            producto = num + num2;
        }
        }
        else {
            for (int i = 0; i < num; i++)
            {
                producto = num + num2;
            }
        }
            printf("El producto es: %d \n", producto);
            break;
           
            
    case 3:
        printf("Ingrese la cantidad de km recorridos: \n");
        scanf("%d", &km);
        printf("Ingrese el precio por litro del combustible: \n");
        scanf("%d", &precioC);
        printf("Ingrese el tiempo que se ha tardado(horas y min): \n");
        scanf("%d %d", &h, &m);


        break;
    case 4:
        printf("Ingresa la cantidad de entradas que queres comprar: \n");
        scanf("%d", &CantidadEntradas);

        //Valor de entradas es de 1000

        if (CantidadEntradas == 2) {
            ValorEntradas = (1000 * 2) * 0.90;
            printf("El valor con el descuento aplicado es: %d \n", ValorEntradas);
        }
        else if (CantidadEntradas == 3) {
            ValorEntradas = (1000 * 3) * 0.85;
            printf("El valor con el descuento aplicado es: %d \n", ValorEntradas);
        }
        else {
            ValorEntradas = (1000 * 4) * 0.80;
            printf("El valor con el descuento aplicado es: %d \n", ValorEntradas);
        }
        break;
    case 5:
        printf("Ingresa la cantidad de personas: \n");
        scanf("%d", &personas);

        if (personas < 200) {
            total = personas * 6500;
            printf("El valor total es de: %d \n", total);
        }
        else if (personas > 200 && personas <= 300) {
            total = personas * 5500;
            printf("El valor total es de: %d \n", total);
        }
        else {
            total = personas * 4500;
            printf("El valor total es de: %d \n", total);
        }
        break;
    }
    return 0;
}
