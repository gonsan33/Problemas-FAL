#include <iostream>
#include <string>
#include <vector>
using namespace std;

int resolver(std::vector<int> v) {
	int ceros = 0; 
	int unos = 0; 
	int pos_max = -1; 
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 0) ++ceros;
		else if (v[i] == 1) ++unos; 
		if (ceros == unos) pos_max = i; 
	}
	return pos_max; 
}

void resuelveCasos() {
	int tam = 0; 
	std::cin >> tam; 
	std::vector<int> v(tam); 
	for (auto& x : v) std::cin >> x; 
	std::cout << resolver(v) << '\n'; 
}

int main() {
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCasos();
	return 0;
}