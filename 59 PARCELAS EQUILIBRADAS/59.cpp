#include <iostream>
#include <vector>
using namespace std; 
const int incF[4] = {0,1,0,1};
const int incC[4] = { 0,0,1,1 }; 



struct tSol {
	int labranza; 
	int total; 
	bool sol; 
	tSol() {
		labranza = 0; 
		total = 0; 
		sol = false; 
	}
	tSol(int labranza, int total, bool sol) {
		this->labranza = labranza; 
		this->total = total; 
		this->sol = sol; 
	}
};

tSol eq(std::vector<std::vector<int>>& m, int dim, int m_i, int m_j) {
	if (dim == 1) return tSol(int(m[m_i][m_j] == 1), dim, true);
	else {
		int mitad = dim / 2; 
		tSol* arr[4]; 
		for (int i = 0; i < 4; ++i) arr[i] = new tSol; 
		bool todos_corr = true; 
		int i = 0; 
		while (todos_corr && i < 4) {//Poda
			*arr[i] = eq(m, mitad, m_i + incF[i] * mitad, m_j + incC[i] * mitad); 
			todos_corr = todos_corr && arr[i]->sol; 
			++i; 
		}

		if (todos_corr) {
			int suma_l = 0;
			int total = 0;
			for (int i = 0; i < 4; ++i) {
				suma_l += arr[i]->labranza;
				total += arr[i]->total;
			}
			if (suma_l <= double(3 / double(4)) * total && suma_l >= (total - 1) / double(4)) {
				bool res = true;
				int i = 0;
				int j = 0;
				while (i < 4 && res) {
					j = i + 1;
					while (j < 4 && res) {
						res = abs(arr[i]->labranza - arr[j]->labranza) <= 2;
						++j;
					}
					++i;
				}
				return tSol(suma_l, total, res);
			}
			else return tSol();
		}
		else return tSol(); 
	}
}


void resuelveCasos() {
	int dim; 
	std::cin >> dim; 
	std::vector<std::vector<int>> m(dim, std::vector<int>(dim,0)); 
	for (auto& v : m) {
		for (auto& x : v) std::cin >> x; 
	}
	if (eq(m,dim, 0,0).sol) std::cout << "SI\n";
	else std::cout << "NO\n"; 
}

int main() {
	int n; 
	std::cin >> n; 
	for (int i = 0; i < n; ++i) resuelveCasos(); 
	return 0; 
}