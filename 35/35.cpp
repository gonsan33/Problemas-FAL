#include <iostream>
using namespace std; 
//Gonzalo Sánchez Montesinos
//DG29

int mcd(int a, int b) {
	if (b == 0) return a;
	else return mcd(b, a % b); 
}

bool resuelveCasos() {
	int a, b; 
	std::cin >> a >> b; 
	if (a == 0 && b == 0) return false; 
	else {
		if (a >= b) std::cout << mcd(a, b) << '\n';
		else std::cout << mcd(b, a) << '\n'; 
		return true; 
	}
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}