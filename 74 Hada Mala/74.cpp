#include <iostream>
#include <vector>
#include <climits>
using namespace std; 

//Gonzalo Sánchez Montesinos
//DG29

/*
Árbol de exploración: 
	Ramas: invitados de la lista
	Altura: puestos

Vector solución: 
	Índices: puestos
	Contenido: en sol[i] se guarda el invitado que ocupa el puesto i 

Marcas: 
	vector de booleanos que tiene: 
		Índices: invitados
		marcas[i]: 1 se ha usado, 0 en otro caso

Medidas adicionales para cortar ramas: 
	Guardar un vector con la suma de la satisfacción máxima de los nodos que quedan por poner. Si esa suma más la 
	satisfacción actual es menor que la satisfacción máxima, entonces se corta la rama. 

*/

bool isValid(int m ,int k, int i,int satis_actual ,const int& satis_max,  const std::vector<bool>& marcas, const std::vector<std::vector<int>>& satis, const std::vector<int>& suma, int iguales) {
	if (marcas[i]) return false;
	else if (k == i && (iguales + 1) > m / 3) return false;
	else if (satis[k][i] <= 0) return false;
	else if ( k < m-1 && satis_actual + satis[k][i] + suma[k+1] < satis_max) return false; 
	else return true; 
}

void va(int n, int m, int k, std::vector<int>& sol,int satis_actual ,int& satis_max, int& num_comb, std::vector<bool>& marcas, const std::vector<std::vector<int>>& satis, const std::vector<int>& suma, int iguales, int hada) {
	for (int i = 0; i < n; ++i) {
		sol[k] = i; //Apuesto por la solución i
		if (isValid(m, k, i,satis_actual ,satis_max, marcas, satis, suma, iguales)) {
			//Se marca: 
			marcas[i] = true; 
			satis_actual += satis[k][i]; 
			if (k == i) ++iguales; 

			if (k == m - 1) {
				if (marcas[hada]) {
					if (satis_actual == satis_max) ++num_comb;
					else if (satis_actual > satis_max) {
						satis_max = satis_actual;
						num_comb = 1;
					}
				}
			}
			else va(n, m, k + 1, sol, satis_actual, satis_max, num_comb, marcas, satis, suma, iguales, hada); 

			//Se desmarca: 
			marcas[i] = false;
			satis_actual -= satis[k][i];
			if (k == i) --iguales;
		}
	}
}


bool resuelveCasos() {
	int n = 0, m = 0; 
	std::cin >> n;
	if (n == 0) return false; 
	else {
		std::cin >> m; 
		int hada; 
		std::cin >> hada; 
		std::vector<std::vector<int>> satis(m, std::vector<int>(n, 0)); 
		std::vector<int> max_satis_puesto(m, 0); 
		for (int i = 0; i < m; ++i) {
			int max = INT_MIN; 
			for (int j = 0; j < n; ++j) {
				std::cin >> satis[i][j];
				if (satis[i][j] > max) max = satis[i][j]; 
			}
			max_satis_puesto[i] = max; 
		}

		std::vector<int> suma_satis_puestos_por_recorrer(m, 0); 
		suma_satis_puestos_por_recorrer[suma_satis_puestos_por_recorrer.size() - 1] = max_satis_puesto[max_satis_puesto.size() - 1]; 
		for (int i = suma_satis_puestos_por_recorrer.size() - 1; i > 0; --i) {
			suma_satis_puestos_por_recorrer[i - 1] = suma_satis_puestos_por_recorrer[i] + max_satis_puesto[i-1];
		}

		//Inicialización satisfacción mejor: 
		int satis_max = INT_MIN; 
		int combinaciones = 0; 
		std::vector<int> sol(m, 0); 
		std::vector<bool> marcas(n, false); 
		va(n, m, 0,sol, 0, satis_max, combinaciones, marcas, satis, suma_satis_puestos_por_recorrer, 0, hada); 

		if (combinaciones != 0) std::cout << satis_max << ' ' << combinaciones << '\n';
		else std::cout << "No\n"; 


		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}