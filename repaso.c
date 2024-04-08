#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ejercicio;

    printf("A que ejercicio quiere acceder? \n");
    printf("1: \n");
    printf("2: \n");
    printf("3: \n");
    printf("4: \n");
    printf("5: \n");
    scanf("%d", &ejercicio);

    int alumnos = 0;
    int valor = 0;
    double sueldo = 0;
    double venta1, venta2, venta3;
    double parcial1, parcial2, parcial3;
    double e_final;    
    double t_final;
    int limit, limit2;
    double km1 = 70;
    double km2 = 150;
    double encuentro;

    switch (ejercicio) {
case 1:
    printf("Ingrese cantidad de alumnos: \n");
    scanf("%d", &alumnos);
    
    if (alumnos >= 100) {
        int valor = alumnos * 500;
        printf("El costo del micro es de: %d", valor);
    }
    else if (alumnos >= 50 && alumnos <= 90) {
        int valor = alumnos * 400;
        printf("El costo del micro es de: %d", valor);
    }
    else if (alumnos >= 30 && alumnos <= 49) {
        int valor = alumnos * 300;
        printf("El costo del micro es de: %d", valor);
    }
    else {
        printf("El costo del micro es de 6000$");
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
    else {
        printf("La calificacion final del alumno es de: %1.f", calificacion_final);
    }
    break;
case 4:
    printf("Ingrese dos numeros limitrofes: \n");
    scanf("%d %d", &limit, &limit2);

    for (int i = limit; i < limit2; i += 2) {
        printf("%d ", i);
    }

    break;
case 5:
    encuentro = (km2 + km1) / 2;
    printf("se encontraran en el kilometro %f", encuentro);
    break;
}

return 0;
}
