
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

const int MAXN = 26; 
class Trie {
	int prefixes;
	
	
	
	public:

		vector<Trie*> child;
		int numOpt;
		int words;
		
		Trie() :prefixes(0), words(0),numOpt(0), child(MAXN, nullptr) {}
	   ~Trie() {
		   for (int i = 0; i < MAXN; ++i) delete child[i];
	   }

	   void add(const char*s) { 
		   if (*s == '\0') ++words; 
		   else { 
			   Trie* t; 
			   if (child[*s - 'a'] == nullptr) {
				   numOpt++;
				   t = child[*s - 'a'] = new Trie(); 
				   t->prefixes = 1; 
			   } else { 
				   t = child[*s - 'a']; 
				   t->prefixes++; 
			   }
			   t->add(s + 1); 
		   } 
	   }
};


bool resuelveCaso() {
	// leer los datos de la entrada
	double n,clicks = 0;
	cin >> n;
	Trie* t = new Trie();
	vector<string>v;
	if (!cin) return false;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
		char *c = &s[0];
		t->add(c);
	}

	for (int i = 0; i < v.size(); i++)
	{
		clicks++;
		Trie* aux = t;
		string act = v[i];
		aux = aux->child[act[0] - 'a'];
		for (int j = 1; j < act.length(); j++) {
			if (aux->numOpt > 1 || aux->words > 0) clicks++;
			aux = aux->child[act[j] - 'a'];

		}
	}
	// escribir sol
	double a = round(clicks / n * 100) / 100;

	printf("%.2f\n",a);

	delete t;
	t = nullptr;
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
