#include <iostream>
#include <vector>
using namespace std; 
//Gonzalo Sánchez Montesinos 
//DG29


//Coste lineal en el número de etapas. 

bool resuelveCasos() {
	int tam = 0; 
	std::cin >> tam; 
	if (tam == -1) return false; 
	else {
		std::vector <long long int> v(tam); 
		for (auto& x : v) std::cin >> x; 
		
		//Se calculan las sumas
		for (int i = v.size() - 2; i >= 0; --i ) {
			v[i] = v[i] + v[i + 1]; 
		}
		int preg = 0; 
		std::cin >> preg; 
		for (int i = 0; i < preg; ++i) {
			int d = 0; 
			std::cin >> d;
			if (d <= v.size() && d>0) {
				std::cout << v[d - 1] << '\n';
			}
			else std::cout << 0 << '\n';
		}
		std::cout << "---\n"; 
		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}