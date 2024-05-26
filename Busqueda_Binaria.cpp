// Busqueda_Binaria.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int obtenerNumRandom() { 
    return rand() % 1001 - 500;
}

void imprimirArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int busquedaBinaria(const vector<int>& arr, int numero) {
    int comparaciones = 0;
    int inicio = 0;
    int fin = arr.size() - 1;

    while (inicio <= fin) {
        comparaciones++;
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == numero) {
            return comparaciones;
        } else if (arr[medio] < numero) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1;
}

void mostrarMenu() {
    cout << "====== BUSQUEDA BINARIA ======" << endl;
    cout << "------------ MENU ------------" << endl;
    cout << "1. Realizar búsqueda" << endl;
    cout << "2. Salir" << endl;
    cout << "------------------------------" << endl;
}

int main() {
    srand(time(0));

    int longitud = 20;
    vector<int> arreglo(longitud);
    for (int i = 0; i < longitud; i++) {
        arreglo[i] = obtenerNumRandom();
    }

    // Ordenar el arreglo de forma ascendente (insertion sort)
    for (int i = 1; i < longitud; i++) {
        int key = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > key) {
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = key;
    }

    cout << "Arreglo generado y ordenado:" << endl;
    imprimirArray(arreglo);

    char opcion;
    do {
        mostrarMenu();
        cout << "¿Qué opción desea elegir? ";
        cin >> opcion;

        if (opcion == '1') {
            int numeroBuscar;
            cout << "Número por buscar: ";
            cin >> numeroBuscar;

            int comparaciones = busquedaBinaria(arreglo, numeroBuscar);
            if (comparaciones == -1) {
                cout << "El número " << numeroBuscar << " NO se encuentra dentro del arreglo." << endl;
            } else {
                cout << "El número " << numeroBuscar << " SI se encuentra dentro del arreglo." << endl;
                cout << "Número de comparaciones: " << comparaciones << "." << endl;
            }
        } else if (opcion != '2') {
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != '2');

    return 0;
}