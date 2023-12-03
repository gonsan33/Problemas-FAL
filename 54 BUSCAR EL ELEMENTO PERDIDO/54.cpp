#include <iostream>
#include <vector>
using namespace std; 

//Gonzalo Sánchez Montesinos
//DG29
int binary(const std::vector<int>& v1, const std::vector<int>& v2, int ini, int fin) {
	if (ini + 1 == fin) return v1[ini]; 
	else {
		int m = (ini + fin - 1) / 2; 
		if (v1[m] < v2[m]) return binary(v1, v2, ini, m + 1);
		else return binary(v1, v2, m + 1, fin); 
	}
}



void resuelveCasos() {
	int tam; 
	std::cin >> tam; 
	std::vector<int> v1(tam); 
	std::vector<int> v2(tam-1); 
	for (auto& x : v1) std::cin >> x; 
	for (auto& x : v2) std::cin >> x;
	std::cout << binary(v1, v2, 0, v1.size()) << '\n'; 
}


int main() {
	int n; 
	std::cin >> n; 
	for (int i = 0; i < n; ++i) resuelveCasos(); 
	return 0; 
}