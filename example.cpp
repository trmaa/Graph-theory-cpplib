#include <iostream>
#include "graf/type.hpp"
#include "graf/arlogithm.hpp"

using namespace std;

int main() {
	cout << "G: Graf K10\n";
	Graf::LlistaAdj G(Graf::Tipus::K, 10);

	cout << "Mida: " << G.Mida() << endl;

	cout << "DFS:\n";
	Graf::DFS(G, 0, [](int v) {
		cout << v << endl;
	});
}
