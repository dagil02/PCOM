
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>


#define MAX 306

using namespace std;


int X[MAX], Y[MAX], P[MAX], G[MAX][MAX], n, r, a, b;
bool V[MAX];

bool team(int c) {
	return (X[b] - X[a])*(Y[c] - Y[a]) - (Y[b] - Y[a])*(X[c] - X[a]) > 0;
}

int sqrdist(int a, int b) {
	return (X[a] - X[b])*(X[a] - X[b]) + (Y[a] - Y[b])*(Y[a] - Y[b]);
}

int send(int s, int t, int minn) {
	V[s] = true;

	if (s == t) return minn;
	for (int i = 0; i <= n; i++) {
		if (!V[i] && G[s][i] > 0) {
			if (int sent = send(i, t, min(minn, G[s][i]))) {
				G[s][i] -= sent;
				G[i][s] += sent;
				return sent;
			}
		}
	}
	return 0;
}


bool resuelveCaso(int caso) {
	// leer los datos de la entrada
	cin >> n;

	if (n==0) return false;

	memset(G, 0, sizeof(G));

	for (int i = 1; i <= n; i++)
		cin >> X[i] >> Y[i] >> P[i];
	cin >> a >> b >> r;

	vector<int> A, B;
	for (int i = 1; i <= n; i++) {
		if (P[i] == 0) continue;
		if (team(i))
			B.push_back(i);
		else
			A.push_back(i);
	}
	if (A.size() > B.size()) A.swap(B);

	for (int i = 0; i < A.size(); i++) {
		int u = A[i];
		G[0][u] = 1;
		for (int j = 0; j < B.size(); j++) {
			int v = B[j];
			G[v][n + 1] = 1;
			if (sqrdist(u, v) <= r * r && P[u] > P[v])
				G[u][v] = 1;
		}
	}
	n++;

	memset(V, 0, sizeof(V));
	int total = 0;
	while (int sent = send(0, n, INT_MAX)) {
		total += sent;
		memset(V, 0, sizeof(V));
	}
	


	// escribir sol
	cout << "Case " << caso << ": " << total << '\n';


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
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
