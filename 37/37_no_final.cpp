#include <iostream>
#include <vector>
using namespace std;
//Gonzalo Sánchez Montesinos
//DG29


/*
//No final: 
int f(int n) {
	if (n < 10 && n % 2 == 0) return n + 1;
	else if (n < 10 && n % 2 == 1)  return n - 1; 
	else {
		if (n % 2 == 0) {
			return n % 10 + 1 + 10 * f(n / 10); 
		}
		else {
			return n % 10 - 1 + 10 * f(n / 10);

		}
	}
}

void resuelveCasos() {
	int n;
	std::cin >> n;
	std::cout << f(n) << '\n'; 
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCasos();
	return 0;
}

*/