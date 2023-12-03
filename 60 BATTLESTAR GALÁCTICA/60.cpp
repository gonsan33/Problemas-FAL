#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int mergesort(vector<int>& v, int ini, int fin) {
	if (ini + 1 == fin) return 0; 
	else {
		int mitad = (ini + fin - 1) / 2; 
		//Se ordenan las dos mitades y se cuentan las trasposiciones 
		int a = mergesort(v, ini, mitad + 1); 
		int b = mergesort(v, mitad + 1, fin);
		int trasposiciones = a + b ; 
		//Se copia en un vector auxiliar utilizando el algoritmo de mezcla ordenada. 

		int i = ini; 
		int j = mitad + 1; 
		while (i < mitad + 1 && j < fin) {
			if (v[i] < v[j]) ++i; 
			else { //v[i] > v[j]
				trasposiciones += mitad - (i - ini); 
				++j; 
			}
		}
		while (i < mitad + 1) {
			if (v[i] > v[j]) {
				trasposiciones += mitad - (i - ini); 
				++i; 
			}
		}

		while (j < fin) {
			if (v[i] > v[j]) {
				trasposiciones += mitad - (i - ini);
				++j; 
			}
		}
		inplace_merge(v.begin() + ini, v.begin() + mitad + 1, v.begin() + fin); 
		/*
		int k = ini; 
		int trasposiciones_transitorias = 0; 
		vector<int> aux(v.size()); 
		while (i < mitad + 1 && j < fin) {
			if (v[i] < v[j]) {
				aux[k] = v[i]; 
				++i; 
				++k; 
			}
			else {//no hay repetidos
				aux[k] = v[j]; 
				++j; 
				++k; 
				trasposiciones += (j - k) - trasposiciones_transitorias; 
				trasposiciones_transitorias = j-k; 
			}
			trasposiciones_transitorias = max(0, trasposiciones_transitorias - 1);
		}
		while (i < mitad+1) {
			aux[k] = v[i]; 
			++i; 
			++k; 
			trasposiciones_transitorias = max(0, trasposiciones_transitorias - 1);
		}
		while (j < fin) {
			aux[k] = v[j]; 
			++j; 
			++k; 
			trasposiciones_transitorias = max(0, trasposiciones_transitorias - 1);
		}
		for (int r = ini; r < fin; ++r) {
			v[r] = aux[r]; 
		}
		*/


		
		return trasposiciones;
	}
}


bool resuelveCasos() {
	int n; 
	std::cin >> n; 
	if (!cin) return false; 
	vector<int> v(n); 
	for (auto& x : v) std::cin >> x; 
	if (n == 0) std::cout << 0 << '\n'; 
	else std::cout << mergesort(v, 0, v.size())<<'\n';
	return true; 
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}