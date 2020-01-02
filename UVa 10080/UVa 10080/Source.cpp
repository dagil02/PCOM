
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

typedef vector<int> vi;

vi match, vis; 
vector<vi> AdjList;

int Aug(int l) { 
	if (vis[l])
		return 0; 
	vis[l] = 1;
	for (int j = 0; j < (int)AdjList[l].size(); j++) {
		int r = AdjList[l][j];
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1; 
		}
	}
	return 0; 
}

double gx[105], gy[105], hx[105], hy[105];

double dist(int g, int h) {
	return sqrt(
		(gx[g] - hx[h]) * (gx[g] - hx[h])
		+ (gy[g] - hy[h]) * (gy[g] - hy[h]));
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m, s, v;
	int der, izq;
	cin >> n >> m >> s >> v;

	if (!cin) return false;

	der = n + m;
	izq = n;

	AdjList.assign(der, vi());


	for (int i = 0; i < n; i++) {
		cin >> gx[i] >> gy[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> hx[i] >> hy[i];
	}

	for (int g = 0; g < n; g++) {
		for (int h = 0; h < m; h++) {
			if (s >= (dist(g, h) / (double)v))
				AdjList[g].push_back(n + h);
		}
	}

	int MCBM = 0;
	match.assign(der, -1);

	for (int l = 0; l < izq; l++) {
		vis.assign(izq, 0);
		MCBM += Aug(l);
	}

	// escribir sol

	cout << n - MCBM << '\n';


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}