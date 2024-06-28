#include <iostream>

using namespace std;

//Declaro los colores que se utilizan
#define Rojo "\033[0;31m" 
#define Cyan "\033[0;36m"
#define RESET_COLOR "\033[0m"
//Defino VIANDAS y OPERADORES para trabajar mas comodo
#define VIANDAS 4 
#define OPERADORES 7 
int precios[VIANDAS] = {10, 5, 20, 15};

void pedido(int viandas[OPERADORES][VIANDAS]) {
    int operador;
    int cantidad;
    int meal;
    int c4 = 0;
    cout << Rojo "Pedido:" RESET_COLOR << endl << endl;
    while (true) {
        cout << Cyan "Ingresa el tipo de comida que queres en la vianda: " RESET_COLOR << endl << endl;
        cout << Rojo "1. Vegetales" << endl
             << "2. Carnes" << endl
             << "3. Pescado" << endl
             << "4. Frutas" << endl
             << "0. Salir" RESET_COLOR << endl << endl
             << "Nro: ";
        cin >> meal;
        if (meal == 0) {
            break;
        }
        //Se chequea que meal este entre 1 y 4
        if (meal < 1 || meal > 4) {
            cout << "Tipo de comida no válida, intente de nuevo." << endl;
            continue;
        }
        
        cout << "Con que operador quiere hablar: " << endl;
        cin >> operador;
        //Se chequea que meal este entre 1 y 7
        if (operador < 1 || operador > 7) {
            cout << "Operador no válido, intente de nuevo." << endl;
            continue;
        }

        cout << "Ingresa la cantidad de viandas de ese tipo que queres: ";
        cin >> cantidad;
        //Se chequea que se ingrese una cantidad valida
        if (cantidad == 0) {
            cout << "Ingresa una cantidad distinta a 0." << endl;
            continue;
        }
        //Se le suma 1 a la variable que almacena la cantidad de ventas de mas de 4 unidades
        if (cantidad >= 4) {
            c4++;
        }
        cout << "Hubieron en total " << c4 << " ventas que superaron las 4 unidades" << endl << endl;
        viandas[operador - 1][meal - 1] += cantidad; 
    }
}

int valorTotal(int viandas[OPERADORES][VIANDAS], int precios[VIANDAS]) {
    int VT = 0;
    //Recorrer viandas y precios para conseguir el valor total
    for (int i = 0; i < OPERADORES; i++) { 
        for (int j = 0; j < VIANDAS; j++) {
            VT += (viandas[i][j] * precios[j]); //Se calcula el valor total
        }
    }
    return VT;
}

void results(int viandas[OPERADORES][VIANDAS], int precios[VIANDAS]) {
    int valorGen = valorTotal(viandas, precios); //Se le asigna el valor de VT a la variable valorGen
    cout << "Se ganó un total de " << valorGen << endl << endl;

    for (int i = 0; i < OPERADORES; i++) {
        cout << Rojo "Operador " << i + 1 << endl << endl; //Imprimir el operador al que se le cuentan las ventas por vianda
        cout << "" RESET_COLOR;
        for (int j = 0; j < VIANDAS; j++) {
            cout << "Vendió un total de " << viandas[i][j] << " viandas de tipo " << j + 1 << endl; //Imprimir cuantas viandas vendió cada operador
        }
        cout << "" << endl;
    }

    // Calcular y mostrar comisiones
    for (int i = 0; i < OPERADORES; i++) {
        int totalVentasOperador = 0;
        bool tieneVentaMayorA4 = false;
        for (int j = 0; j < VIANDAS; j++) {
            totalVentasOperador += viandas[i][j] * precios[j]; //Calcular la cantidad de ventas del operador
            if (viandas[i][j] >= 4) {
                tieneVentaMayorA4 = true;
            }
        }
        //Calcular la comision que recibe el operador
        int comision = totalVentasOperador * 0.10;
        if (tieneVentaMayorA4) {
            comision += totalVentasOperador * 0.03;
        }
        cout << "El Operador n° " << i + 1 << " consigue una comisión de: " << comision << endl; //Imprimir la comisión de cada operador
    }
}

int main() {
    int viandas[OPERADORES][VIANDAS] = {0};
    pedido(viandas); //Llamada a la funcion pedido
    results(viandas, precios); //Llamada a la funcion results
    return 0;
}
