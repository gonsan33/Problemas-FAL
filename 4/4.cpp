// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std; 

// función que resuelve el problema
bool resolver(std::vector<int> & v,  int pos) {
    int max = v[0]; 
    for (int i = 1; i <= pos; ++i) {
        if (max < v[i]) max = v[i];
    }
    int j = pos + 1; 
    while (j < v.size() && v[j] > max) ++j; 
    return j == v.size(); 

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam = 0, pos = 0; 
    std::cin >> tam >> pos; 
    std::vector<int> v(tam); 
    for (int& x : v) {
        std::cin >> x;
    }

    bool sol = resolver(v, pos);
    switch (sol) {
    case true: std::cout << "SI\n"; break; 
    case false: std::cout << "NO\n"; break; 
    }

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto



    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    return 0;
}