//DG29
//Gonzalo Sánchez Montesinos
#include <iostream>
#include <string>
using namespace std;
using lli = long long int;

pair<lli, bool> sinUnos(lli n) {
	if (n == 0) return { 1,false };
	else if (n < 10) return { n, n == 1 }; 
	else {
		auto aux = sinUnos(n / 10); 
		if (aux.second) {
			return { aux.first * 9,true }; 
		}
		else {
			auto aux2 = sinUnos(n % 10); //Coste constante
			return { (aux.first - 1) * 9 + aux2.first, aux2.second }; 
		}
	}
}



bool noUnos(int n) {
	if (n < 10) return n != 1; 
	return n % 10 != 1 && noUnos(n / 10); 
}

bool resuelveCasos() {
	lli n = 0;
	std::cin >> n;
	if (!cin) return false; 
	else {		
		std::cout << sinUnos(n).first  << '\n';
		return true; 
	}
}


int main() {
	while (resuelveCasos());
	return 0;
}