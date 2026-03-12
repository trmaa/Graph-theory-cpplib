#include <iostream>
#include "graf/type.hpp"
#include "graf/arlogithm.hpp"

using namespace std;

int main() {
	cout << "G: Graf C10\n";
	Graf::LlistaAdj G(Graf::Tipus::C, 10);

	cout << "Mida: " << G.Mida() << endl;

	cout << "DFS:\n";
	Graf::DFS(G, 0, [](int v) {
		cout << v << endl;
	});

	cout << "BFS:\n";
	Graf::BFS(G, 0, [](int v) {
		cout << v << endl;
	});
}
