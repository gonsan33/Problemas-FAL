//GONZALO SÁNCHEZ MONTESINOS
//DG 29
#include <iostream>
#include <vector>
using namespace std; 

std::ostream& operator << (std::ostream& op, const std::vector<int>& v) {
	if (v[0] == 0) {
		op << "azul";
	}
	else if (v[0] == 1) op << "rojo";
	else std::cout << "verde"; 
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] == 0) {
			std::cout << " azul";
		}
		else if (v[i] == 1) std::cout << " rojo";
		else std::cout << " verde";
	}

	return op; 
	
}

void va(int altura, vector<int>& sol, int k) {
	for (int i = 0; i < 3; ++i) {
		sol[k] = i; 
		if (k == altura - 1) std::cout << sol << '\n';
		else va(altura, sol, k + 1); 
	}
}

bool resuelveCasos() {
	int altura; 
	std::cin >> altura; 
	if (altura == 0) return false; 
	else {
		std::vector<int> sol(altura, 0); 
		va(altura, sol,0); 
		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}