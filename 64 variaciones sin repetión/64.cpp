//DG29
//Gonzalo Sánchez Montesinos

#include <iostream>
#include <vector>
using namespace std; 

std::ostream& operator << (std::ostream& op,const std::vector<char>& v) {
	for (auto& x : v) op << x; 
	return op; 
}

void va(int m, int n, int k, std::vector<char>& sol, std::vector<bool>& marcas) {
	for (int i = 'a'; i < 'a' + m; ++i) {
		sol[k] = 'a' + i; 
		if (!marcas[i-'a']) {
			marcas[i] = true; 
			if (n - 1 == k)	std::cout << sol << '\n';
			else va(m, n, k + 1, sol, marcas); 
			marcas[i - 'a'] = false; 
		}
	}
}


bool resuelveCasos() {
	int m, n; 
	std::cin >> m; 
	if (!cin) return false; 
	cin >> n;
	std::vector<char> sol(n); 
	std::vector<bool> marcas(m, false); 
	va(m, n, 0, sol, marcas); 
	return true; 
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}