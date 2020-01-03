
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,1,1,1,0,-1,-1,-1 };

char M[1000][1001];
int dist[1000][1000];


int bfs(int rs, int cs, int rd, int cd, int &R, int &C) {
	for (int i = 0; i < R; i++) fill(dist[i], dist[i] + C, -1);

	deque< pair<int, int> > Q;

	Q.push_back(make_pair(rs, cs));
	dist[rs][cs] = 0;

	pair<int, int> P;
	int r, c;

	while (true) {
		P = *(Q.begin());
		Q.pop_front();

		if (P.first == rd && P.second == cd) return dist[rd][cd];

		r = P.first + dr[M[P.first][P.second] - '0'];
		c = P.second + dc[M[P.first][P.second] - '0'];

		if (r >= 0 && r < R && c >= 0 && c < C && (dist[r][c] == -1 || dist[r][c] > dist[P.first][P.second])) {
			dist[r][c] = dist[P.first][P.second];
			Q.push_front(make_pair(r, c));
		}

		for (int i = 0; i < 8; i++) {
			r = P.first + dr[i];
			c = P.second + dc[i];

			if (r >= 0 && r < R && c >= 0 && c < C && (dist[r][c] == -1 || dist[r][c] > dist[P.first][P.second] + 1)) {
				dist[r][c] = dist[P.first][P.second] + 1;
				Q.push_back(make_pair(r, c));
			}
		}
	}
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int R, C;
	cin >> R >> C;
	if (!cin) return false;

	int m,rs,cs,rd,cd;

	for (int i = 0; i < R; i++) 
		cin >> M[i];

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> rs >> cs >> rd >> cd;
		cout << bfs(rs - 1, cs - 1, rd - 1, cd - 1, R, C) << '\n';
	}

	


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