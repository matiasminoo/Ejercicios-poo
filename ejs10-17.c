#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {

    int desicion;

    printf("A que ejercicio quiere acceder? \n");
    printf("1 \n");
    printf("2 \n");
    printf("3 \n");
    printf("4 \n");
    printf("5 \n");
    printf("6 \n");
    printf("7 \n");
    scanf("%d", &desicion);
//Ejercicio 11
    double parcial1, parcial2, parcial3;
    double e_final;    
    double t_final;
//Ejercicio 12
    double sueldo = 0;
    double venta1, venta2, venta3;
//Ejercicio 13
    float compra;
//Ejercicio 14
    int num;
//Ejercicio 15
    float alumnos;
    float hombres, mujeres;
//Ejercicio 16
    float pesos;
    float cotizacion;
//Ejercicio 17
    int edad;
    float peso;
    float Ppeso;
    char genero;


    switch (desicion) {
    case 1:
        printf("Ingrese calificacion de los examenes parciales: \n");
        scanf("%lf %lf %lf", &parcial1, &parcial2, &parcial3);

        printf("Ingrese la calificacion del examen final: \n ");
        scanf("%lf", &e_final);

        printf("Ingrese la calificacion del trabajo final: \n");
        scanf("%lf", &t_final);

        double calificacion_final = (parcial1 + parcial2 + parcial3 * 0.55 / 3) + (e_final * 0.30) + (t_final * 0.15);
        if (calificacion_final >= 10) {
        printf("La calificacion final del alumno es de: 10 \n");
        }
        break;
    case 2:
        printf("Ingrese el valor del sueldo base: \n");
        scanf("%lf",  &sueldo);

        printf("Ingrese el precio de cada venta: \n");
        scanf("%lf %lf %lf", &venta1, &venta2, &venta3);

        double pago = sueldo + (venta1 * 0.10) + (venta2 * 0.10) + (venta3 * 0.10);

        printf("El sueldo base es de: %2.f, y el sueldo + comisiones es de: %2.f. \n", sueldo, pago);
        break;
    case 3:
        printf("Ingrese el valor de su compra: \n");
        scanf("%f", &compra);

        compra = compra * 0.85;
        printf("El precio final de la compra es de: %.2f \n", compra);
        break;
    case 4:
        printf("Ingrese un numero: \n");
        scanf("%d", &num);

        if(num > 0) {
            printf("El numero absoluto es: %d \n", num);
        }
        else {
            num = num * -1;
            printf("El numero absoluto es: %d \n", num);
        }
        break;
    case 5:
        printf("Ingrese la cantidad total de alumnos: \n");
        scanf("%f", &alumnos);
        printf("Ingrese la cantidad de hombres: \n");
        scanf("%f", &hombres);
        printf("Ingrese la cantidad de mujeres: \n");
        scanf("%f", &mujeres);

        hombres = (hombres / alumnos) * 100;
        mujeres = (mujeres / alumnos) * 100;
        printf("El porcentaje de mujeres es: %.1f porciento \n", mujeres);
        printf("El procentaje de hombres es: %.1f porciento \n", hombres);
        break;
    case 6:
        printf("Ingrese la cantidad de pesos argentinos: \n");
        scanf("%f", &pesos);
        printf("Ingrese la cotizacion: \n");
        scanf("%f", &cotizacion);

        float dolares = pesos / cotizacion;
        printf("%1.f pesos son %.1f dolares", pesos, dolares);
        break;
    case 7:
        printf("Ingrese su edad: \n");
        scanf("%d", &edad);
        printf("Ingrese su peso: \n");
        scanf("%f", &peso);
        printf("Ingrese su genero: \n");
        scanf("%c", &genero);
        Ppeso = peso * 0.01;
       
        if (genero == "hombre") {
        float FCmaxH = ((210 - (0.5 * edad)) - Ppeso ) + 4;
        printf("%2.f", FCmaxH);
        }
        else {
        float FCmaxM = (210 - (0.5 * edad)) - Ppeso;
        printf("%2.f", FCmaxM);
        }
        break;
}
return 0;
}
