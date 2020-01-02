
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int big_mod(int base, int power, int mod)
{
	if (power == 0) {
		if(mod > 1)  return 1;
		else return 0;
	}   
	else if (power % 2 == 1)
	{
		int p1 = base % mod;
		int p2 = (big_mod(base, power - 1, mod)) % mod;
		return (p1*p2) % mod;
	}
	else if (power % 2 == 0)
	{
		int p1 = (big_mod(base, power / 2, mod)) % mod;
		return (p1*p1) % mod;
	}
}


bool resuelveCaso() {
	// leer los datos de la entrada
	int b, p, m;
	cin >> b >> p >> m;
	if (!cin) return false;

	int sol = big_mod(b, p, m);

	// escribir sol
	cout << sol << '\n';

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