// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std; 


int binarySearchlowerbound(const std::vector<int>& v, int elem, int ini, int fin) {
    if (ini >= fin) return ini; //Vector vacío
    else if (ini + 1 == fin) return ini; //vector de un elemento
    else {
        int mitad = (ini + fin - 1) / 2; //El de la izquierda
        if (v[mitad] < elem) return binarySearchlowerbound(v, elem, mitad + 1, fin);
        else return binarySearchlowerbound(v, elem, ini, mitad + 1);  //para que incluya la mitad
    }
}

int binarySearchupperbound(const std::vector<int>& v, int elem, int ini, int fin) {
    if (ini >= fin) return ini; //Vector vacío
    else if (ini + 1 == fin) return ini; //vector de un elemento
    else {
        int mitad = (ini + fin ) / 2; //El de la izquierda
        if ( elem < v[mitad]) return binarySearchupperbound(v, elem, ini, mitad);
        else return binarySearchupperbound(v, elem, mitad, fin );  //para que incluya la mitad
    }
}



bool resuelveCaso() {
    int tam = 0;
    std::cin >> tam; 
    if (!std::cin)return false;
    else {
        int h = 0; 
        std::cin >> h; 
        std::vector<int> v(tam); 
        for (auto& x : v) std::cin >> x; 
        int lb = binarySearchlowerbound(v, h, 0, v.size()); 
        int ub = binarySearchupperbound(v, h, 0, v.size()); 
        if (lb == ub && v[lb] == h) std::cout << lb << '\n';
        else if (v[lb] == h) std::cout << lb << ' ' << ub << '\n';
        else std::cout << "NO EXISTE\n"; 
        return true;
    }
}

int main() {




    while (resuelveCaso());



    return 0;
}