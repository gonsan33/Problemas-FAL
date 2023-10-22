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
    int max = 0; //La mínima puntuación
    int lastposmax = 0; //La última posición del máximo


    for (int k = 0; k < l; ++k) {
        suma_par += v[k];
        if (v[k] >= max) {
            max = v[k]; 
            lastposmax = k; 
        }
    }
    int suma_max = suma_par;

    for (int j = 0; j < v.size() - l; ++j) {
        //Invariante: max lleva el máximo de la parte recorrida del array: for all k: 0<= k < j+l: v[k] <= max
        //Invariante: poslastmax lleva la última posición del máximo:  for all k: lastposmax < k < j+l: v[k] != max
        //Invariante: suma_par lleva la suma parcial:  suma_par = (sumatorio k: j <= k < j+l: v[k]
        //Invariante: suma_max lleva el máximo de las sumas parciales con un máximo en la ventana:    


        suma_par += v[j + l];
        suma_par -= v[j];

        if (v[j + l] > max) {
            max = v[j + l];
            lastposmax = j + l;
            suma_max = 0; 
        }
        else if (v[j + l] == max) lastposmax = j + l; 

        if (suma_par >= suma_max && lastposmax > j) {
            pag_ini = j + 1;
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

        std::cout << ventana(v, l) << '\n';
        return true;
    }
}

int main() {

    while (resuelveCaso());

    return 0;
}