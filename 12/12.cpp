// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std; 

// función que resuelve el problema

//Idea: recorre el vector desde el final contando el número de pares, cuando llega a un par
//las parejas que puede formar con ese par son una por cada impar anterior
//Así, solo se recorre el vector una vez
int resolver(const std::vector<int>& v) {
    int pares = 0; 
    int suma_parejas = 0; 
    for (int i = v.size()-1; i >= 0; --i) { //El bucle se ejecuta v.size() veces. El coste del interior del bucle es constante (2) luego la función está en O(n)
        if (v[i] % 2 == 0) ++pares; 
        else {
            suma_parejas += pares; 
        }
    }
    
    return suma_parejas; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n = 0; 
    std::cin >> n; 
    std::vector<int> v(n); 
    //Lectura: 
    for (int& x : v) std::cin >> x; 

    std::cout << resolver(v) << '\n';


}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    return 0;
}