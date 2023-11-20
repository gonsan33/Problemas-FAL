#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std; 

tuple<int, bool,int> contar(const std::vector<string>& v, int ini, int fin, int r) {
	if (ini + 2 == fin) {
		if (v[ini] == "NP" && v[ini + 1] == "NP") return make_tuple( 0,false,1 );
		else if(v[ini] == "NP" || v[ini + 1] == "NP")return make_tuple(0, true, 1);
		else return make_tuple(1, true, 1);
	}
	else {
		int mitad = (ini + fin - 1) / 2; 
		auto a = contar(v, ini, mitad + 1,r); 
		auto b = contar(v, mitad + 1, fin,r); 
		int c = 0; 
		if(get<2>(a) >= r) return make_tuple(get<0>(a) + get<0>(b) , get<1>(a) || get<1>(b), get<2>(a) + 1);
		else {
			if (get<1>(a) && get<1>(b)) ++c;
			return make_tuple(get<0>(a) + get<0>(b) + c, get<1>(a) || get<1>(b), get<2>(a) + 1);
		}
		
	}
}

bool resuelveCasos() {
	int n, r; 
	std::cin >> n; 
	if (!cin) return false; 
	std::cin >> r; 
	vector<string>v(n); 
	for (string& x : v) std::cin >> x; 
	std::cout << get<0>(contar(v, 0, v.size(),r)) << '\n';
	return true; 
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}