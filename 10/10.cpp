#include <iostream>
#include <string>
#include <vector>
using namespace std; 

void resuelveCasos() {
	int n; 
	std::cin >> n; 
	std::vector <int> v(n); 
	for (auto& x : v)std::cin >> x; 
	int p = v.size() - 1;
	int ceros = 0; 
	int unos = 0; 
	if (v[p] == 0) ++ceros; 
	else if (v[p] == 1) ++unos; 
	for (int i = v.size() - 2; i >= 0; --i) {
		if (ceros == unos) p = i; 
		if (p == 0) ++ceros;
		else if (p == 1) ++unos; 
	}
	std::cout << p << '\n'; 

}

int main() {
	int n = 0; 
	std::cin >> n; 
	for (int i = 0; i < n; ++i) resuelveCasos(); 
	return 0; 
}