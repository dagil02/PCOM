
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;



bool resuelveCaso() {
	// leer los datos de la entrada
	int a, b;
	cin >> a >> b;

	if (a == 0 && b == 0) return false;

	unsigned long long int sol = 1;

	if (b > (a / 2)) b = a - b;

	for (int i = 0; i < b; i++) {
		sol *= (a - i);
		sol /= (1 + i);
	}

	// escribir sol

	cout << sol<< '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
