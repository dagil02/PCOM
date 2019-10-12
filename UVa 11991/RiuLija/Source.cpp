
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map> 
#include <vector>


using namespace std;


struct num {

	int n;
	vector<int> pos;

	bool operator<(const num & other) const
	{
		return n < other.n;
	}

	num(int n) : n(n) {}
};

bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m;
	cin >> n >> m;
	if (!std::cin)
		return false;

	map<int, num> nmap;
	map<int, num>::iterator iter;

	int x;

	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		if ((iter = nmap.find(x)) == nmap.end())
			iter = nmap.insert(pair<int, num>(x, num(x))).first;

		iter->second.pos.push_back(i);
	}

	int p;
	while (m--)
	{
		cin >> p >> x;
		p--;
		iter = nmap.find(x);

		if (iter == nmap.end() || iter->second.pos.size() <= p)
			cout << "0\n";
		else
			cout << iter->second.pos[p] << '\n';
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