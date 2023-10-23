// Nombre del alumno GONZALO SÁNCHEZ MONTESINOS
// Usuario del Juez DG29


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

void resolver(std::vector<int>& v, int & sumamax, int& inidemax, int& lengthdemax) {
	//Inicialización
	int ini = 0; 
	 sumamax = v[0]; 
	 inidemax = 0; 
	int sumaactual = v[0]; 
	int length = 1; 
	 lengthdemax = 1; 
	for (int i = 1; i < v.size(); ++i) {
		if (sumaactual > 0) {
			sumaactual += v[i]; 
			++length; 
		}
		else {
			sumaactual = v[i]; 
			length = 1; 
			ini = i; 
		}
		if (sumaactual > sumamax || (sumaactual == sumamax && length < lengthdemax)) { 
			sumamax = sumaactual;
			lengthdemax = length; 
			inidemax = ini; 
		}
	}

}


bool resuelveCasos() {
	int n = 0; 
	std::cin >> n; 
	if (!cin) return false; 
	else {
		std::vector<int> v(n); 
		for (int& x : v) std::cin >> x; 
		int ini = 0, suma = 0, lenthdemax = 0; 
		resolver(v, suma, ini, lenthdemax); 
		std::cout << suma << " " << ini << " " << lenthdemax << '\n'; 
		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 

}