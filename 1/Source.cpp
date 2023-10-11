// Nombre y apellidos del alumno: GONZALO SÁNCHEZ MONTESINOS
// Usuario del juez de clase DG29

#include <iostream>
#include <iomanip>
#include <fstream>


void resuelveCaso() {
    int n;
    std::cin >> n;
    int max = n; 
    int n_veces = 1; 
    std::cin >> n; 
    while (n != 0) {
        if (n > max) {
            max = n;
            n_veces = 1;
        }
        else if (n == max) ++n_veces; 
        std::cin >> n;
    }
    std::cout << max  <<' ' <<  n_veces  << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    std::ofstream out("datos_out.txt"); 
    auto coutbuf = std::cout.rdbuf(out.rdbuf()); 
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf); 
    system("PAUSE");
#endif

    return 0;
}