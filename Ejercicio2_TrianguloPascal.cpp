//Ejercicio practico 2 - Triangulo de Pascal 

//Bibliotecas 
#include <iostream>
#include <vector>
using namespace std;

//Menu
void mostrarMenu() {
    cout << "======== TRIÁNGULO DE PASCAL =======" << endl;
    cout << "--------------- MENU ---------------" << endl;
    cout << "1. Generar Triángulo de Pascal" << endl;
    cout << "2. Salir" << endl;
}

// Esta funcion recibe como parametro un vector de enteros y
// Se encarga de imprimir los elementos del vector en consola
void imprimirArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

//Esta es una funcion recursiva el cual genera una linea del triangulo de pascal
vector<int> obtenerLineaPascal(int n) {
    if (n == 1) {
        return { 1 };
    }
    else {
        vector<int> prev = obtenerLineaPascal(n - 1);
        vector<int> current(n, 1);
        for (int i = 1; i < n - 1; i++) {
            current[i] = prev[i - 1] + prev[i];
        }
        return current;
    }
}

// Funcion principal del programa
// En esta funcion use do-while el cual permite que se repita el menu hasta el user 
// decida salirse.
int main() {
    char opcion;
    do {
        mostrarMenu();
        cout << "¿Qué opción desea elegir? ";
        cin >> opcion;

        switch (opcion) {
        case '1': {
            int numIteraciones;
            cout << "Ingrese el número de iteraciones (1-50): ";
            cin >> numIteraciones;

            if (numIteraciones < 1 || numIteraciones > 50) {
                cout << "El número de iteraciones debe estar entre 1 y 50." << endl;
            }
            else {
                for (int i = 1; i <= numIteraciones; i++) {
                    vector<int> lineaPascal = obtenerLineaPascal(i);
                    cout << "Iteración " << i << ": ";
                    imprimirArray(lineaPascal);
                }
            }
            break;
        }
        case '2':
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
            break;
        }

    } while (opcion != '2');

    return 0;
}
