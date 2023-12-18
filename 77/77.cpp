#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; 

//Gonzalo S�nchez Montesinos
//DG29


/*
�rbol de exploraci�n: 
	Ramas: IDA (incluir la canci�n en el viaje de ida)  VUELTA: (incluir la canci�n en el viaje de vuelta) NO (NO incluir la canci�n ni en el viaje de ida ni en el de vuelta)
	Altura: canciones

Vector soluci�n: 
	�ndices: canciones
	Contenido: v[i]= 0 si la i-�sima canci�n no se coge, v[i] = 1 si se coge para la ida v[i] = 2 si se coge para la vuelta

Estimaci�n: 
	La primera soluci�n a la que se llega es la soluci�n voraz, luego se van a podar muchas ramas posteriormente.
	La estimaci�n es como la del problema de la mochila. En este caso, se suman los tiempos de ida y de vuelta y se va intentando
	llenar los tiempos. 
	La estimaci�n se hace en el NO. 
*/



struct tDato {
	int tiempo; 
	int satis; 
};

//Operadores
std::istream& operator >> (std::istream& op, tDato& d) {
	op >> d.tiempo >> d.satis; 
	return op; 
}

class comparador {
public : 
	bool operator() (const tDato& a, const tDato& b) {
		return (float)a.satis / a.tiempo > (float)b.satis / b.tiempo; 
	}
};

int estimar(const std::vector<tDato>& v, const int n, const int k, const std::vector<int>& sol, const int satisActual, const int& satisMax,const int tiempoIda, const int tiempoVuelta, const int tiempoActualIda, const int tiempoActualVuelta) {
	int i = k + 1; 
	int sumaSatis = satisActual; 
	int sumaTiempo = tiempoActualIda + tiempoActualVuelta; 

	while (i < v.size() && sumaTiempo < tiempoIda + tiempoVuelta) {
		sumaTiempo += v[i].tiempo; 
		sumaSatis += v[i].satis; 
		++i; 
	}

	return sumaSatis; 
}

void VA(const std::vector<tDato>& v, int n, int k, std::vector<int>& sol, int satisActual, int& satisMax, int tiempoIda, int tiempoVuelta, int tiempoActualIda, int tiempoActualVuelta) {
	//Primero se coge la canci�n para la ida: 
	sol[k] = 1; 
	//Se actualizan los tiempos y las satisfacciones (se marca): 
	tiempoActualIda += v[k].tiempo; 
	satisActual += v[k].satis; 

	//Se comprueba si la soluci�n es v�lida: 
	if (tiempoActualIda <= tiempoIda) {
		if (k == n - 1) {
			if (satisMax < satisActual && tiempoIda == tiempoActualIda && tiempoVuelta == tiempoActualVuelta) satisMax = satisActual;
		}
		else VA(v, n, k + 1, sol, satisActual, satisMax, tiempoIda, tiempoVuelta, tiempoActualIda, tiempoActualVuelta); 
	}

	//Se desmarca: 
	tiempoActualIda -= v[k].tiempo;
	satisActual -= v[k].satis;
	
	/*..........................................................................................*/

	//Ahora se coge la canci�n para la vuelta: 
	sol[k] = 2;
	//Se actualizan los tiempos y las satisfacciones (se marca): 
	tiempoActualVuelta += v[k].tiempo;
	satisActual += v[k].satis;

	//Se comprueba si la soluci�n es v�lida: 
	if (tiempoActualVuelta <= tiempoVuelta) {
		if (k == n - 1) {
			if (satisMax < satisActual && tiempoIda == tiempoActualIda && tiempoVuelta == tiempoActualVuelta) satisMax = satisActual;
		}
		else VA(v, n, k + 1, sol, satisActual, satisMax, tiempoIda, tiempoVuelta, tiempoActualIda, tiempoActualVuelta);
	}

	//Se desmarca: 
	tiempoActualVuelta -= v[k].tiempo;
	satisActual -= v[k].satis;

	/*..........................................................................................*/

	//Ahora no se coge la canci�n: 
	sol[k] = 2;
	if (k == n - 1) {
		if (satisMax < satisActual && tiempoIda == tiempoActualIda && tiempoVuelta == tiempoActualVuelta) satisMax = satisActual;
	}
	else if (estimar(v, n, k, sol, satisActual, satisMax, tiempoIda, tiempoVuelta, tiempoActualIda, tiempoActualVuelta) >=  satisMax) VA(v, n, k + 1, sol, satisActual, satisMax, tiempoIda, tiempoVuelta, tiempoActualIda, tiempoActualVuelta);
	//else VA(v, n, k + 1, sol, satisActual, satisMax, tiempoIda, tiempoVuelta, tiempoActualIda, tiempoActualVuelta);
}


bool resuelveCasos() {
	int n, t1, t2; 
	std::cin >> n >> t1 >> t2; 
	if (n == 0 && t1 == 0 && t2 == 0) return false;
	else {
		std::vector<tDato> v(n); 
		for (auto& x : v) std::cin >> x; 

		std::sort(v.begin(), v.end(), comparador()); //Ordenar para que se haga primero la soluci�n voraz

		int satisMax = -1; 
		std::vector<int> sol(n,0);

		VA(v, n, 0, sol, 0, satisMax, t1, t2, 0, 0); 
		if (satisMax == -1) std::cout << "Imposible\n";
		else std::cout << satisMax << '\n'; 



		return true; 
	}
}



int main() {
	while (resuelveCasos()); 
	return 0; 
}