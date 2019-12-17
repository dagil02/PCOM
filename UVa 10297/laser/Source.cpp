#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <map>
#include <math.h>

const double PI = acos(-1);

using namespace std;

using T = int;

struct pt {
	T x, y,z;

	bool operator<(const pt& p)const {
		
		long long int sol  = (long long int)x * x + (long long int)y*y < (long long int)p.x*p.x + (long long int)p.y*p.y;
		return sol;
		
	}

};

int mcd(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	int aux;
	while (a) {
		aux = a;
		a = b % a;
		b = aux;
	}
	return b;
}

bool compara(const pt& a, const pt& b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool resuelveCaso(int cont) {
	// leer los datos de la entrada
	int n;
	cin >> n;

	if (n==0) return false;

	map< pair<int, int>, int > poles;
	vector<pt>v, sol;
	pt ini;
	v.assign(n, ini);

	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y >> v[i].z;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {
		
		int div = mcd(v[i].x, v[i].y);
		pair<int, int> pr(v[i].x / div, v[i].y / div);
		if (poles.count(pr)) {
			int& r = poles[pr];
			
			if (r >= v[i].z) sol.push_back(v[i]);
			r = max(r, v[i].z);
		}
		else {
			poles[pr] = v[i].z;
		}
	}
	
	// escribir sol
	cout << "Data set " << cont << ":\n";
	if (sol.empty()) {
		cout << "All the lights are visible." << endl;
	}
	else {
		cout << "Some lights are not visible:" << endl;
		sort(sol.begin(), sol.end(), compara);
		for (int i = 0; i < sol.size(); ++i) {
			cout << "x = " << sol[i].x << ", y = " << sol[i].y;
			if (i + 1 < sol.size()) cout << ';';
			else cout << '.';
			cout << endl;
		}
	}

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int cont = 1;
	while (resuelveCaso(cont)) cont++
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
