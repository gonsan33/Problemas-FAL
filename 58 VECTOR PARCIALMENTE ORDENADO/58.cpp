#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

struct tD {
	int max, min;
	bool sol;
	tD(int ma, int mi, bool so) {
		this->max = ma; 
		this->min = mi; 
		this->sol = so; 
	}
};

tD resolver(const std::vector<int>& v, int ini, int fin) {
	if (ini + 1 == fin) return tD(v[ini], v[ini], true); 
	else {
		int mitad = (ini + fin - 1) / 2; 
		tD a = resolver(v, ini, mitad + 1);
		tD b = tD(INT_MAX, INT_MAX, false); 
		if (a.sol) {
			b = resolver(v, mitad + 1, fin); 
		}
		return tD(min(a.min, b.min), max(a.max, b.max), a.min <= b.min && a.max <= b.max && a.sol && b.sol);
	}
}

bool resuelveCasos() {
	std::vector<int> v(0); 
	int n,m; 
	std::cin >> n;
	if (n == 0) return false; 
	while (n != 0) {
		v.push_back(n);
		std::cin >> n;
	}

	if (resolver(v, 0, v.size()).sol) std::cout << "SI\n";
	else std::cout << "NO\n"; 
	return true; 
}


int main() {
	while (resuelveCasos());
	return 0; 
}