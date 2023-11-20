#include <iostream>
#include <vector>
using namespace std; 

//Gonzalo Sánchez Montesinos
int binarySearch(std::vector<int> const& v, int ini, int fin, int d) {
	if (ini >= fin) return ini;
	else if (ini + 1 == fin) return ini; 
	else {
		int mitad = (ini + fin - 1) / 2;
		int days = 0;
		int carga = 0;
		int i = 0;

		while (i < v.size() && days < d) {
			if (carga + v[i] <= mitad) {
				carga += v[i];
				++i;
			}
			else {
				carga = v[i];
				++days;
				++i;
			}
		}
		if (carga > 0) ++days;
		if (i == v.size() && days <= d) return binarySearch(v, ini, mitad + 1, d);
		else return binarySearch(v, mitad + 1, fin, d);
	}
	
}


bool resuelveCasos() {
	int n, d; 
	std::cin >> n >> d;
	if (n == 0 && d == 0) return false; 
	else {
		std::vector<int> v(n); 
		int ini = 0; 
		int fin = 0; 
		for (int& x : v) {
			std::cin >> x; 
			ini = max(x, ini); 
			fin += x; 
		}
		std::cout << binarySearch(v, ini, fin+1,d) << '\n';
		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}