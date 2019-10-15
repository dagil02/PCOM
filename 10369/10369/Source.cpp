

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
using pii = pair<int, int>;
using arista = pair<float, pair<int, int>>;


float distancia(pii a, pii b) {
	return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
}

void resuelveCaso() {
	// leer los datos de la entrada
	vector <bool> bases;
	vector <arista> aristas;
	vector<pii> posiciones;

	int sat, post;
	float max = 0;
	cin >> sat >> post;

	int rest = post;

	bases.assign(post, false);

	for (int i = 0; i < post; i++) {
		int x, y;
		cin >> x >> y;

		pii pos;
		pos.first = x; pos.second = y;

		posiciones.push_back(pos);
	}

	for (int i = 0; i < post; i++) {
		for (int j = i+1; j < post; j++) {
			arista x;
			x.first = distancia(posiciones[i], posiciones[j]);
			x.second.first = i;
			x.second.second = j;
			aristas.push_back(x);
		}
	}


	sort(aristas.begin(), aristas.end());

	int it = 0;
	while (rest > 0)
	{
		if (!bases[aristas[it].second.first] || !bases[aristas[it].second.second]) {
			if (!bases[aristas[it].second.first]) {
				bases[aristas[it].second.first] = true;
				rest--;
			}

			if (!bases[aristas[it].second.second]) {
				bases[aristas[it].second.second] = true;
				rest--;
			}
			max = aristas[it].first;
		}
		
		it++;
	}

	printf("%.2f\n",max);

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