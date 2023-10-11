#include <iostream>
#include <string>
#include <vector>
using namespace std; 

using lli = long long int; 

std::ostream& operator << (std::ostream& op, std::vector<lli>& v) {
	op << v.size() << '\n'; 
	if (v.size() > 0) {
		op << v[0]; 
		for (int i = 1; i < v.size(); ++i) {
			op << " " << v[i]; 
		}
	}
	return op; 
}

void resolver(std::vector<lli>& v, const lli& err)  {
	int cont = 0; 
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] != err) {
			v[cont] = v[i]; 
			++cont; 
		}
	}
	v.resize(cont); 
}


void resuelveCasos() {
	int tam = 0; 
	std::cin >> tam; 
	lli err; 
	std::cin >> err; 
	std::vector<lli> v(tam); 
	for (auto& x : v) std::cin >> x; 
	resolver(v, err); 
	std::cout << v << '\n'; 
}

int main()  {
	int number_of_cases = 0; 
	std::cin >> number_of_cases; 
	for (int i = 0; i < number_of_cases; ++i) resuelveCasos(); 
	return 0; 
}