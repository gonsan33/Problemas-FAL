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
	if (ini + 1 == fin && v[ini] >= (int(v.size()) - ini) * p) return fin;
	else if(ini + 1 == fin) return ini;
	else {	//Caso recursivo: 
		int mitad = (ini + fin - 1) / 2; 
		if (v[mitad] >= (int(v.size()) - mitad) * p) {//Se puede racionalizar el agua más tarde: 
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
	if (a == v.size()) std::cout << "SIN RACIONAMIENTO\n"; 
	else std::cout << a << '\n'; 
}

int main() {
	int n; 
	std::cin >> n; 
	for (int i = 0; i < n; ++i) resuelveCasos();
	return 0; 
}


/*Recurrencia
T(n) = C0 si n = 1
T(n) = T(n/2) + C1 si n >= 2

Desplegado: 
T(n) = T(n/2) + C1 = T(n/4) + 2C1 = ... = T(n/2^k) + kC1 = ... = C0 +  log2(n) C1
Luego está en O(log2(n)) donde n es el tamaño del vector(número de obras de arte). 


*/