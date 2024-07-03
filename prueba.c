#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    // Variables para el ejercicio 1
    string hora_entrada, hora_salida;
    // Variables para el ejercicio 2
    double num1, num2;
    int producto;
    // Variables para el ejercicio 4
    int pago_a_realizar;
    int cantidad_entradas;
    int precio_entradas = 300;
    // Variables para el ejercicio 5
    int personas;
    int total = 0;


    int decision;
    cout << "1. Ejercicio 1" << endl;
    cout << "2. Ejercicio 2" << endl;
    cout << "3. Ejercicio 3" << endl;
    cout << "4. Ejercicio 4" << endl;
    cout << "5. Ejercicio 5" << endl;
    cout << "Seleccione el ejercicio al que desea acceder: ";
    cin >> decision;

    if (decision < 1 || decision > 5) {
        cout << "Ejercicio inválido." << endl;
        return 1;
    }

    switch(decision) {
        case 1:
            // Solicitar hora de entrada y hora de salida
            cout << "Ingrese la hora de entrada (formato militar, ej. 0830): ";
            cin >> hora_entrada;
            cout << "Ingrese la hora de salida (formato militar, ej. 1345): ";
            cin >> hora_salida;

            // Convertir horas de entrada y salida a minutos desde la medianoche
            {
                int entrada_minutos = stoi(hora_entrada.substr(0, 2)) * 60 + stoi(hora_entrada.substr(2));
                int salida_minutos = stoi(hora_salida.substr(0, 2)) * 60 + stoi(hora_salida.substr(2));

                // Calcular la duración en minutos
                int duracion_minutos = salida_minutos - entrada_minutos;

                // Calcular el total a pagar
                int total_pagar;
                if (duracion_minutos <= 60) {
                    total_pagar = 500;
                } else {
                    // Calcular horas completas adicionales
                    int horas_completas_adicionales = duracion_minutos / 60;
                    if (duracion_minutos % 60 != 0) {
                        horas_completas_adicionales++;
                    }
                    total_pagar = 500 + 250 * (horas_completas_adicionales - 1);
                }

                // Mostrar total a pagar
                cout << "El total a pagar por el servicio de estacionamiento es: $" << total_pagar << endl;
            }
            break;

        case 2:
            // Solicitar dos números enteros positivos
            cout << "Ingresa dos números positivos y enteros: ";
            cin >> num1 >> num2;

            // Verificar que sean positivos
            if (num1 < 0 || num2 < 0) {
                cout << "Por favor ingresa dos números POSITIVOS Y ENTEROS." << endl;
                return 1;
            }
            // Verificar que num1 sea entero
            if (num1 == floor(num1)) {
                cout << num1 << " es un número entero." << endl;
        } else {
                cout << num1 << " no es un número entero." << endl;
            return 1;
        }
        // Verificar que num2 sea entero
             if (num2 == floor(num2)) {
        cout << num2 << " es un número entero." << endl;
    } else {
        cout << num2 << " no es un número entero." << endl;
        return 1;
    }
            // Calcular el producto de num1 por num2 utilizando un bucle
            producto = 0;
            for (int i = 0; i < num2; i++) {
                producto += num1;
            }

            cout << "El producto es: " << producto << endl;
            break;

        case 4:
            // Pido la cantidad de entradas
            cout << "Cuantas entradas quiere comprar (Maximo 4): ";
            cin >> cantidad_entradas;
            // Verifico que la cantidad de entradas sea mayor a 0 y menor a 4
            if (cantidad_entradas > 4 || cantidad_entradas < 0) {
                cout << "Cantidad de entradas invalida (Minimo 1 y maximo 4)." << endl;
                return 1;
            }
            //Realizar los calculos para conseguir el precio del pago a realizar en base a las distintas cantidades de entradas
            if (cantidad_entradas == 2) {
                pago_a_realizar = (precio_entradas * 2) * 0.90;
                cout << "El pago a realizar es de: $" << pago_a_realizar << " pesos." << endl; 
            } else if (cantidad_entradas == 3) {
                pago_a_realizar = (precio_entradas * 3) * 0.85;
                cout << "El pago a realizar es de: $" << pago_a_realizar << " pesos." << endl; 
            } else if (cantidad_entradas == 4) {
                pago_a_realizar = (precio_entradas * 4) * 0.80;
                cout << "El pago a realizar es de: $" << pago_a_realizar << " pesos." << endl; 
            } else {
                pago_a_realizar = precio_entradas;
                cout << "El pago a realizar es de: $" << pago_a_realizar << " pesos." << endl; 
            }
            break;

        case 5:
        //Pedir la cantidad de personas
             cout << "Ingresa la cantidad de personas: " << endl;
             cin >> personas;
        //Realizar los calculos en base a las distintas situaciones
        if (personas < 200) {
            total = personas * 6500;
            cout << "El valor total es de: " << total << endl;
        }
        else if (personas > 200 && personas <= 300) {
            total = personas * 5500;
            cout << "El valor total es de: " << total << endl;
        }
        else {
            total = personas * 4500;
            cout << "El valor total es de: " << total << endl;
        }
        break;
    }

    return 0;
}
