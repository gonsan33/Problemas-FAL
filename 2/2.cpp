// Problema: Ultima vez que..

// IMPORTANTE.
// Nombre del alumno: GONZALO SÁNCHEZ MONTESINOS
// Usuario del juez: DG29


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std; 
// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(std::vector<std::string> const& v, const std::string& country) {
    
    int i = v.size() - 1; 
    while (i >= 0 && v[i] != country) --i; 

    if (i == -1) return -1;
    else return v.size() - i; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    std::cin >> num;
    if (num == 0) return false;
    std::string country; 
    cin >> country; 
    std::vector<std::string> v (num, "") ; //Declararión del vector a un tamaño dado e inicialización de los strings a vacío
    for (int i = 0; i < num; ++i) {
        cin >> v[i]; 
    }
    int res = resolver(v, country); 
    
    res == -1 ? std::cout << "NUNCA\n" : std::cout << res << '\n'; 
    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}