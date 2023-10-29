#include <iostream>
#include <vector>
using namespace std;
//Gonzalo Sánchez Montesinos
//DG29



//Final: 
int f(int n, int suma, int pot) {
	if (n < 10 && n % 2 == 0) return (n + 1) * pot + suma;
	else if (n < 10 && n % 2 == 1)  return (n - 1) * pot + suma;
	else {
		if (n % 2 == 0) 
			return f(n / 10, suma + (n % 10 + 1) * pot, pot * 10); 
		
		else
			return f(n / 10, suma + (n % 10 - 1) * pot, pot * 10);

	}
}


void resuelveCasos() {
	int n;
	std::cin >> n;
	std::cout << f(n,0,1) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCasos();
	return 0;
}