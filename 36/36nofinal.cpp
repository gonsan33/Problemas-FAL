#include <iostream>
#include <vector>
using namespace std;
//Gonzalo Sánchez Montesinos
//DG29
/*
std::ostream& operator <<(std::ostream& op, const std::vector<int>& v) {
	if (v.size() > 0) {
		op << v[0]; 
		for (int i = 1; i < v.size(); ++i) {
			op << " " << v[i]; 
		}
	}
	return op; 
}

//No final: 
int sumaDigitos(int n) {
	if (n < 10) return n; 
	else return n % 10 + sumaDigitos(n / 10); 

}

void resuelveCasos() {
	int n; 
	std::cin >> n; 
	int num; 
	std::cin >> num; 
	std::vector<int> v(n); 
	for (int& x : v) std::cin >> x; 

	int suma = sumaDigitos(num); 
	std::vector<int> sol(0); 
	for (int i = 0; i < v.size(); ++i) {
		if(sumaDigitos(v[i]) == suma) sol.push_back(v[i]); 
	}
	std::cout << sol << '\n'; 
}

int main() {
	int n; 
	std::cin >> n; 
	for (int i = 0; i < n; ++i) resuelveCasos(); 
	return 0; 
}
*/