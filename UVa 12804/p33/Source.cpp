


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct  ins
{
	string name;
	int next;
};


int resuelve(int ini,int fin, vector<ins> &v,vector<bool> &visitados) {
	int i = ini;
	while (i < fin) {
		visitados[i] = true;
		if (v[i].name == "A") {
			i++;
		}
		else if (v[i].name == "J") {
			i = v[i].next;
			if (visitados[i]) return -1;
		}
		else {

				vector<bool>aux = visitados;
				int a, b;
				if (visitados[v[i].next])a = -1;
				else a = resuelve(v[i].next, fin, v, visitados);

				
				if (a == 0) return 0;

				if (i + 1 == fin) b = 1;
				else if (aux[i + 1]) b = -1;
				else { 
					
					if(a == 1)b = resuelve(i + 1, fin, v, aux);
					else b = resuelve(i + 1, fin, v, visitados);
				}


				if (a == b) return a;
				else return 0;
			
				
		}
	
	}

	return 1;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	vector<ins> v;
	vector<bool> visitados;
	visitados.assign(n+1, false);
	ins aux;
	v.push_back(aux);
	for (int i = 1; i <= n; i++) {
		string inst;
		cin >> inst;

		ins x;
		x.name = inst;

		if (inst == "A") {
			x.next = i + 1;
		}
		else {
			int a;
			cin >> a;
			x.next = a;
		}

		v.push_back(x);
	}



	// escribir sol
	int sol = resuelve(1, n + 1, v, visitados);
	if (sol == -1) cout << "NEVER" << '\n';
	else if (sol == 0) cout << "SOMETIMES" << '\n';
	else cout << "ALWAYS" << '\n';

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