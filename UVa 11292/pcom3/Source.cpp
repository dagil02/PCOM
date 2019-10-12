// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int buscaJusto(int n, vector <int> &knights) {
	int sol = -1;
	if (n > knights[0])
		return -1;
	for (int i = 1; i < knights.size(); i++) {
		if (knights[i] < n) {
			sol = knights[i - 1];
			knights[i - 1] = 0;
			sort(knights.begin(), knights.end(), greater<int>());
			return sol; 
		}


	}

	sol = knights[knights.size() - 1];
	knights[knights.size() - 1] = 0;
	sort(knights.begin(), knights.end(), greater<int>());
	return sol;
}

// función que resuelve el problema
int resolver(int n, int m) {
	
	
	
	int sol = 0;
	vector <int> dragons;
	vector <int> knights;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		dragons.push_back(x);
	}
	sort(dragons.begin(),dragons.end(),greater<int>());
	
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		knights.push_back(x);
	}

	sort(knights.begin(), knights.end(), greater<int>());



	if (n > m) return -1;


	for (int i = 0; i < n; i++) {
		int x = buscaJusto(dragons[i], knights);
		if (x == -1) return -1;
		else sol += x;
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m;
	cin >> n >> m;
	if (n == 0 && m == 0)
		return false;

	int sol = resolver(n,m);

	// escribir sol
	if (sol == -1) cout << "Loowater is doomed!" << '\n';
	else cout << sol << '\n';
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
