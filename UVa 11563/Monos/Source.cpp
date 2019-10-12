

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct  dato
{
	int id, sig;

	dato() {}
	dato(int i, int s) {
		id = i; sig = s;
	}

	bool operator < (dato x)const {
		return sig < x.sig;
	}
}aux;


bool resuelveCaso() {
	vector<int> v;
	vector <int> ult;
	vector <int> sig;
	vector <bool> cache;
	
	// leer los datos de la entrada
	int c, n, a,dentro = 0, lecturas = 0;
	priority_queue<dato> pq;
	cin >> c >> n >> a;
	if (!std::cin)
		return false;

	cache.assign(n,false);
	ult.assign(n,a);
	sig.assign(a, 0);

	for (int i = 0; i < a; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = a - 1; i >= 0; i--) {
		sig[i] = ult[v[i]];
		ult[v[i]] = i;
	}
	
	for (int i = 0, x; i < a; ++i) {

		x = v[i];

		if (!cache[x]) {
			cache[x] = true;
			lecturas++;

			if (dentro < c) dentro++;
			else {
				aux = pq.top();
				pq.pop();
				cache[aux.id] = false;
			}
		}

		pq.push(dato(x, sig[i]));
	}
	
	// escribir sol
	cout << lecturas << '\n';

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