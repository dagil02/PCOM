

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
using pii = pair<int, int>;
using arista = pair<float, pair<int, int>>;

void init(int n, vector<int> &C,int &numSets) {
	C.assign(n, 0); numSets = n;
	for (int i = 0; i < n; i++) C[i] = i;
}

int find(int x, vector<int> &C) {
	return (C[x] == x) ? x : C[x] = find(C[x],C);
}

void merge(int x, int y, vector<int> &C, int &numSets) {
	C[find(x, C)] = find(y, C);
	--numSets;
}
float distancia(pii a, pii b) {
	return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
}

void resuelveCaso() {
	// leer los datos de la entrada
	vector<int> C;
	int numSets;
	vector <arista> aristas;
	vector<pii> posiciones;

	int sat, post;
	float max = 0;
	cin >> sat >> post;

	for (int i = 0; i < post; i++) {
		int x, y;
		cin >> x >> y;

		pii pos;
		pos.first = x; pos.second = y;

		posiciones.push_back(pos);
	}

	for (int i = 0; i < post; i++) {
		for (int j = i + 1; j < post; j++) {
			arista x;
			x.first = distancia(posiciones[i], posiciones[j]);
			x.second.first = i;
			x.second.second = j;
			aristas.push_back(x);
		}
	}


	sort(aristas.begin(), aristas.end());


	init(post, C, numSets);

	for (auto ar : aristas) {
		if (find(ar.second.first,C) != find(ar.second.second,C)) { 
			merge(ar.second.first, ar.second.second,C,numSets);
			max = ar.first;
		}
		if (numSets <= sat) break;
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