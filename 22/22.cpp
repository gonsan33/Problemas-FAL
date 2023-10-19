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

bool compare(int i, int j) { return i > j;  }
//Función apariciones(v, valor, tope) = (#k: 0<= k < i : v[k] = valor)
void moda(const std::vector<int>& v, std::vector<int>& res, std::vector<int>& moda) {
    int max = 0; //Almacena el máximo número de veces que aparece repetido un elemento 
    for (int i = 0; i < v.size(); ++i) {
        //Invariante: forall k: 0 <= k < i : res[v[k]] = apariciones(v,v[k], i) 
        //Invariante: max = máx k: 0<= k < i: apariciones(v, v[k], i)
        //Invariante: forall j: 0<= j < moda.size():  ((existe k: 0<= k < i: v[k] = moda[j]) && apariciones(v, moda[j], i)) = max
        
        ++res[v[i]]; 
        if (max < res[v[i]]) {
            moda.resize(0); 
            moda.push_back(v[i]); 
            max = res[v[i]]; 
        }
        else if (max == res[v[i]]) {
            moda.push_back(v[i]); 
        }
    }
    std::sort(moda.begin(), moda.end(), compare ); 
}


bool resuelveCaso() {
    int tiradas = 0, max = 0; 
    std::cin >> tiradas; 

    if (tiradas == -1) return false;
    else {
        std::cin >> max; 
        std::vector<int> v(tiradas); 
        for (auto& x : v)std::cin >> x; 
        std::vector<int> res(max + 1, 0); 
        std::vector<int> modav(0); 
        moda(v, res, modav); 
        std::cout <<  modav << '\n';
        return true;
    }
}

int main() {

    while (resuelveCaso());

    return 0;
}