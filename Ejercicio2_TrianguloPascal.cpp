//Ejercicio practico 2 - Triangulo de Pascal 

//Bibliotecas 
#include <iostream>
#include <vector>
using namespace std;

void mostrarMenu() {
    cout << "======== TRIÁNGULO DE PASCAL =======" << endl;
    cout << "--------------- MENU ---------------" << endl;
    cout << "1. Generar Triángulo de Pascal" << endl;
    cout << "2. Salir" << endl;
}

void imprimirArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

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
