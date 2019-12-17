
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;



struct Piso
{
	int size;
	int color;

	bool operator<(const Piso & other)
	{
		return size > other.size;
	}
};


int N;
Piso floors[500005];

int Ordena(int color)
{
	int count = 0;

	int neededColor = 1 - color;
	for (int i = 0; i < N; ++i)
		if (floors[i].color == neededColor)
		{
			++count;
			neededColor = 1 - neededColor;
		}

	return count;
}

void resuelveCaso() {

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> floors[i].size;
		if (floors[i].size > 0) floors[i].color = 1;
		else floors[i].color = 0;
		floors[i].size = abs(floors[i].size);
	}

	sort(floors, floors + N);

	cout << max(Ordena(0), Ordena(1)) << '\n';
	
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