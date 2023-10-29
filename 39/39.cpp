#include <iostream>
#include <vector>
using namespace std;
//Gonzalo Sánchez Montesinos
//DG29



//NO Final: 
int f(int n) {
	if (n < 10) return 9 - n; 
	else {
		return 9 - (n % 10) + 10 * f(n / 10); 
	}
}

int fi(int n, int acum) {
	if (n < 10) return 9 - n + 10  * acum;
	else {
		return fi(n/10, 9 - n% 10 + 10 * acum);
	}
}


void resuelveCasos() {
	int n;
	std::cin >> n;
	std::cout << f(n) << " " << fi(n, 0) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCasos();
	return 0;
}