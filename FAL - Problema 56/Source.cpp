// Víctor Gómez Torres
// DG10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int paradas(const vector<int>& v, int tramo) {
    int paradas = 0;
    int pAct = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (pAct + v[i] > tramo) {
            ++paradas;
            pAct = v[i];
        }
        else pAct += v[i];
    }
    return paradas;
}

// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin, int stops) {
    if (ini == fin)return ini;
    else {
        int mitad = (ini + fin - 1) / 2;
        if (paradas(v, mitad) <= stops) return resolver(v, ini, mitad, stops);
        else return resolver(v, mitad + 1, fin, stops);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int c = 0, t = 0;
    cin >> c >> t;
    if (c == 0 && t == 0)
        return false;
    vector<int>v(c);
    int sum = 0;
    int max = 0;
    for (int i = 0; i < c; ++i) {
        cin >> v[i];
        sum += v[i];
        if (max < v[i])max = v[i];
    }
    int sol = resolver(v, max, sum, t);
    // escribir sol
    cout << sol << '\n';
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
