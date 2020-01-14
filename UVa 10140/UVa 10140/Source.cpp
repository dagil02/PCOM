
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>

typedef long long ll;



using namespace std;

const int BITSET_SIZE = 100000;
const int LARGEST_DIFFERENCE = 1000001;
bitset<BITSET_SIZE> isPrime;
bitset<LARGEST_DIFFERENCE> isComposite;
vector<int> primes;

bool resuelveCaso() {
	// leer los datos de la entrada
	int L, U;
	cin >> L >> U;
	if (!cin) return false;


	isComposite.reset();
	for (int i = 0; i < primes.size() && (ll)primes[i] * primes[i] <= U; ++i)
	{
		const int &prime = primes[i];
		ll start = L % prime == 0 ? L : (ll)L + (prime - L % prime);
		for (ll n = start; n <= U; n += prime)
		{
			if (n != prime)
				isComposite.set(n - L);
		}
	}
	
	if (L == 1)
		isComposite.set(0);

	ll C1(0), C2(U), D1(0), D2(0);
	ll lastPrime = 0;
	for (ll n = L; n <= U; ++n)
	{
		if (!isComposite[n - L])
		{
			if (lastPrime != 0)
			{
				if (n - lastPrime < C2 - C1)
				{
					C1 = lastPrime;
					C2 = n;
				}
				if (n - lastPrime > D2 - D1)
				{
					D1 = lastPrime;
					D2 = n;
				}
			}
			lastPrime = n;
		}
	}
	if (C1 == 0)
		cout << "There are no adjacent primes." << '\n';
	else
		cout << C1
		<< ","
		<< C2
		<< " are closest, "
		<< D1
		<< ","
		<< D2
		<< " are most distant."
		<< '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	isPrime.set();
	isPrime.reset(0);
	isPrime.reset(1);

	for (int n = 2; n < BITSET_SIZE; ++n)
	{
		if (isPrime[n])
		{
			if ((unsigned long long)n * n < BITSET_SIZE)
			{
				for (int m = n * n; m < BITSET_SIZE; m += n)
					isPrime.reset(m);
			}
			primes.push_back(n);
		}
	}

	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}