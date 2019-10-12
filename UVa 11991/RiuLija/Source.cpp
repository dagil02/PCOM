// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
//#include <iomanip>
#include <fstream>
#include <vector>



using namespace std;

// función que resuelve el problema
void resolver(int n, int m) {
	vector< vector<int> > v = vector< vector<int> >(1000001, vector<int>(0));

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int num, pos;
		cin >> pos >> num;
		if (v[num].size() < pos) cout<< 0 <<'\n';
		else cout << v[num][pos - 1] << '\n';
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m;
	cin >> n >> m;
	if (!std::cin)
		return false;

	resolver(n,m);

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