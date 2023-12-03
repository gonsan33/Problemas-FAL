#include <iostream>
#include <vector>
#include <tuple>
using namespace std; 
//Gonzalo Sánchez Montesinos
//DG29

tuple<int, int, bool> f(const std::vector<int>& a, const std::vector<int>& b, int ini, int fin) {
	if (ini == fin) return make_tuple(ini, ini, false);
	else if (ini + 1 == fin && a[ini] == b[ini]) return  make_tuple(ini, ini, true);
	else if (ini + 1 == fin && a[ini] < b[ini]) return make_tuple(ini, ini + 1, false);
	else if (ini + 1 == fin && a[ini] > b[ini]) return make_tuple(ini - 1, ini, false); 
	else {
		int m = (ini + fin - 1) / 2; 
		if (a[m] < b[m]) return f(a, b, m+1, fin);
		else return f(a, b, ini, m+1); 
	} 
}




bool resuelveCasos() {
	int tam; 
	std::cin >> tam; 
	if (tam == 0) return false; 
	else {
		std::vector<int> v1(tam); 
		std::vector<int> v2(tam); 
		for (auto& x : v1) std::cin >> x; 
		for (auto& x : v2) std::cin >> x;
		auto sol = f(v1, v2, 0, v1.size()); 
		if (get<2>(sol)) std::cout << "SI " << get<0>(sol) << '\n'; 
		else std::cout << "NO " << get<0>(sol) <<' ' << get<1>(sol) << '\n';
		return true; 
	}
}



int main() {
	while (resuelveCasos()); 
	return 0;
}