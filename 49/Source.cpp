//Gonzalo Sánchez Montesinos 
//DG29

#include <vector>
#include <iostream>
using namespace std; 

int min(const vector<int>& v, int ini, int fin) {
	if (ini + 1 == fin) return v[ini];
	else if (ini + 2 == fin) return min(v[ini], v[ini + 1]); 
	else {//tres elementos
		int mitad = (ini + fin - 1) / 2; 
		if (v[mitad - 1] > v[mitad] && v[mitad] < v[mitad + 1]) return v[mitad];
		else if (v[mitad - 1] < v[mitad]) return min(v, ini, mitad);
		else return min(v, mitad + 1, fin); 
	}
}

bool resuelveCasos() {
	int n; 
	std::cin >> n; 
	if (!cin) return false; 
	std::vector<int> v(n);
	for (auto& x : v)std::cin >> x; 
	std::cout << min(v,0,v.size()) << '\n';
	return true; 
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}
