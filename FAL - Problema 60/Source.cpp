// Víctor Gómez Torres
// DG10

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
int resolver( vector<int>& v, int ini,int fin) {
    if (ini + 1 == fin)return 0;
    else {
        int numInv = 0;
        int mitad = (ini + fin-1) / 2;
        numInv+= resolver(v, ini, mitad+1);
        numInv+= resolver(v, mitad+1, fin);
        int i = ini, j = mitad+1;
        while ((i < mitad+1) && j < fin) {
            if (v[i] > v[j]) {
                numInv += mitad - (i-1);
                ++j;
            }
            else++i;
        }
        inplace_merge(v.begin() + ini, v.begin() + mitad+1, v.begin() + fin);
        return numInv;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int>v(n);
    for (int& x : v)cin >> x;
    int nums=
    resolver(v, 0, v.size());
    // escribir sol
    cout << nums << '\n';
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}