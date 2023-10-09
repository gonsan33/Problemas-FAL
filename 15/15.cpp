#include <vector>
#include <iostream>
using namespace std;
//Gonzalo Sánchez Montesinos 
//DG 29

bool crecientePorLosPelos(std::vector<int> v) {
	bool creciente = true;
	int i = 0;
	while (i < v.size() - 1 && v[i + 1] - v[i] >= 0 && v[i + 1] - v[i] <= 1) ++i;
	return i == v.size() - 1; 
}

bool divertido(std::vector<int> v, int d) {//Se puede asumir que es creciente
	int num_rep = 1; 
	int i = 1; 
	int last_elem = v[0]; 
	int rep_elem = 1; 
	while (i < v.size() && num_rep <= d) {
		if (v[i] == last_elem) {
			++rep_elem;
			if (rep_elem > num_rep) num_rep = rep_elem;
		}
		else { 
			rep_elem = 1;
			last_elem = v[i]; 
		}
		++i; 
	}
	return num_rep <= d; 
}

void resuelveCasos() {
	int d = 0; 
	int tam = 0; 
	std::cin >> d >> tam; 
	std::vector<int> v(tam); 
	for (auto& x : v) std::cin >> x; 
	
	if (crecientePorLosPelos(v) && divertido(v, d)) std::cout << "SI\n";   //El vector es creciente, se usa short boolean evaluation
	else std::cout << "NO\n"; 
}


int main() {
	int number_of_cases = 0; 
	std::cin >> number_of_cases; 
	for (int i = 0; i < number_of_cases; ++i) resuelveCasos(); 
	return 0; 
}