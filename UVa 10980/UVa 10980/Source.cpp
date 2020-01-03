
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

typedef pair <int, double> venta;

bool resuelveCaso(int numCase) {
	// leer los datos de la entrada
	int n;
	double precioUni;

	cin >> precioUni >> n;

	if (!cin) return false;
	vector<venta> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	

	vector<double> minP(101, 0);
	
	for (int k = 1; k <= 100; ++k)
		minP[k] = precioUni * k;
	for (int i = 0; i < n; ++i)
	{
		int n = v[i].first;
		double p = v[i].second;
		for (int k = 0; k <= 100 - n; ++k)
			for (int m = 1; m <= n; ++m)
				minP[k + m] = min(minP[k + m], minP[k] + p);
	}

	// escribir sol
	cin.ignore();

	string s;
	int K;
	getline(cin, s);
	stringstream ss(s);
	cout << "Case " << numCase << ":\n";
	while (ss >> K)
	{
		cout << "Buy "
			<< K
			<< " for $"
			<< setprecision(2)
			<< fixed
			<< minP[K]
			<< '\n';
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

	int numCase = 1;
	while (resuelveCaso(numCase)) numCase++
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}


