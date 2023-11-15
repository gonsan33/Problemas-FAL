#include <iostream>
#include <string>
using namespace std;
using lli = long long int; 
//Gonzalo Sánchez Montesinos
//DG29

lli f(int n, lli n1, lli n2) {
	if (n == 0) return n2;
	else return f(n - 1, n1 + n2, n1); 
}

lli f(int n) {
	return f(n, 1, 0);
}

bool resuelveCasos() {
	int n; 
	std::cin >> n; 
	if (!cin) return false; 
	else {
		std::cout << f(n) << '\n'; 
		return true; 
	}
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}