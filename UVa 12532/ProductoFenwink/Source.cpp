#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class FenwickTree {
	vector<int> ft;
public:
	FenwickTree(int n) { ft.assign(n + 1, 0); }
	int getSum(int b) {
		int ret = 0;
		while (b) {
			ret *= ft[b];
			b -= (b & -b);
		}
		return ret;
	}

	void add(int pos, int val) {
		while (pos < ft.size()) {
			ft[pos] += val;
			pos += (pos & -pos);
		}
	}

	long long int getSum(int a, int b) {
		long long int x = 1;
		for (int i = a; i <= b; i++) { 
			x *= ft[i]; 
			if (x == 0) return 0;
			else if (x > 0) x = 1;
			else x = -1;
		}

		return x;
	}

	int getValue(int pos) {
		return getSum(pos) - getSum(pos - 1);
	}

	void setValue(int pos, int val) {
		ft[pos] = val;
	}
};



bool resuelveCaso() {
	// leer los datos de la entrada
	int N,K;
	cin >> N >> K;
	if (!cin) return false;
	FenwickTree fen = FenwickTree(N);
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		fen.setValue(i, x);
	}

	for (int i = 0; i < K; i++) {
		string s;
		cin >> s;
		if (s == "C") {
			int x, y;
			cin >> x >> y;
			fen.setValue(x, y);
		}
		else if (s == "P"){
			int x, y;
			cin >> x >> y;
			long long int sol = fen.getSum(x, y);
			if (sol == 0) cout << 0;
			else if (sol > 0) cout << "+";
			else cout << "-";
		}
	}

	cout << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	
	while (resuelveCaso());
		


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}