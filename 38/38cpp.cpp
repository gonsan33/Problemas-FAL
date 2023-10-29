#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Gonzalo Sánchez Montesinos
//DG29



//NO Final: 
string conversor(int num) {
	if (num == 0) return "0";
	else if (num == 1) return "1"; 
	else {
		return  conversor(num / 2) + to_string(num % 2) ;
	}
}

void resuelveCasos() {
	int n;
	std::cin >> n;
	std::cout << conversor(n) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCasos();
	return 0;
}