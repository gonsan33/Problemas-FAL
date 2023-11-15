#include <iostream>
#include <vector>
using namespace std; 
//Gonzalo Sánchez Montesinos
//DG29
/*
Definición recursiva: 
f(x,n,m) = 0 si n > m
f(x,n,m) = 1 si n == m y v[n] == valor
f(x,n,m) = f(x,n+1,m) + f(x - v[n], n+1,m)
Es decir, el objetivo es llegar a subproblemas "con un vector de un elemento", así, hay una forma de sumar el valor dado 
si y solo si el elemento es igual al elemento del vector. Para disminuir el número de elementos del vector, se consideran índices
entre n y m. 
En el caso recursivo, se consideran las formas de sumar el valor x entre los índices n+1 y m habiendo cogido v[n] como parte de la suma
o sin haberlo cogido como parte de la suma
m será v.size()-1
*/

int formas(const std::vector<int>& v, int x, int n, int m, std::vector<std::vector<int>>& matriz) {
	if (n > m) return matriz[x][n] = 0;
	else if (n == m && v[n] == x) return matriz[x][n] = 1;
	else if (n == m) return matriz[x][n] = 0;
	else {
		if (matriz[x][n + 1] == -1) {
			matriz[x][n + 1] = formas(v, x, n + 1, m, matriz);
		}
		int b; 
		if (x - v[n] > 0) {
			if (matriz[x - v[n]][n + 1] == -1) {
				matriz[x - v[n]][n + 1] = formas(v, x - v[n], n + 1, m, matriz);
			}
			b = matriz[x - v[n]][n + 1];
		}
		else if (x - v[n] == 0) b = 1;
		else b = 0; 
		return matriz[x][n + 1] + b; 
	}
}



/*
int formas(const std::vector<int>& v,int x ,int n,int m ,std::vector<std::vector<int>>& matriz) {
	if (x == 0) return 1;
	if (n > m) return matriz[x][n] = 0;
	else if (n == m && v[n] == x) return matriz[x][n] = 1;
	else if (n == m) return matriz[x][n] = 0;
	else {
		int a= 0, b= 0;
		if (matriz[x][n + 1] == -1) {
			matriz[x][n + 1] = formas(v, x, n + 1, m, matriz); a = matriz[x][n + 1];
		}
		if (x - v[n] >= 0) {
			if (matriz[x - v[n]][n + 1] == -1) {
				matriz[x - v[n]][n + 1] = formas(v, x - v[n], n + 1, m, matriz);
				b = matriz[x - v[n]][n + 1];
			}
		}
		return matriz[x][n] = a+b;
	}
}
*/


bool resuelveCasos() {
	int n; 
	int x; 
	std::cin >> n; 
	if (!cin)return false; 
	else {
		std::cin >> x; 
		std::vector<int> v(n); 
		for (auto& i : v)std::cin >> i;  
		std::vector<std::vector<int>> matriz(x + 1, vector<int>(n+1,-1)); 
		std::cout << formas(v, x,0,v.size()-1, matriz) << '\n';
		return true; 
	}
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}