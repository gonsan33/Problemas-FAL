#include <vector>
#include <iostream>
using namespace std; 

//Gonzalo Sánchez Montesinos
//DG29
int resolver(const std::vector<int>& v, int k) {
	int cont = 0; 
	std::vector<int> posiciones(k, -1);  //Almacena las posiciones de los últimos trues
	int lm = 0; 
	int i = 0;
	//Se inicializa: 
	while (i < v.size() && cont < k) {
		if (v[i] == 1) {
			posiciones[cont] = i; 
			++cont; 
		}
		++i; 
	}
	lm = posiciones[k-1] - posiciones[0] +1; 
	if (cont < k) return v.size() + 1; 
	else {
		for (int i = posiciones[k - 1] + 1; i > 0 && i < v.size(); ++i) {
			if (v[i] == 1) {
				for (int j = 0; j < k - 1; ++j) {
					posiciones[j] = posiciones[j + 1];
				}
				posiciones[k - 1] = i;
				if (posiciones[k - 1] - posiciones[0] + 1 < lm) lm = posiciones[k - 1] - posiciones[0] + 1;
			}
		}

		return lm;
	}
	

}


bool resuelveCasos() {
	int n; 
	std::cin >> n; 
	if (n == -1) return false; 
	else {
		std::vector<int> v(n); 
		for (auto& x : v) std::cin >> x; 
		int k; 
		std::cin >> k; 
		std::cout << resolver(v,k) <<'\n';
		return true; 
	}
}



int main() {
	while (resuelveCasos()); 
	return 0; 
}