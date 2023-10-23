//GONZALO SÁNCHEZ MONTESINOS
//DG29

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

struct tPasajero {
	std::string nombre; 
	int altura; 
};

std::istream& operator >> (std::istream& op,  tPasajero& p) {
	op >> p.nombre >> p.altura; 
	return op; 
}
bool operator < (const tPasajero& a, const tPasajero& b) { return a.nombre < b.nombre;  }
bool operator <= (const tPasajero& a, const tPasajero& b) { return a.nombre <= b.nombre; }
bool operator > (const tPasajero& a, const tPasajero& b) { return a.nombre > b.nombre; }
bool operator < (const tPasajero& a, int b) { return a.altura < b; }
bool operator <= (const tPasajero& a, int b) { return a.altura <= b; }
bool operator > (const tPasajero& a, int b) { return a.altura > b; }
bool operator >= (const tPasajero& a, int b) { return a.altura >= b; }
bool compare(const tPasajero& a, const tPasajero& b) { return a < b;  }

void resolver(std::vector<tPasajero>& v, int altura) {
	int i = 0; 
	int j = v.size()-1; 
	while (i <= j) {
		if (v[i] > altura && v[j] <= altura) {
			tPasajero aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
		else if (v[i] <= altura) ++i;
		else if (v[j] >= altura) --j; 
	}
	std::vector<tPasajero> v1(j+1); 
	for (int k = 0; k < v1.size(); ++k) {
		v1[k] = v[k];
	}
	std::vector<tPasajero> v2(v.size()- v1.size());
	for (int k = 0; k < v2.size(); ++k) { 
		v2[k] = v[k + j + 1];
	}
	std::sort(v1.begin(), v1.end()); 
	std::sort(v2.begin(), v2.end()); 

	std::cout << "Bajos:"; 
	for (int k = 0; k < v1.size(); ++k) std::cout << " " << v1[k].nombre; 
	std::cout << '\n'; 
	std::cout << "Altos:";
	for (int k = 0; k < v2.size(); ++k) std::cout << " " << v2[k].nombre;
	std::cout << '\n'; 
}


bool resuelveCasos() {
	int n, altura; 
	std::cin >> n; 
	if (!cin) return false; 
	else {
		cin >> altura; 
		std::vector<tPasajero> v(n); 
		for (auto& x : v) std::cin >> x; 
		resolver(v, altura); 
		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}