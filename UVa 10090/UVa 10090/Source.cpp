
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


long long mcd(long long x, long long y, long long &a, long long &b) {
	
	int flag = 0;
	long long t, la = 1, lb = 0, ra = 0, rb = 1;
	while (x%y) {
		if (flag == 0)
			la -= x / y * ra, lb -= x / y * rb;
		else
			ra -= x / y * la, rb -= x / y * lb;
		t = x, x = y, y = t % y;
		flag = 1 - flag;
	}
	if (flag == 0)
		a = ra, b = rb;
	else
		a = la, b = lb;
	return y;
}

bool resuelveCaso() {
	// leer los datos de la entrada
	long long n,c1,n1,c2,n2;
	cin >> n;

	if (n == 0) return false;

	cin >> c1 >> n1 >> c2 >> n2;

	long long a, b, g;

	g = mcd(n1, n2, a, b);

	if (n%g) {
		cout << "failed\n";
		return true;
	}
	
	long long k = n / g, k1, k2;
	
	a *= k, b *= k;
	
	k1 = n1 * n2 / g / n1, k2 = n1 * n2 / g / n2;
	
	if (a < 0) { 
		k = -(a / k1) + (a%k1 != 0);
		a += k * k1, b -= k * k2;
	}
	
	if (b < 0) { 
		k = -(b / k2) + (b%k2 != 0);
		a -= k * k1, b += k * k2;
	}
	
	if (a < 0 || b < 0) {
		cout << "failed\n";
		return true;
	}
	
	long long x1, x2, y1, y2;
	
	k = a / k1;
	a -= k * k1;
	b += k * k2;
	x1 = a, y1 = b;
	
	k = b / k2;
	a += k * k1;
	b -= k * k2;
	x2 = a, y2 = b;
	

	// escribir sol

	if (x1*c1 + y1 * c2 < x2*c1 + y2 * c2)
	
		cout << x1 << " " << y1 << '\n';
	else
		cout << x2 << " " << y2 << '\n';

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
