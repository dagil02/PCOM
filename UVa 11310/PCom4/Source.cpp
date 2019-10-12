


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
long long int resolver(int n, vector<long long int> &v) {
	
	if (v[n - 1] != -1)
		return v[n - 1];
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 5;
	else if (n == 3)
		return 11;

	else {
		long long int sol =resolver(n - 1, v) + 4 * resolver(n - 2, v) + 2 * resolver(n - 3, v); 
		v[n - 1] = sol;
		return sol;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int n;
	cin >> n;
	vector<long long int> v;
	for (int i = 0; i < 40; i++) {
		v.push_back(-1);
	}
	long long int sol = resolver(n,v);
	// escribir sol

	cout << sol << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}