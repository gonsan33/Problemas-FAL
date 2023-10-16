// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std; 

std::istream& operator >> (std::istream& op, std::vector<int>& v) {
    int i = 0; 
    op >> i; 
    int cont = 0; 
    while (i != 0) {
        v[cont] = i; 
        ++cont;
        op >> i; 
    }
    v.resize(cont); 
    return op;
}

std::ostream& operator << (std::ostream& op, std::vector<int>& v) {
    if (v.size() > 0) {
        op << v[0];
        for (int i = 1; i < v.size(); ++i) {
            op << " " << v[i];
        }
    }
    return op; 
}


//Diferencia simétrica
void resolver(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& sol) { 
    int i = 0, j = 0, cont = 0; 
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            ++i; 
            ++j; 
        }
        else if (a[i] < b[j]) {
            sol[cont] = a[i]; 
            ++cont; 
            ++i; 
        }
        else {
            sol[cont] = b[j];
            ++cont;
            ++j;
        }

    }
    for (int k = i; k < a.size(); ++k) {
        sol[cont] = a[k]; 
        ++cont; 
    }
    for (int k = j; k < b.size(); ++k) {
        sol[cont] = b[k]; 
        ++cont; 
    }
    sol.resize(cont); 
}


void resuelveCasos() {
    std::vector<int> a(100000); 
    std::vector<int> b(100000);
    std::cin >> a >> b ; 
    std::vector<int> sol(a.size() + b.size()); 
    resolver(a, b, sol); 
    std::cout << sol << '\n'; 
}

int main() {
    int number_of_cases = 0; 
    std::cin >> number_of_cases; 
    for (int i = 0; i < number_of_cases; ++i) resuelveCasos();     
    return 0;
}
