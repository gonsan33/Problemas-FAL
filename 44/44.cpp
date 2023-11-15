#include <iostream>
#include <string>
#include <vector>
using namespace std; 
using lli = long long int; 

lli comb(int n, int m, std::vector<std::vector<int>>& matriz) {
	if (n == 0) return matriz[n][m] = 1;
	else if (m == 0 || m == n) return matriz[n][m] = 1;
	else if (m == 1 || m == n - 1) return matriz[n][m] = n; 
	else {
		if (matriz[n - 1][m] == -1) matriz[n - 1][m] = comb(n - 1, m, matriz); 
		if(matriz[n-1][m-1] == -1)matriz[n - 1][m-1] = comb(n - 1, m-1, matriz);
		return matriz[n][m] = matriz[n - 1][m - 1] + matriz[n - 1][m]; 
	}
}

bool resuelveCasos() {
	int n, m; 
	std::cin >> n; 
	if (!cin) return false; 
	else {
		std::cin >> m; 
		
		std::vector<std::vector<int>> matriz(n+1,vector<int>(m+1,-1)); 
		std::cout << comb(n, m, matriz) << '\n'; 
		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}