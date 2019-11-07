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
			ret += ft[b];
			b -= (b & -b);
		}
		return ret;
	}

	void add(int pos, int val) {
		while (pos <= ft.size()) {
			ft[pos] += val;
			pos += (pos & -pos);
		}
	}

	void add(int a, int b, int val) {
		add(a, val);
		add(b + 1, -val);
	}

	int getSum(int a, int b) {
		return getSum(b) - getSum(a - 1);
	}

	int getValue(int pos) {
		return getSum(pos);
	}

	void setValue(int pos, int val) {
		add(pos, val - getValue(pos));
	}
};



bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n == 0) return false;
	FenwickTree f = FenwickTree(100000);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "B") {
			int a, b, y;
			cin >> a >> b >> y;
			f.add(a, b, y);
		}
		else {
			int x;
			cin >> x;
			cout << f.getValue(x) << '\n';

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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
