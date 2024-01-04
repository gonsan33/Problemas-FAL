// Víctor Gómez Torres
// DG10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

using tMatriz = vector<vector<int>>;

bool enemistado(const tMatriz&m, const tMatriz&d,int c,int k) {
    bool ok = false;
    int i = 0;
    while(!ok&&d[i][c]!=-1&&i<3) {
        if (m[k][d[i][c]]==1) {
            ok = true;
        }
        ++i;
    }
    return ok;
}

int canoa(const vector<int>& sol, int k,int canoa) {//Devuelve 1 si la canoa que se va a usar esta vacia
    int s = 1, i = 0;
    while(i<k && s == 1) {
        if (sol[i] == canoa) {
            s = 0;
        }
        ++i;
    }
    return s;
}

// función que resuelve el problema
void resolver(const tMatriz&m,int amigos,int canoas,int k,vector<int>&sol,vector<int>&pesos,vector<int>pesoC,vector<int>&capC,
int pMax,int capMax,bool&hay,int&min,int numc,tMatriz&distrib) {
    for (int i = 0; i < canoas; ++i) {
        sol[k] = i;
        if (pesoC[i] + pesos[k] <= pMax && capC[i] + 1 <= capMax && !enemistado(m,distrib, i,k) && numc + canoa(sol, k, i) <= min) {//Poda
            pesoC[i] += pesos[k];//Marcamos
            distrib[capC[i]][i] = k;
            ++capC[i];//Marcamos
            numc += canoa(sol, k, i);
            if (k + 1 == amigos) {
                if (numc < min) {
                    min = numc;
                    hay = true;
                }
            }
            else resolver(m, amigos, canoas, k + 1, sol, pesos, pesoC, capC, pMax, capMax, hay, min,numc,distrib);
            pesoC[i] -= pesos[k];//Desmarcamos
            --capC[i];//Desmarcamos
            distrib[capC[i]][i] = -1;
            numc -= canoa(sol, k, i);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int amigos, canoas, pMax;
    cin >> amigos >> canoas >> pMax;
    if (amigos > 0) {
        vector<int>pesos(amigos);
        for (int& x : pesos)cin >> x;
        tMatriz m(amigos, vector<int>(amigos));
        for (int i = 0; i < amigos; ++i) {
            for (int j = 0; j < amigos; ++j) {
                cin >> m[i][j];
            }
        }
        bool hay = false;
        int cont = canoas+1;
        vector<int>pesosC(canoas, 0);
        vector<int>capC(canoas, 0);
        vector<int>sol(amigos);
        tMatriz distrib(3, vector<int>(canoas,-1));
        resolver(m, amigos, canoas, 0, sol, pesos, pesosC, capC, pMax, 3, hay, cont, 0,distrib);
        // escribir sol
        if (hay)cout << cont << '\n';
        else cout << "IMPOSIBLE\n";
    }
    else cout << "IMPOSIBLE" << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}