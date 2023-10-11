// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std; 

// función que resuelve el problema
bool resolver(std::vector<int>&v, int d) {
    int i = 0;
    bool encontrado = true; 
    int primero = 0, last = 0; 
    while (i < v.size() && encontrado) {
         
        //Cálculo de last
        while (i < v.size() - 1 && v[i] < v[i + 1]) ++i; 
        last = i; 
        encontrado = v[last] - v[primero] <= d; 
        primero = i+ 1; 
        ++i; 
    }
    return encontrado; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int d = 0; 
    std::cin >> d; 
    if (!cin) return false; 
    else {
        int tam = 0; 
        std::cin >> tam; 
        std::vector <int> v(tam); 
        for (int i = 0; i < v.size(); ++i) {
            std::cin >> v[i];
        }
        
        if (resolver(v, d)) std::cout << "APTA\n";
        else std::cout << "NO APTA\n";
        // escribir sol

        return true; 
    }

    


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

*/


    while (resuelveCaso()); 

/*
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

*/

    return 0;
}