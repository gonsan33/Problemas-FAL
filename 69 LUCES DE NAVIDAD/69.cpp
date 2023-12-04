//GONZALO SÁNCHEZ MONTESINOS
//DG29

#include <iostream>
#include <vector>
using namespace std; 

//En el árbol, las ramas son las bombillas de cada color. 
//las etapas son el número de bombillas puestas
//Tenemos un vector de marcas que contiene la siguiente información: El número de bombillas de un color dado
//La suma de las bombillas de la tira es la etapa (k)
//Se lleva el consumo de la tira y el consumo máximo 





void va(int n, int colores, const std::vector<int>& consumos, std::vector<int>& sol, int k, std::vector<int>& marcas, int consumo_tira, int consumo_max, int& combinaciones) {
	for (int i = 0; i < colores; ++i) { 
		sol[k] = i; 
		if ((k > 1 && !(sol[k] == sol[k-1] && sol[k-1] == sol[k-2]) || k == 0 || k == 1) && marcas[i] <= k - marcas[i] && consumo_tira + consumos[i] <= consumo_max) {

			//Se marca
			++marcas[i]; 
			consumo_tira += consumos[i]; 

			if (k == n - 1)  ++combinaciones;
			else va(n, colores, consumos, sol, k + 1, marcas, consumo_tira, consumo_max, combinaciones); 


			//Se desmarca: 
			--marcas[i]; 
			consumo_tira -= consumos[i];
		}
	}
}

bool resuelveCasos() {
	int n, colores, consumo; 

	std::cin >> n; 
	if (n == 0) return false; 
	cin>> colores >> consumo; 
	std::vector<int> consumos(colores); 
	for (auto& x : consumos) std::cin >> x; 
	std::vector<int> sol(n, -1); 
	std::vector<int> marcas(colores,0); 
	int combinaciones = 0; 
	va(n, colores, consumos, sol, 0, marcas, 0, consumo, combinaciones);
	std::cout << combinaciones << '\n'; 
	return true; 
}


int main(){
	while (resuelveCasos()); 
	return 0; 

}

