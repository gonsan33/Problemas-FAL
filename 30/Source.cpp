// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std; 


// función que resuelve el problema
int resolver(const std::vector<int> & v) {
    //Cuando se aumenta en uno la longitud del segmento, basta ver si el último subsegmento de 3 cumple la propiedad 
    //Inicialización
    int longMax = 2; 
    int longActual = 2; 

    for (int i = 2; i < v.size(); ++i) { //Coste del algoritmo: lineal en el número de elementos del vector porque en el bucle se recorre el vector una única vez. Además, cada vuelta del bucle tiene coste constante
        
        if (!(v[i - 2] < v[i - 1] && v[i - 1] < v[i])) { //Coste constante
            ++longActual;
            if (longActual > longMax) longMax = longActual; 
        } 
        else longActual = 2;  //Coste constante
       
    }
    return longMax; 
}


void resuelveCaso() {
    int n; 
    std::cin >> n; 
    std::vector<int> v(n); 
    for (int& x : v) std::cin >> x; 
    if (v.size() < 3) std::cout << v.size() << '\n'; 
    else std::cout << resolver(v) << '\n'; 
}

int main() {
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    return 0;
}