// Víctor Gómez Torres
// DG10

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

using namespace std;

using tMatriz = vector<vector<int>>;

struct tSol {
    int jug1;
    int jug2;
};

bool satisfacciones(const vector<int>& v,int min) {
    bool ok = true;
    int i = 0;
    while (i < v.size() && ok) {
        if (v[i] < min)ok = false;
        ++i;
    }
    return ok;
}

void escribirSol(const vector<tSol>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].jug1 << " " << v[i].jug2 << " ";
    }
    cout << '\n';
}


// función que resuelve el problema
void resolver(const tMatriz&m,vector<tSol>&sol,int njug,int ninis, int k, const vector<string>&tipos
,vector<int>&cantidades,vector<int>&sats,int satMin,bool&hay) {
    for (int i = 0; i < njug; ++i) {
        sol[k].jug1 = i;
        for (int j = i + 1; j < njug; ++j) {
            sol[k].jug2 = j;
            if (tipos[i] != tipos[j] && cantidades[i] > 0 && cantidades[j] > 0) {
                sats[k] += m[k][i];
                sats[k] += m[k][j];
                --cantidades[i];
                --cantidades[j];
                if (k == ninis - 1) {
                    if (satisfacciones(sats, satMin)) {
                        escribirSol(sol);
                        hay = true;
                    }
                }
                else resolver(m, sol, njug, ninis, k + 1, tipos, cantidades, sats,satMin, hay);
                sats[k] -= m[k][i];
                sats[k] -= m[k][j];
                ++cantidades[i];
                ++cantidades[j];
            }
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nj;
    cin >> nj;
    if (!std::cin)
        return false;
    int ninis; int satMin;
    cin >> ninis >> satMin;
    vector<int>cantidades(nj);
    for (int& x : cantidades)cin >> x;
    vector<string>tipos(nj);
    for (string& s : tipos)cin >> s;
    tMatriz m(ninis, vector<int>(nj));
    for (int i = 0; i < ninis; ++i) {
        for (int j = 0; j < nj; ++j) {
            cin >> m[i][j];
        }
    }
    bool hay = false;
    vector<tSol>sol(ninis);
    vector<int>sats(ninis,0);
    resolver(m, sol, nj, ninis, 0, tipos, cantidades, sats, satMin, hay);
    cout << '\n';
    // escribir sol
    if (!hay)cout << "SIN SOLUCION\n\n";
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