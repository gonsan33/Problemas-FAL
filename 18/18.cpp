// Nombre del alumno GONZALO S�NCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

std::istream& operator >> (std::istream& op, std::vector<int>& v) {
    for (auto& x : v) op >> x;
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


//Diferencia sim�trica
void resolver(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& sol) {
    int i = 0, j = 0, cont = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            sol[cont] = a[i];
            ++i;
            ++cont; 
            sol[cont] = b[j]; 
            ++j;
            ++cont;
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
    while (i < a.size()) {
        sol[cont] = a[i];
        ++i;
        ++cont;
    }
    while (j < b.size()) {
        sol[cont] = b[j];
        ++j;
        ++cont;
    }

    sol.resize(cont);
}


void resuelveCasos() {
    int tam1 = 0, tam2 = 0;
    std::cin >> tam1 >> tam2;

    std::vector<int> a(tam1);
    std::vector<int> b(tam2);
    std::cin >> a >> b;
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