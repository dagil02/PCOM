
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct Pt {
	int x, y;
	Pt(int a = 0, int b = 0) :
		x(a), y(b) {}
	bool operator<(const Pt &p) const {
		if (p.x != x)
			return x < p.x;
		return y < p.y;
	}
};
bool cmp(Pt a, Pt b) {
	if (a.y != b.y)
		return a.y < b.y;
	return a.x < b.x;
}
Pt tree[3000];

void resuelveCaso() {
	int h, w;
	int x, y, dx = 0, dy = 0;
	cin >> h >> w;
	int op, i, j;
	int n = 0;
	tree[n++] = Pt(0, 0);
	tree[n++] = Pt(h, w);
	tree[n++] = Pt(h, 0);
	tree[n++] = Pt(0, w);
	cin >> op;
	while (op != 0) {
		cin >> x >> y;
		if (op != 1)
			cin >> dx >> dy;

		for (i = 0; i < op; i++) {
			tree[n++] = Pt(x, y);
			x += dx, y += dy;
		}
		cin >> op;
	}
	sort(tree, tree + n);
	int area = 0;
	for (i = 0; i < n; i++) {
		int mny = 0, mxy = w;
		for (j = i + 1; j < n; j++) {
			area = max(area, (tree[j].x - tree[i].x)*(mxy - mny));
			if (tree[j].x == tree[i].x)
				continue;
			if (tree[j].y > tree[i].y)
				mxy = min(mxy, tree[j].y);
			else
				mny = max(mny, tree[j].y);
		}
	}
	sort(tree, tree + n, cmp);
	for (i = 0; i < n; i++) {
		int mnx = 0, mxx = h;
		for (j = i + 1; j < n; j++) {
			area = max(area, (tree[j].y - tree[i].y)*(mxx - mnx));
			if (tree[j].y == tree[i].y)
				continue;
			if (tree[j].x > tree[i].x)
				mxx = min(mxx, tree[j].x);
			else
				mnx = max(mnx, tree[j].x);
		}
	}
	cout << area << '\n';


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}