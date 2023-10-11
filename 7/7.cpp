// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector> 
using namespace std; 

// función que resuelve el problema
std::ostream& operator << (std::ostream& op, const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        op << v[i] << ' '; 
    }
    return op; 
}
std::vector<int> resolver(const std::vector<int>& v, int ini, int fin) {
    int max = v[0]; 
    std::vector<int> sol(0); 
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > max) {
            sol.push_back(i + ini);
            max = v[i];
        }
    }
    return sol; 

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int ini = 0, fin = 0;
    std::cin >> ini >> fin; 
    int n = fin - ini + 1 ; 
    std::vector<int> v(n); 
    for (int& x : v) std::cin >> x; 
    std::cout << resolver(v, ini, fin) << '\n'; 

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto



    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto



    return 0;
}