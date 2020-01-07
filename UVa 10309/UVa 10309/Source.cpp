
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream> 

using namespace std;


char g[15][15];
int ng[15][15], sol;
void press(int x, int y) {
	ng[x][y] = !ng[x][y];
	if (x - 1 >= 0)    
		ng[x - 1][y] = !ng[x - 1][y];
	if (x + 1 < 10)    
		ng[x + 1][y] = !ng[x + 1][y];
	if (y - 1 >= 0)    
		ng[x][y - 1] = !ng[x][y - 1];
	if (y + 1 < 10)    
		ng[x][y + 1] = !ng[x][y + 1];
}
void dfs(int x, int y, int n) {
	if (y == 10)  x++, y = 0;
	if (n >= sol) return;
	if (x == 0) {
		dfs(x, y + 1, n);
		press(x, y);
		dfs(x, y + 1, n + 1);
		press(x, y);
	}
	else if (x < 10) {
		if (ng[x - 1][y] == 1) {
			press(x, y);
			dfs(x, y + 1, n + 1);
			press(x, y);
		}
		else
			dfs(x, y + 1, n);
	}
	else {
		int i;
		for (i = 0; i < 10; i++)
			if (ng[x - 1][i])
				return;
		if (n < sol)  sol = n;
	}
}

bool resuelveCaso() {
	// leer los datos de la entrada
	string s;
	cin >> s;
	if (s=="end") return false;

	for (int i = 0; i < 10; i++)
		cin >> g[i];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ng[i][j] = g[i][j] == 'O';
		}
	}
	sol = 10000;
	dfs(0, 0, 0);
	

	// escribir sol
	cout << s << " " << sol << '\n';
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
