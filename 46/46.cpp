//DG29
//Gonzalo Sánchez Montesinos
#include <iostream>
#include <string>
using namespace std; 
using lli = long long int; 

//No final: 
pair<lli,lli> poli(int n, int y) {
	if (n == 0) return { 1,0 };
	else if (n == 1) return { 2 * y,1 }; 
	else {
		pair<lli, lli> sol = poli(n - 1, y); 
		return { 2 * y * sol.first - 2 * (n - 1) * sol.second, sol.first }; 
	}
}



//Final
long long int poli(int n, int y, lli n1, lli n2) {
	if (n == 0) return n2;
	else if (n == 1) return n1; 
	else {
		return poli(n - 1, y, 2 * y * n1 - 2 * (n - 1) * n2, n1); 
	}
}


bool resuelveCasos() {
	int n = 0; 
	std::cin >> n; 
	if (n == -1) return false; 
	else {
		int y = 0; 
		std::cin >> y; 
		std::cout << poli(n, y).first << '\n'; //no final
		//std::cout << poli(n,y,2*y,1) << '\n'; //final
		return true; 
	}
}


int main() {
	while (resuelveCasos()); 
	return 0; 
}

//Recurrencia : 
/*
T(n) = C0 si n==0
T(n) = C1 si n==1
T(n) = T(n-1) + C2 si n>1
Haciendo el desplegado: 
T(n) = T(n-1) + C2 = T(n-2) + 2*C2  = ... = T(n-k) + k*C2 = ... = T(1) + (n-1) * C2 = C1 + (n-1) * C2
Por lo tanto T(n) está en O(n) 



Por contra, el coste de la definición recursiva es 
T(n) = C0 si n==0
T(n) = C1 si n==1
T(n) = T(n-1) + T(n-2) + C2 si n>1
Esta recurrencia es análoga a la vista en clase para Fibonacci, que vimos que pertenecía a O(2^n)
La cota superior vista en clase fue T(n) = 2*T(n-1) + C2
Desplegando: 
T(n) = ... = 2^k T(n-k) + C2 * sumatorio desde i = 1 hasta k de 2^i = C2*sumatorio desde i = 1 hasta n de 2^i
Esto está en O(2^n)
*/ 