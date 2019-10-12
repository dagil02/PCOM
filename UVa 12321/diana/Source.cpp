

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;


pair <int, int> pii[10000];

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int l, g, x, r;

	cin >> l >> g;
	if (l == 0 && g == 0)
		return false;

	for (int i = 0; i < g; i++) {
		cin >> x >> r;
		pii[i] = make_pair(x - r, x + r);
	}
	
	sort(pii, pii + g);

	int pos = 0, aux = 0, n = 0, sol = g;

	while (pos < l) {
		aux = pos;
		while (n < g && pii[n].first <= pos) {
			aux = max(aux, pii[n++].second);
		}

		if (aux == pos) break;

		pos = aux;

		sol--;
	}
	// escribir sol
	cout << (pos < l ? -1 : sol) << '\n';

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