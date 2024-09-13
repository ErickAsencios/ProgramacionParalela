#include <iostream>
#include <chrono>
using namespace std;

// Funci�n para la multiplicaci�n cl�sica de matrices
void multiplicacionMatricesClasica(int n, double** A, double** B, double** C) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;  // Inicializar el elemento C[i][j] a 0
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];  // Producto de matrices
            }
        }
    }
}

int main() {
    int n = 1000;  // Tama�o de la matriz (puedes cambiarlo seg�n tus necesidades)

    // Creaci�n din�mica de matrices A, B y C
    double** A = new double*[n];
    double** B = new double*[n];
    double** C = new double*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
        B[i] = new double[n];
        C[i] = new double[n];
    }

    // Inicializaci�n de matrices A y B con valores arbitrarios
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = i + j;  // Valores arbitrarios para A
            B[i][j] = i - j;  // Valores arbitrarios para B
        }
    }

    // Medici�n del tiempo de ejecuci�n de la multiplicaci�n de matrices
    auto start = chrono::high_resolution_clock::now();
    
    // Llamada a la funci�n de multiplicaci�n de matrices
    multiplicacionMatricesClasica(n, A, B, C);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Tiempo de ejecuci�n de la multiplicaci�n de matrices: " << elapsed.count() << " segundos\n";
    
    // Mostrar algunos resultados de la matriz C para verificar
    cout << "C[0][0]: " << C[0][0] << endl;
    cout << "C[" << n-1 << "][" << n-1 << "]: " << C[n-1][n-1] << endl;

    // Liberar la memoria de las matrices
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}

