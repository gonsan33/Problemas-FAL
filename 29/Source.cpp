//Gonzalo Sánchez Montesinos
//DG29

#include <iostream>
#include <string>
#include <vector>
using namespace std; 


std::vector<int> resolver(const std::vector<int>& v, int l) {
	int length = 1; 
	int lengthmax = 0; 
	int last_elem = v[v.size() - 1]; 
	int numprados = 0; 
	int ini = v.size() - 1; 
	int max_altura = v[v.size() - 1]; 

	std::vector<int> sol(2,0); 
	for (int i = v.size() - 2; i >= 0; --i) {
		if (v[i] == last_elem && v[i] >= max_altura) {
			++length; 
			if (length > lengthmax && length >= l) {
				lengthmax = length; 
			}
		}
		else {
			if (length >= l) {
				++numprados; 
				sol.push_back(ini);

			}
			if (v[i] > max_altura) max_altura = v[i]; 
			
			length = 1;
			last_elem = v[i];
			
			ini = i; 
			
		}
		
	}
	if (length >= l) {
		++numprados;
		sol.push_back(ini);
	}
	sol[0] = lengthmax; 
	sol[1] = numprados; 
	return sol; 
}

bool resuelveCasos() {
	int tam = 0; 
	std::cin >> tam; 
	if (!cin) return false; 
	else {
		int l = 0; 
		std::cin >> l; 
		std::vector<int> v(tam); 
		for (int& x : v) std::cin >> x; 
		std::vector<int> sol = resolver(v, l); 
		std::cout << sol[0] ; 
		for (int i = 1; i < sol.size(); ++i) {
			std::cout << " " << sol[i]; 
		}
		std::cout << '\n'; 
		return true; 
	}
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}