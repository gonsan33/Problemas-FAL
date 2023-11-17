#include <iostream>
#include <vector>
using namespace std;
//Precondición: el valor que falta está entre ini y fin. 
int f(const std::vector<char>& v, int ini, int fin) {
	if (ini >= fin) return  ini;
	else if (ini + 1 == fin) return  ini;
	else {
		int mitad = (ini + fin - 1) / 2; 
		if (v[mitad] + 1 != v[mitad + 1]) return mitad; 
		else if (mitad - ini == v[mitad] - v[ini]) return f(v, mitad + 1, fin);
		else return f(v, ini, mitad + 1); 
	}
}


void resuelveCasos()  {
	char ini, fin; 
	std:cin >> ini >> fin; 
	int n = fin - ini; 
	std::vector<char>v(n); 
	for (char& x : v) std::cin >> x; 
	if (v[0] > ini) std::cout << ini << '\n';
	else if (v[v.size() - 1] < fin) std::cout << fin << '\n'; 
	else 	std::cout << char(v[f(v, 0, v.size())] +1) << '\n'; 


}

int main() {
	int n = 0; 
	std::cin >> n; 
	for (int i = 0; i < n; ++i) resuelveCasos(); 
	return 0; 
}