

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void resuelve(const vector <int> &secs, vector <int> sol, int n, int restante,int suma,int &solution, vector <int> &dardos) {
	if (n < 0) return;
	else {
		if (restante % secs[n] == 0) {
			int x = restante / secs[n];
			suma += x;
			sol[n] = x;
			if (solution == -1 || suma < solution) {
				solution = suma;
				dardos = sol;
			}
		}
		else {
			for (int i = restante / secs[n]; i >= 0; i--) {
				if (solution == -1 || suma + i < solution) {
					sol[n] = i;
					resuelve(secs, sol, n - 1, restante - (secs[n] * i), suma + i, solution, dardos);
				}
			}
			sol[n] = 0;
			
		}
	}
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int obj, s,suma,solution = -1;
	cin >> obj >> s;

	vector <int> secs;
	vector <int> sol,dardos;
	if (!std::cin)
		return false;

	for (int i = 0; i < s; i++) {
		int x;
		cin >> x;
		secs.push_back(x);

	}
	sol.assign(s, 0);

	resuelve(secs, sol, s - 1, obj, 0,solution,dardos);
	



	if (solution == -1) {
		cout << "Imposible" << '\n';
	}
	else {
		cout << solution << ":";
		for (int i = s - 1; i >= 0; i--) {
			if (dardos[i] != 0) {
				for (int j = 0; j < dardos[i]; j++) {
					cout << " " << secs[i] ;
				}
			}
		}

		cout << '\n';
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