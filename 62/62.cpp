#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std; 

//Gonzalo Sánchez Montesinos 
//DG29

//Búsqueda binaria en el espacio de soluciones 
int binarySearch(std::vector<int>& v, int ini, int fin, int p) {
	//Caso base
	if (ini + 1 == fin && v[ini] > (int(v.size()) - ini) * p) return fin;
	else if(ini + 1 == fin) ini;
	else {	//Caso recursivo: 
		int mitad = (ini + fin - 1) / 2; 
		if (v[mitad] > (int(v.size()) - ini) * p) {//Se puede racionalizar el agua más tarde: 
			return binarySearch(v, mitad + 1, fin, p);
		}
		else return binarySearch(v, ini, mitad + 1, p); 
	}


}

void resuelveCasos() {
	int m, g; 
	std::cin >> m >> g; 
	std::vector<int> v(m); 
	for (int i = 0; i < v.size(); ++i) {
		std::cin >> v[i]; 
	}
	int a = binarySearch(v, 0, v.size(), g); 
	std::cout << a << '\n'; 
}

int main() {
	int n; 
	std::cin >> n; 
	for (int i = 0; i < n; ++i) resuelveCasos();
	return 0; 
}