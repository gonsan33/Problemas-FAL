#include <iostream>
#include <string>
#include <vector>
using namespace std; 

//Gonzalo Sánchez Montesinos 

//DG29



struct tDato {
	int elem; 
	int apariciones; 
	tDato(int elem, int apariciones) {
		this->elem = elem; 
		this->apariciones = apariciones; 
	}
	tDato() {
		this->elem = -1; 
		this->apariciones = -1; 
	}
};

pair<tDato,bool> resolver(const std::vector<int>& v, int ini, int fin) { 
	if (ini == fin) return { tDato(), false }; 
	else if (ini + 1 == fin) return { tDato(v[ini],1) ,true };
	else {
		int m = (ini + fin - 1) / 2; 
		auto a = resolver(v, ini, m + 1); 
		auto b = resolver(v, m + 1, fin); 
		if (!a.second && !b.second) return a; //Devuelvo falso



		//Ya sabemos cuáles son los elementos que tienen posibilidades de aparecer más de n/2 veces. 
		//ahora, se recorren las otras mitades para contar las apariciones de cada elemento
		if (b.second) {
			for (int i = ini; i < m + 1; ++i) {
				if (v[i] == b.first.elem) ++b.first.apariciones;
			}
		}
		if (a.second) {
			for (int i = m + 1; i < fin; ++i) {
				if (v[i] == a.first.elem) ++a.first.apariciones;
			}
		}
		
		
		//Por lo tanto, basta devolver el que más apariciones tenga
		if (a.first.apariciones >= b.first.apariciones) return { a.first, a.first.apariciones > (fin - ini) / 2 }; //Si tienen las mismas apariciones, la condición será falsa, luego da igual cuál se devuelva
		else return { b.first, b.first.apariciones > (fin - ini) / 2 }; 

	}
}


void resuelveCasos() {
	std::vector<int> v; 
	int n; 
	std::cin >> n; 
	while (n != 0) {
		v.push_back(n); 
		cin >> n; 
	}

	auto sol = resolver(v, 0, v.size()); 
	if (sol.second) std::cout << sol.first.elem << '\n';
	else std::cout << "NO\n"; 



}



int main() {
	int n; 
	std::cin >> n; 
	for (int i = 0; i < n; ++i) resuelveCasos(); 
	return 0; 
}


