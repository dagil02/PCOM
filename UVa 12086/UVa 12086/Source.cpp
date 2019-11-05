
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
		while (pos < ft.size()) {
			ft[pos] += val;
			pos += (pos & -pos);
		}
	}

	int getSum(int a, int b) {
		return getSum(b) - getSum(a - 1);
	}

	int getValue(int pos) {
		return getSum(pos) - getSum(pos - 1);
	}

	void setValue(int pos, int val) {
		add(pos, val - getValue(pos));
	}
};



bool resuelveCaso(int num) {
	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N == 0) return false;
	FenwickTree fen = FenwickTree(N);
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		fen.setValue(i, x);
	}

	string s;
	cin >> s;

	cout << "Case " << num << ":" << '\n';

	while (s != "END")
	{
		if (s == "S") {
			int pos, num;
			cin >> pos >> num;
			fen.setValue(pos, num);
		} if (s == "M") {
			int pri, ult;
			cin >> pri >> ult;
			int sol = fen.getSum(pri, ult);
			cout << sol << '\n';
		}

		cin >> s;
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

	int n = 1;
	while (resuelveCaso(n))
		n++;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
