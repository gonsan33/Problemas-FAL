#include <iostream>
#include <vector>
using namespace std;

int lower(const std::vector<int>& v, int ini, int fin) {
	//Casos base: 
	if (ini >= fin) return ini;
	else if (ini + 1 == fin) return ini; 
	//Caso recursivo: 
	else {
		int mitad = (ini + fin - 1) / 2; 
		if (v[mitad] <= v[mitad + 1]) return lower(v, ini, mitad + 1);
		else return lower(v, mitad + 1, fin); 
	}
}

int upper(const std::vector<int>& v, int ini, int fin) {
	//Casos base: 
	if (ini >= fin) return ini;
	else if (ini + 1 == fin) return ini; 
	//Caso recursivo: 
	else {
		int mitad = (ini + fin) / 2; 
		if (v[mitad - 1] >= v[mitad]) return upper(v, mitad, fin);
		else return upper(v, ini, mitad); 
	}
}

bool resuelveCasos() {
	int tam = 0; 
	std::cin >> tam; 
	if (tam == -1) return false; 
	else {
		std::vector<int> v(tam); 
		for (int& x : v)std::cin >> x; 
		std::cout << upper(v, 0, v.size()) - lower(v, 0, v.size()) + 1 << '\n'; 
		return true; 
	}
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}