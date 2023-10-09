#include <iostream>
#include <string>
#include <vector>
using namespace std; 

//Gonzalo Sánchez Montesinos 
//DG 29


using lli = long long int; 
void preproceso(std::vector<lli>& v) {
	for (int i = 1; i < v.size(); ++i) {
		v[i] = v[i] + v[i - 1]; 
	}
}

void resolver_preguntas(std::vector<lli>& v, int prin) {
	int number_of_cases = 0; 
	std::cin >> number_of_cases; 
	int ini = 0; 
	int fin = 0; 
	for (int i = 0; i < number_of_cases; ++i) {
		std::cin >> ini >> fin; 
		if (ini > prin) {
			std::cout << v[fin - prin] - v[ini - prin - 1]<< '\n';
		}
		else std::cout << v[fin - prin] << '\n';
	}
	std::cout << "---\n"; 
}

bool resuelveCasos() {
	int ini = 0; 
	int fin = 0; 
	std::cin >> ini >> fin; 
	if (ini == 0 && fin == 0) return false; 
	else {
		int tam = fin - ini + 1; 
		std::vector<lli> v(tam); 
		for (auto& x : v)std::cin >> x; 
		preproceso(v); 
		resolver_preguntas(v, ini); 
		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}