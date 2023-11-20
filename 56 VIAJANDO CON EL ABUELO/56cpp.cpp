//GONZALO SÁNCHEZ MONTESINOS 
//DG29
#include <iostream>
#include <vector>
using namespace std; 

int binarySearchlowerbound(const std::vector<int>& v, int elem, int ini, int fin) {
	if (ini >= fin) return ini; //Vector vac?o
	else if (ini + 1 == fin) return ini; //vector de un elemento
	else {
		int mitad = (ini + fin - 1) / 2; //El de la izquierda
		if (v[mitad] < elem) return binarySearchlowerbound(v, elem, mitad + 1, fin);
		else return binarySearchlowerbound(v, elem, ini, mitad + 1);  //para que incluya la mitad
	}
}



bool resuelveCasos() {
	int n, p; 
	std::cin >> n >> p; 
	if (n == 0 && p == 0) return false; 
	else {
		vector<int> v(n); 
		vector<int> sumas(n); 
		std::cin >> v[0];
		sumas[0] = v[0]; 

		for (int i = 0; i < n; ++i) {
			std::cin >> v[i]; 
			sumas[i] = sumas[i - 1] + v[i]; 
		}
		for(int i )
		return true; 
	}
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}