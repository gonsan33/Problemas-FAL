#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

//Gonzalo Sánchez Montesinos 
//DG29

pair<int,int> ventana(const std::vector<int>& v, int m) {
	int sumaParcial = 0; 
	for (int i = 0; i < m; ++i) {
		sumaParcial += v[i]; 
	}
	int s = sumaParcial; 
	int pos = 0; 
	for (int j = 0; j < v.size() - m; ++j) {
		sumaParcial -= v[j]; 
		sumaParcial += v[j + m]; 
		if (sumaParcial >= s) {
			s = sumaParcial;
			pos = j + 1; 
		}
	}
	return { pos,s };
}


void resuelveCasos() {
	int n = 0; 
	std::cin >> n; 
	int m = 0; 
	std::cin >> m; 
	std::vector<int> v(n); 
	for (int& x : v) std::cin >> x; 
	pair<int, int> sol = ventana(v, m); 
	std::cout << sol.first << " " << sol.second << '\n';
	
}

int main() {
	int n = 0; 
	std::cin >> n; 
	for (int i = 0; i < n; ++i) resuelveCasos(); 

	return 0; 
}