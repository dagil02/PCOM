
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

char s[1024];

bool resuelveCaso() {
	// leer los datos de la entrada
	cin >> s;

	if (!cin) return false;

	int n = strlen(s);
	int ceros = 0, unos = 0, mod = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			continue;
		ceros++;
		if (s[(i + 1) % n] == '0') mod++;
	}
	
	// escribir sol
	if (mod * n == ceros * ceros)
		cout << "EQUAL\n";
	else if (mod * n > ceros * ceros)
		cout << "SHOOT\n";
	else
		cout << "ROTATE\n";


	


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