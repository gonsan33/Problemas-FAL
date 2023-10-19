// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int ventana(const std::vector<int>& v, int l) {
    int suma_par = 0; 
    int pag_ini = 0; 
    for (int k = 0; k < l; ++k) {
        suma_par += v[k]; 
    }
    int suma_max = suma_par;
    for(int j = 0; j < v.size() - l; ++j) {

        suma_par += v[j + l]; 
        suma_par -= v[j]; 
        if (suma_par >= suma_max) {
            pag_ini =  j+1; 
            suma_max = suma_par; 
        }


    }
    return pag_ini; 


}


bool resuelveCaso() {
    int n, l = 0;
    std::cin >> n >> l;

    if (l == 0 && n == 0) return false;
    else {
        std::vector<int> v(n);
        for (auto& x : v)std::cin >> x;

        std::cout <<ventana(v, l) << '\n';
        return true;
    }
}

int main() {

    while (resuelveCaso());

    return 0;
}