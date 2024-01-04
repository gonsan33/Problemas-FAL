// Víctor Gómez Torres
// DG10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

pair<int, int>maxMin(const vector<int>& v) {
    int max = v[0];
    int min = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > max)max = v[i];
        if (v[i] < min)min = v[i];
    }
    return { max,min };
}



// función que resuelve el problema
void resolver(const vector<int>&v,int s,int n,int k,int sumaAct,const vector<int>&sumas,bool&encontrado) {
    //
        //Caso 1:Sumamos
        sumaAct += v[k];
        if (sumaAct - sumas[k]<=n && sumaAct + sumas[k ] >= n && !encontrado) {//Estimacion cutre
            if (k + 1 == s) {
                if (sumaAct == n) {
                    encontrado = true;
                }

            }
            else resolver(v, s, n, k + 1, sumaAct, sumas, encontrado);
        }
        sumaAct -= v[k];
        //Caso 2:Restamos
        sumaAct -= v[k];
        if (sumaAct - sumas[k ] <= n && sumaAct + sumas[k ] >= n && !encontrado) {//Estimacion cutre
            if (k + 1 == s) {
                if (sumaAct == n)encontrado =true;
            }
            else resolver(v, s, n, k + 1, sumaAct, sumas, encontrado);
        }
        sumaAct += v[k];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> m >> n;
    if (n == 0) {
        if (m == 0)cout << "SI\n";
        else cout << "NO\n";
    }
    else {
        vector<int>v(n);
        for (int& x : v)cin >> x;
        if (n == 1) {
            if (v[0] == m)cout << "SI\n";
            else cout << "NO\n";
        }
        else {
            pair<int, int>p = maxMin(v);
            bool encontrado = false;
            vector<int>sumas(n);
            sumas[sumas.size() - 1] = v[v.size() - 1];
            for (int i = sumas.size() - 2; i >= 0; --i) {
                sumas[i] = sumas[i + 1] + v[i];
            }
            resolver(v, n, m, 1, v[0], sumas, encontrado);
            // escribir sol
            if (encontrado)cout << "SI\n";
            else cout << "NO\n";
        }

    }

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