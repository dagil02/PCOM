// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

// función que resuelve el problema
double resolver(double &a, double &b, double &h) {
	double minimo, maximo, w, estimacion, diff = 0.000001;
	minimo = 0;
	maximo = min(a, b);

	while (true) {
		w = minimo / 2 + maximo / 2;
		estimacion = sqrt(a*a - w * w)*sqrt(b*b - w * w) / (sqrt(a*a - w * w) + sqrt(b*b - w * w));
		if (fabs(estimacion - h) <= diff)
			return w;
		if (estimacion > h)minimo = w;
		else maximo = w;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	double a, b, h;
	cin >> a >> b >> h;
	if (!std::cin)
		return false;

	double sol = resolver(a,b,h);
	
	printf("%.3f\n", sol);
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