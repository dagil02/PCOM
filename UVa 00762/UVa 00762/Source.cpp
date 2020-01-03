
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

map<string, string> route;
map <string, int> visited;


int bfs(string a, string b, map<string, vector<string> > graph) {
	queue<string>s;
	s.push(a);
	visited[a] = 1;
	while (s.empty() == false) {
		string top = s.front();
		s.pop();
		if (top == b)
			return visited[top];
		int size = graph[top].size();
		for (int i = 0; i < size; i++) {
			string n = graph[top][i];
			if (visited[n] == -1) {         
				visited[n] = visited[top] + 1; 
				route[n] = top;              
				s.push(n);
			}
		}
	}
	return -1;
}

void printpath(string a, string b) {
	if (a == b) { return; }
	printpath(route[a], b);
	cout << route[a] << " " << a << '\n';
}


bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!cin) return false;

	map<string, vector<string> > graph;

	string s1, s2, start, end;
	for (int i = 0; i < n; ++i)
	{
		cin >> s1 >> s2;
		graph[s1].push_back(s2);
		graph[s2].push_back(s1);
		visited[s1] = -1;
		visited[s2] = -1;
	}
	cin >> start >> end;

	// escribir sol
	
	
	if (bfs(start, end, graph) != -1) {
		printpath(end, start);
		cout << '\n';
	}
	else
		cout << "No route\n";
	


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}