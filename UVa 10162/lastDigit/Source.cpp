
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int a[201], x;

int pot(int b, int e) {
	if (e == 0) return 1;
	int mid = pot(b, e >> 1);
	mid = (mid*mid) % 10;
	if (e & 1) return (mid*b) % 10;
	return mid;
}

bool resuelveCaso() {
	// leer los datos de la entrada
	
	string s;

	cin >> s;

	if (s=="0") return false;

	if (s.size() > 3) s = s.substr(s.size() - 3);
	istringstream(s) >> x;
	cout << a[x % 200] << '\n';

	

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i < 201; ++i) {
		a[i] = (a[i - 1] + pot(i, i)) % 10;
	}

	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
