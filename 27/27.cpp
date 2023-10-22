// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int ventana(const std::vector<int>& v, int l) {
    //Inicialización de la ventana: 
    int num_pos_i = 0; //De la parte izquierda
    int num_pos_d = 0; //De la parte derecha
    for (int i = 0; i < l/2; ++i) {
        if (v[i] > 0)++num_pos_i; 
    }
    for (int i = l / 2; i < l; ++i) {
        if (v[i] > 0) ++num_pos_d; 
    }
    
    int cont = 0; 
    if (num_pos_i >= num_pos_d) ++cont; 
    for (int j = 0; j < v.size() - l; ++j) {
        if (v[j] > 0) --num_pos_i; 
        if (v[j + l] > 0) ++num_pos_d; 
    
        if (v[j + l / 2] > 0) {
            --num_pos_d;
            ++num_pos_i; 
        } 
        if (num_pos_i >= num_pos_d) ++cont;
    }
    return cont; 
}

bool resuelveCasos() {
    int tam = 0; 
    std::cin >> tam; 
    if (tam == 0) return false; 
    else {
        int l = 0; 
        std::cin >> l; 
        std::vector<int> v(tam); 
        for (auto& x : v) std::cin >> x; 
        std::cout << ventana(v, l) << '\n'; 
        return true; 
    }
}


int main() {

    while (resuelveCasos());

    return 0;
}