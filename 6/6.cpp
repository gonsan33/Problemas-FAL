// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std; 
std::ostream& operator << (std::ostream& op, const std::pair<long long int, int>& a) {
    op << a.first << " " << a.second; 
    return op; 
}

std::pair<long long int,int> resolver(const std::vector<int>& v) {
    int min = v[0]; 
    int multiplicidad = 1; 
    long long int media = 0; 
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] < min) {
            media = media + min * multiplicidad;
            min = v[i];
            multiplicidad = 1;
        }
        else if (v[i] == min) ++multiplicidad;
        else media += v[i]; 
    }

    return { media, v.size() - multiplicidad }; 

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    std::cin >> n; 
    std::vector<int> v(n); 
    for (auto& x : v) std::cin >> x; 


    std::cout << resolver(v) << '\n';

    // escribir sol


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