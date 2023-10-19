// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


std::ostream& operator << (std::ostream& op, const std::vector<int> v) {
    op << v[0];
    for (int i = 1; i < v.size(); ++i) op << " " << v[i];
    return op;
}

//Funci�n apariciones(v, valor, tope) = (#k: 0<= k < i : v[k] = valor)
int moda(std::vector<int>& v) {
    std::sort(v.begin(), v.end()); 
    int moda = 0; //Almacena la posición de la moda
    int fm = 1; //Almacena la frecuencia máxima
    int f = 1; //Almacena la frecuencia relativa
    for (int i = 1; i < v.size(); ++i) {
        //Invariante: forall i: 1 <= i < v.size : f = apariciones(v,v[i-1], i) 
        //Invariante: fm = máx k: 0<= k < i: apariciones(v, v[k], i)
        //Invariante: 0<= moda < i && apariciones(v, v[moda], i) = fm
        if (v[i - 1] == v[i]) {
            ++f; 
            if (f > fm) {
                moda = i; 
                fm = f; 
            }
        }
        else {
            f = 1; 
        }
    }
    return v[moda]; 
}


bool resuelveCaso() {
    int tiradas = 0;
    std::cin >> tiradas;

    if (tiradas == -1) return false;
    else {
        std::vector<int> v(tiradas);
        for (auto& x : v)std::cin >> x;

        std::cout << moda(v) << '\n';
        return true;
    }
}

int main() {

    while (resuelveCaso());

    return 0;
}