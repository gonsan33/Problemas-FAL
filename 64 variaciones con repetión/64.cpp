//DG29
//Gonzalo S�nchez Montesinos

#include <iostream>
#include <vector>
using namespace std;



std::ostream& operator << (std::ostream& op, const std::vector<char>& v) {
	for (auto& x : v) op << x;
	return op;
}

void va(int m, int n, int k, std::vector<char>& sol) {
	for (int i = 'a'; i < 'a' + m; ++i) {
		sol[k] = i;
		
		if (n - 1 == k)	std::cout << sol << '\n';
		else va(m, n, k + 1, sol);
		
	}
}


bool resuelveCasos() {
	int m, n;
	std::cin >> m;
	if (!cin) return false;
	cin >> n;
	std::vector<char> sol(n);
	va(m, n, 0, sol);
	return true;
}



int main() {
	while (resuelveCasos());
	return 0;
}