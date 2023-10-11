// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std; 
// función que resuelve el problema
bool resolver(const std::vector<int>& v, int& sol) {
    int suma = 0; 
    sol = -1;
    int i = v.size()- 1; 

    while (i >= 0 && v[i] != suma) { //En el caso peor, el bucle se recorre n veces. Comprobar la condición del bucle tiene coste 2 a lo sumo y el interior del bucle tiene coste 2 en cada iteración. Luego el coste es lineal (4n a lo sumo)
        suma += v[i]; 
        --i; 
    }
    sol = i; 
    
    
    return sol != -1; 
    //Como el orden de la suma de funciones es el orden del máximo y tanto la lectura como el bucle while son lineales, el coste es lineal

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n = 0; 
    std::cin >> n; 
    std::vector<int> v(n); 
    for (auto& x : v) { //Lectura: coste lineal
        std::cin >> x; 
    }
    int sol = 0; 
    if (resolver(v, sol)) {
        std::cout << "Si " << sol << '\n';
    }
    else std::cout << "No\n"; 
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