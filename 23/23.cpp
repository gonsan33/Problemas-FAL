// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


std::ostream& operator << (std::ostream& op, const std::pair<int,int> x) {
    op << x.first << " " << x.second; 
    return op;
}

std::pair<int, int> resolver(const std::vector<int>& v, int tte) {
    int ini = 0, fin = 0; 
    int ini_max = 0, fin_max = 0; 

    while (fin < v.size()) { //Coste: lineal en el número de elementos del vector. En el caso peor, se avanza de uno en uno
        //Invariante: ini <= fin
        //Invariante forall k: ini <= k < fin: v[k] > tte
        //Invariante: forall k: ini_max <= k < fin_max: v[k] > tte
        //Invariante fin - ini <= fin_max - ini_max 
        if (v[fin] > tte) {
            ++fin; 
            if (fin - ini > fin_max - ini_max) {
                fin_max =fin;
                ini_max = ini;
            }
        }
        else {
            ini = ++fin;
        }
    }
    return { ini_max, --fin_max }; 
}


void resuelveCasos() {
    int edificios = 0, tte = 0;
    std::cin >> edificios >> tte; 
    std::vector<int> v(edificios); 
    for (auto& x : v) std::cin >> x; 
    std::cout << resolver(v, tte) << '\n'; 

   
}

int main() {

    int n = 0; 
    std::cin >> n; 
    for (int i = 0; i < n; ++i) resuelveCasos(); 
    return 0;
}