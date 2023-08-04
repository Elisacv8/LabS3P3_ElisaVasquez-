//Bibliotecas 
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
        }
        else if (arr[medio] < numero) {
            inicio = medio + 1;
       