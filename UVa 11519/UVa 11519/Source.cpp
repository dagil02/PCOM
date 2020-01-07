#pragma warning(disable:4996)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI(acos(-1.0));

int t, i, n, q;
char c[1001], buf[100];
int d[1001], sol;
double x, y, a, d1, d2;

double rad(double _) { return _ * PI / 180.0; }

void check(int id) {
	switch (c[id]) {
	case 'f':
		x += d[id] * cos(a);
		y += d[id] * sin(a);
		break;
	case 'b':
		x -= d[id] * cos(a);
		y -= d[id] * sin(a);
		break;
	case 'l':
		a += rad(d[id]);
		break;
	case 'r':
		a -= rad(d[id]);
	}
}
void makePoint() {
	a = x = y = 0.0;
	for (int i = 0; i < n; ++i){
		check(i);
	}
		
}


void resuelveCaso() {
	// leer los datos de la entrada
	cin >> n;

	for (i = 0; i < n; ++i) {
		cin >> buf;
		c[i] = buf[0];
		cin >> buf;
		if (buf[0] == '?')
			q = i;
		else
			sscanf(buf, "%d", d+i);
	}
	if (c[q] == 'f' || c[q] == 'b') {
		d[q] = 0;
		makePoint();
		sol = round(hypot(x, y));
		d[q] = sol;
		makePoint();
		d1 = hypot(x, y);
		d[q] = -sol;
		makePoint();
		d2 = hypot(x, y);
		if (d1 > d2) sol *= -1;
	}
	else {
		for (sol = 0; sol < 360; ++sol) {
			d[q] = sol;
			makePoint();
			if (abs(x) < 0.01 && abs(y) < 0.01) break;
		}
	}
	
	if (sol < 0) sol = -sol;

	// escribir sol
	cout << sol << '\n';

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