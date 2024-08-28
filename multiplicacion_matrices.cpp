#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib> 
#include <ctime>   

using namespace std;




// Función para generar una matriz de números aleatorios
vector<vector<int>> generarMatrizAleatoria(int filas, int columnas, int minValor = 10, int maxValor = 20) {

    srand(time(0));
    vector<vector<int>> matriz(filas, vector<int>(columnas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = minValor + rand() % (maxValor - minValor + 1);
        }
    }

    return matriz;
}
// Función para multiplicar dos matrices con la manera clásica
vector<vector<int>> multiplicarMatrices(const vector<vector<int>> A, const vector<vector<int>> B) {

    vector<vector<int>> C;
    int filasA = A.size();
    int columnasA = A[0].size();
    int columnasB = B[0].size();

    // Inicializar la matriz resultante C con ceros
    C = vector<vector<int>>(filasA, vector<int>(columnasB, 0));

    // Multiplicación de matrices con tres bucles anidados
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout<<"Size of matrix C: "<<C.size()<<endl;
    return C;
}


vector<vector<int>> multiplicacionPorBloques(const vector<vector<int>>& A, const vector<vector<int>>& B, int tamañoBloque) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i += tamañoBloque) {
        for (int j = 0; j < n; j += tamañoBloque) {
            for (int k = 0; k < n; k += tamañoBloque) {
                for (int i1 = 0; i1 < tamañoBloque; ++i1) {
                    for (int j1 = 0; j1 < tamañoBloque; ++j1) {
                        for (int k1 = 0; k1 < tamañoBloque; ++k1) {
                            C[i + i1][j + j1] += A[i + i1][k + k1] * B[k + k1][j + j1];
                        }
                    }
                }
            }
        }
    }
    cout<<"Size of matrix for C with 6 loops: "<<C.size()<<endl;
    return C;
}
    

    

int main() {
    vector<vector<int>> A = generarMatrizAleatoria(10,10);
    vector<vector<int>> B = generarMatrizAleatoria(10,10);

    vector<vector<int>> C = generarMatrizAleatoria(100,100);
    vector<vector<int>> D = generarMatrizAleatoria(100,100);

    vector<vector<int>> E = generarMatrizAleatoria(500,500);
    vector<vector<int>> F = generarMatrizAleatoria(500,500);




    //iniciamos los bucles con threads
    std::thread hilo1(multiplicarMatrices,A,B);
    std::thread hilo2(multiplicarMatrices,C,D);
    std::thread hilo3(multiplicarMatrices,E,F);

    //iniciamos la multiplicacion con 6 bucles
    std::thread hilo4(multiplicacionPorBloques,A,B,5);
    std::thread hilo5(multiplicacionPorBloques,C,D,5);
    std::thread hilo6(multiplicacionPorBloques,E,F,5);


    hilo1.join();
    hilo2.join();
    hilo3.join();

    hilo4.join();
    hilo5.join();
    hilo6.join();


    return 0;
}
