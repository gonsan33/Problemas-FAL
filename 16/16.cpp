#include <iostream>
#include <string>
#include <vector>
using namespace std; 
//Gonzalo Sánchez Montesinos 
//DG29

//precondición: 0 <= v.size <= 200000 && k >= 0 
int fun_kemparejados(std::vector<int>& v, int k) {
	//Inicialización
	int i = 0; 
	int j = 0; 
	int cont = 0; 
	//Bucle
	while (j < v.size()) {
		//Invariante: i <= j
		//Invariante: # (n,m): 0<= n < j &&  0<= m < j && n<= m : |v[n] - v[m]| = k
		if (v[j] - v[i] == k) {
			++j;
			++i;
			++cont; 
		}
		else if (v[j] - v[i] < k) ++j;
		else ++i; 
	}
	return cont; 
}
//poscondición: res = # (i,j): 0<= i < v.size &&  0<= j < v.size : |v[i] - v[j]| = k


bool resuelveCasos() {
	int tam = 0; 
	std::cin >> tam; 
	if (tam == -1) return false; 
	else {
		std::vector<int> v(tam); 
		int k = 0; 
		std::cin >> k; 
		for (auto& x : v) std::cin >> x; 
		std::cout << fun_kemparejados(v, k) << '\n'; 
		return true; 
	}
}

int main() {
	while (resuelveCasos()); 
	return 0;
}