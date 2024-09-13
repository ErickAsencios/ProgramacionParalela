#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

const int MAX = 1000;  // Cambia este valor según tus pruebas

int main() {
    vector<vector<double>> A(MAX, vector<double>(MAX));
    vector<double> x(MAX), y(MAX, 0);  // Inicialización de y = 0

    // Inicialización de A y x
    for (int i = 0; i < MAX; ++i) {
        x[i] = i;
        for (int j = 0; j < MAX; ++j) {
            A[i][j] = i + j;  // Valores arbitrarios
        }
    }

    // Primer par de bucles: patrón "row-major"
    auto start1 = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            y[i] += A[i][j] * x[j];
        }
    }
    
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed1 = end1 - start1;
    cout << "Tiempo de ejecucion del primer par de bucles (row-major): " << elapsed1.count() << " segundos\n";

    // Reinicialización de y = 0
    fill(y.begin(), y.end(), 0);

    // Segundo par de bucles: acceso no contiguo
    auto start2 = chrono::high_resolution_clock::now();
    
    for (int j = 0; j < MAX; ++j) {
        for (int i = 0; i < MAX; ++i) {
            y[i] += A[i][j] * x[j];
        }
    }
    
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = end2 - start2;
    cout << "Tiempo de ejecucion del segundo par de bucles (no contiguo): " << elapsed2.count() << " segundos\n";

    return 0;
}




