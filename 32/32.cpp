#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

//Gonzalo Sánchez Montesinos
//DG29


pair<int, int> partitionin3(std::vector<pair<char, int>>& v) {
	int i = 0, k = 0, q = v.size() - 1; 
	while (k <= q) {
		if (v[k].first == 'v') ++k;
		else if (v[k].first == 'a') { //hay que intercambiarlo con v[i]
			pair<char, int> aux = v[i]; 
			v[i] = v[k]; 
			v[k] = aux; 
			++i;
			k = max(k, i); 
		}
		else { //if (v[k].first == 'r') 
			pair<char, int> aux = v[k];
			v[k] = v[q]; 
			v[q] = aux; 
			--q; 
		}
		/*
		if (v[q].first == 'r') --q; 
		else if (v[q].first == 'a') {
			pair<char, int> aux = v[i];
			v[i] = v[q]; 
			v[q] = aux; 
			--q; 
			++i; 
			k = max(k, i); 
		}
		else { //if( v[q].first == 'v' ) 
			pair<char, int> aux = v[k];
			v[k] = v[q]; 
			v[q] = aux; 
			++k; 
		}
		*/
		
	}
	return { i, k }; 
}

bool resuelveCasos() {
	int n; 
	std::cin >> n; 
	if (!cin) return false; 
	else {
		std::vector<pair<char, int>> v(n); 
		for (auto& x : v) std::cin >> x.first >> x.second; 
		pair<int,int> pq= partitionin3(v); 
		std::sort(v.begin(), v.begin() + pq.first); 
		std::sort(v.begin() + pq.first, v.begin() + pq.second); 
		std::sort(v.begin() + pq.second, v.end()); 
		std::cout << "Azules:"; 
		for (int i = 0; i < pq.first; ++i) {
			std::cout << " " << v[i].second; 
		}
		std::cout << '\n'; 
		std::cout << "Verdes:";
		for (int i = pq.first; i < pq.second; ++i) {
			std::cout << " " << v[i].second;
		}
		std::cout << '\n';
		std::cout << "Rojas:";
		for (int i = pq.second; i < v.size(); ++i) {
			std::cout << " " << v[i].second;
		}
		std::cout << '\n';
		return true; 
	}
}

int main() {
	while (resuelveCasos()); 
	return 0; 
}