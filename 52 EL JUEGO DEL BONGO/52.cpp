#include <iostream>
#include <vector>
using namespace std; 

//Gonzalo Sánchez Montesinos
//DG29

pair<int,bool> f(const std::vector<int>& v, int n, int ini, int fin) {
	if (ini >= fin) return { ini, false };
	else if (ini + 1 == fin) return { ini, n + ini == v[ini] }; 
	else {
		int mitad = (ini + fin - 1) / 2; 
		if (mitad + n <= v[mitad]) return f(v, n, ini, mitad + 1);
		else return f(v, n, mitad + 1, fin); 
	}
}


void resuelveCasos() {
	int tam, n; 
	std::cin >> tam >> n; 
	std::vector<int> v(tam); 
	for (int& x : v) std::cin >> x; 
	auto sol = f(v, n, 0, v.size()); 
	if (!sol.second) std::cout << "NO\n";
	else std::cout << v[sol.first] << '\n'; 
}


int main() {
	int n; std::cin >> n; for (int i = 0; i < n; ++i) resuelveCasos(); 
	return 0; 
}