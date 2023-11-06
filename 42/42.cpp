//DG29
//Gonzalo Sánchez Montesinos
#include <iostream>
#include <string>
using namespace std;
using lli = long long int;

lli sinUnos(lli n) {
	if (n == 0) return 1;
	else if (n < 10) return n; 
	else {
		int aux = 0; 
		switch (n % 10) {
		case 0: aux = 0; break; 
		case 1: aux = 0; break; 
		default: aux = 9 - n % 10; break; 
		}
		return sinUnos(n / 10) * 9 - aux; 
	}
}

bool resuelveCasos() {
	lli n = 0;
	std::cin >> n;
	if (!cin) return false; 
	else {
		std::cout << sinUnos(n) << '\n';
		return true; 
	}
}


int main() {
	while (resuelveCasos());
	return 0;
}