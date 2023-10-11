// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29    


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std; 



void resuelveCaso() {
    int tam = 0; 
    std::cin >> tam; 
    std::vector <string> v(tam, ""); 
    for (string& x : v) {
        std::cin >> x; 
    }
    int min = 0; 
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] < v[min]) min = i; 
    }
    std::cout << v[min] << '\n';
}

int main() {
  
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}