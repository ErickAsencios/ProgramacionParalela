#include <iostream>
#include <chrono>
#include <algorithm> // Para la función std::min

using namespace std;

// Función para la multiplicación de matrices en bloques
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
    int n = 100;  // Tamaño de la matriz (puedes ajustar este tamaño)
    int blockSize = 10;  // Tamaño del bloque (ajustar según tus necesidades)

    // Creación dinámica de matrices A, B y C
    double** A = new double*[n];
    double** B = new double*[n];
    double** C = new double*[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
        B[i] = new double[n];
        C[i] = new double[n];
        // Inicialización de la matriz C a 0
        fill(C[i], C[i] + n, 0);
    }

    // Inicialización de matrices A y B con valores arbitrarios
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = i + j;  // Valores arbitrarios para A
            B[i][j] = i - j;  // Valores arbitrarios para B
        }
    }

    // Medición del tiempo de ejecución de la multiplicación de matrices en bloques
    auto start = chrono::high_resolution_clock::now();
    
    // Llamada a la función de multiplicación de matrices en bloques
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

