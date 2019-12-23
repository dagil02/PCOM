
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


bool resuelveCaso(int caso) {
	// leer los datos de la entrada
	int z, i, m, l;
	cin >> z >> i >> m >> l;
	if (z == 0 && i == 0 && m == 0 & l == 0) return false;

	vector<int> v;
	v.assign(10000, 0);

	int count = 0;
	

	while (!v[l])
	{
		v[l] = ++count;
		l = (z*l + i) % m;
	}

	// escribir sol

	cout << "Case " << caso << ": " << count - v[l] + 1 << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int caso = 1;
	while (resuelveCaso(caso))caso++;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
