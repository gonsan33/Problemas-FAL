// Nombre del alumno GONZALO S�NCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int binarySearchlowerbound(const std::vector<int>& v, int elem, int ini, int fin) {
    if (ini >= fin) return ini; //Vector vac�o
    else if (ini + 1 == fin) return ini; //vector de un elemento
    else {
        int mitad = (ini + fin - 1) / 2; //El de la izquierda
        if (v[mitad] < v[0]) {
            if (v[mitad] < elem && elem < v[0]) return binarySearchlowerbound(v, elem, mitad + 1, fin);
            else if (elem > v[mitad] && elem >= v[0]) return binarySearchlowerbound(v, elem, ini, mitad + 1);
            else return binarySearchlowerbound(v, elem, ini, mitad + 1); 
        }
        else { //v[m] > v[v.size()-1]
            if (v[mitad] < elem) return binarySearchlowerbound(v, elem, mitad + 1, fin);
            else if (elem >= v[0]) return binarySearchlowerbound(v, elem, ini, mitad + 1);
            else return binarySearchlowerbound(v, elem, mitad + 1, fin); 
        }



    }
}




bool resuelveCasos() {
    int tam = 0; 
    std::cin >> tam; 
    if (tam == -1) return false; 
    else {
        int valor; 
        std::cin >> valor; 
        vector<int> v(tam); 
        for (int& x : v)std::cin >> x; 
        if (v[binarySearchlowerbound(v, valor, 0, v.size())] == valor) std::cout << "SI\n";
        else std::cout << "NO\n"; 
        return true; 
    }
}


int main() {
    while (resuelveCasos()); 
    return 0; 
}