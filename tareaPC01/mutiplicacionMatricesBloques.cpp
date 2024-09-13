#include <iostream>
#include <chrono>
#include <algorithm> // Para la funci�n std::min

using namespace std;

// Funci�n para la multiplicaci�n de matrices en bloques
void multiplicacionMatricesBloque(int n, int blockSize, double** A, double** B, double** C) {
    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            for (int k = 0; k < n; k += blockSize) {
                for (int i1 = i; i1 < min(i + blockSize, n); ++i1) {
                    for (int j1 = j; j1 < min(j + blockSize, n); ++j1) {
                        double sum = 0;
                        for (int k1 = k; k1 < min(k + blockSize, n); ++k1) {
                            sum += A[i1][k1] * B[k1][j1];
                        }
                        C[i1][j1] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    int n = 100;  // Tama�o de la matriz (puedes ajustar este tama�o)
    int blockSize = 10;  // Tama�o del bloque (ajustar seg�n tus necesidades)

    // Creaci�n din�mica de matrices A, B y C
    double** A = new double*[n];
    double** B = new double*[n];
    double** C = new double*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
        B[i] = new double[n];
        C[i] = new double[n];
        // Inicializaci�n de la matriz C a 0
        fill(C[i], C[i] + n, 0);
    }

    // Inicializaci�n de matrices A y B con valores arbitrarios
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = i + j;  // Valores arbitrarios para A
            B[i][j] = i - j;  // Valores arbitrarios para B
        }
    }

    // Medici�n del tiempo de ejecuci�n de la multiplicaci�n de matrices en bloques
    auto start = chrono::high_resolution_clock::now();
    
    // Llamada a la funci�n de multiplicaci�n de matrices en bloques
    multiplicacionMatricesBloque(n, blockSize, A, B, C);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Tiempo de ejecucion de la multiplicacion de matrices en bloques: " << elapsed.count() << " segundos\n";
    
    // Mostrar algunos resultados de la matriz C para verificar
    cout << "C[0][0]: " << C[0][0] << endl;
    cout << "C[" << n-1 << "][" << n-1 << "]: " << C[n-1][n-1] << endl;
    cout << "C[" << n/2 << "][" << n/2 << "]: " << C[n/2][n/2] << endl;

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

