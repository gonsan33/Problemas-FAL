#include <iostream>
#include <string>
#include <vector>
using namespace std; 

struct tEdif {
	std::string id;
	int altura;
	int alt_piso;
}; 

bool operator > (const tEdif& a, const tEdif& b) {
	return a.alt_piso > b.altura; 
}

std::istream& operator >> (std::istream& op, tEdif& a) {
	op >> a.id >> a.altura >> a.alt_piso; 
	return op; 
}

std::istream& operator >> (std::istream& op, std::vector<tEdif>& v) {
	for (auto& x : v) op >> x; 
	return op;
}
std::ostream& operator << (std::ostream& op, const std::vector<string>& v) {
	if (v.size() > 0) {
		op << v.size() << '\n';
		op << v[0];
		for (int i = 1; i < v.size(); ++i) {
			op << " " << v[i];
		}
		op << '\n';
	}
	else op << "Ninguno\n"; 
	
	return op;
}

std::vector<string> resolver (const std::vector<tEdif>& v) {
	std::vector<string> sol(v.size(), ""); 
	int cont = 0; 
	int pos_max = v.size() - 1; 
	if (v[pos_max].alt_piso >= 0) {
		sol[0] = v[pos_max].id;
		++cont; 
	}

	for (int i = v.size() - 2; i >= 0; --i) { //Se recorre v.size() -1 veces y el interior tiene coste constante
		if (v[i] > v[pos_max] && v[i].alt_piso >= 0) { //V[i] tiene vistas 
			pos_max = i;
			sol[cont] = v[i].id;
			++cont;
		}
		else if (v[i].altura > v[pos_max].altura) pos_max = i; 
	}
	sol.resize(cont); 
	return sol; 
}

bool resuelveCasos() {
	int n = 0; 
	std::cin >> n;
	if (n == 0) return false; 
	else {
		std::vector<tEdif> v(n);
		std::cin >> v;
		std::vector<string> sol = resolver(v);
		std::cout << sol;
		return true; 
	}
	
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}