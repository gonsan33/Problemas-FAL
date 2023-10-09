#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

//Nombre : Gonzalo Sánchez Montesinos
//Usuario del juez: DG29

void resolver(std::vector<int>& v) {
	std::sort(v.begin(), v.end());
	int pos_insert = 1; 
	int tam = 1; 
	int last_value = v[0]; 
	for (unsigned int i = 1; i < v.size(); ++i) {
		if (last_value != v[i]) {
			v[pos_insert] = v[i]; 
			++pos_insert; 
			++tam; 
			last_value = v[i]; 
		}
	}
	v.resize(tam); 
}


bool resuelveCasos() {
	int tam = 0; 
	std::cin >> tam;

	if (!cin) return false; 
	else {
		std::vector<int> v(tam);
		for (int& x : v) std::cin >> x;
		resolver(v); 
		//Visualización: 
		for (auto& x : v) std::cout << x << " "; 
		std::cout << '\n'; 

		return true; 
	}
}




int main() {
	while(resuelveCasos()); 

	return 0; 
}