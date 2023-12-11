#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Árbol de exploración: 
	Ramas: trabajos
	Nodos: funcionarios

Vector solución: 
	Índices: funcionarios
	Contenido: trabajos


*/

bool isValid(int i, int n, int k, int t_act, int t_min, std::vector<bool>& marcas, const std::vector<std::vector<int>>& tiempos, const std::vector<int>& sumas) {
	if (marcas[i]) return false;
	else if (k < n - 1 && t_act + tiempos[k][i] + sumas[k + 1] > t_min)  return false;
	else return true; 
}


void va(int n, int k, int t_act, int& t_min, std::vector<bool>& marcas, std::vector<int>& sol, const std::vector<std::vector<int>>& tiempos, const std::vector<int>& sumas) {
	for (int i = 0; i < n; ++i) {
		sol[k] = i; 
		if (isValid(i, n, k, t_act, t_min, marcas, tiempos, sumas)) {
			marcas[i] = true; 
			t_act += tiempos[k][i]; 
			if (k == n - 1) {
				if (t_act < t_min) t_min = t_act;
			}
			else va(n, k + 1, t_act, t_min, marcas, sol, tiempos, sumas); 

			marcas[i] = false;
			t_act -= tiempos[k][i];
		}
	}
}




bool resuelveCasos() {
	int n; 
	std::cin >> n; 
	if (n == 0) return false; 
	else {
		std::vector<std::vector<int>> tiempos(n, std::vector<int>(n, 0)); 
		std::vector<int> sumas(n, 0); 
		for (int i = 0; i < n; ++i) {
			int min = INT_MAX; 
			for (int j = 0; j < n; ++j) {
				std::cin >> tiempos[i][j]; 
				if (tiempos[i][j] < min) min = tiempos[i][j]; 
			}
			sumas[i] = min; 
		}

		for (int i = sumas.size() - 2; i >= 0; --i) {
			sumas[i] += sumas[i + 1]; 
		}
		//Solución inicial
		int t_min = 0; 
		for (int i = 0; i < n; ++i) {
			t_min += tiempos[i][i]; 
		}

		std::vector<bool> marcas(n, false); 
		std::vector<int> sol(n, 0);
		va(n, 0, 0, t_min, marcas, sol, tiempos, sumas); 
		std::cout << t_min << '\n'; 
		return true; 
	}
}


int main() {
	while (resuelveCasos());
	return 0;
}