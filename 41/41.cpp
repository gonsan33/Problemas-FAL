//GONZALO SÁNCHEZ MONTESINOS
//DG29

#include <iostream>
#include <vector>
using namespace std; 

pair<bool, int> interesante(int n, int sumapos) { //El int que devuelve es la sumapre
	if (n < 10) return { n != 0 && sumapos % n == 0, n };
	else {
		pair<bool, int> aux = interesante(n / 10, sumapos + n % 10); 
		return { n%10 != 0 && sumapos % (n%10) == 0 && aux.second % (n%10) == 0 && aux.first, aux.second + n % 10 }; 
	}

}


pair<bool,int> interesante(int n) { //Solo para que quede bonito
	return interesante(n, 0); 
}


void resuelveCasos() {
	int n; 
	std::cin >> n;
	if (interesante(n).first) std::cout << "SI\n";
	else std::cout << "NO\n"; 
}


int main() {
	int n; 
	std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCasos(); 
	return 0; 
}



//Coste: 

/*
sea n el número de dígitos 
Se considera la recurrencia siguiente 
T(n) = C1 si n = 1
T(n) = T(n-1) + C2 si n> 1

Haciendo el desplegado: 
T(n) = 15 + T(n-1) = ... = C1 + (n-1) * C2 = C2*n + (C1-C2)
Luego es O(n)

*/