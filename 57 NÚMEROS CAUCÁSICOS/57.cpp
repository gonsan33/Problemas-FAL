#include <vector>
#include <iostream>
using namespace std;
 
std::pair<bool, int> caucasico(const std::vector<int>& v, int ini, int fin) {
	if (ini + 1 == fin) return { true, 1-v[ini]%2 }; 
	else {
		int mitad = (ini + fin - 1) / 2; 
		auto a = caucasico(v, ini, mitad + 1); 
		pair<bool, int> b= { true, 0 }; 
		if (a.first) {//poda
			b = caucasico(v, mitad + 1, fin); 
		}
		return { a.first && b.first && abs(a.second - b.second) <= 2, a.second + b.second };
	}
}


bool resuelveCasos() {
	int n; 
	std::cin >> n; 
	if (n == 0) return false; 
	else {
		std::vector<int>v(n); 
		for (int i = 0; i < n; ++i) std::cin >> v[i]; 
		if (caucasico(v, 0, v.size()).first) std::cout << "SI\n";
		else std::cout << "NO\n"; 
		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}