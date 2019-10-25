

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

int resuelve(int ini, int fin) {
	queue<pair<int, int>> v;
	vector <bool> done;
	done.assign(10000, false);
	if (ini == fin) return 0;
	v.push(make_pair(ini,0));

	
	while (true){
		pair<int, int> z = v.front();

		if (!done[z.first]) {
			
			
			int a = z.first + 1;
			if (a == 10000) a = 0;
			if (a == fin) return z.second+1;
			v.push(make_pair(a,z.second+1));
			

			int b = z.first * 2;
			if (b >= 10000) b -= 10000;
			if (b == fin)  return z.second+1;
			v.push(make_pair(b, z.second + 1));
			

			int c = z.first / 3;
			if (c == fin) return z.second+1;
			v.push(make_pair(c, z.second + 1));
			

			done[z.first] = true;
		}
		v.pop();
	}

}

bool resuelveCaso() {
	// leer los datos de la entrada
	int ini, fin;
	cin >> ini >> fin;
	if (!std::cin)
		return false;

	int sol = resuelve(ini, fin);

	// escribir sol
	cout << sol << '\n';

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