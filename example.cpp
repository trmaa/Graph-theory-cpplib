#include <iostream>
#include "graf/type.hpp"
#include "graf/arlogithm.hpp"

using namespace std;

int main() {
	cout << "G: Graf K10\n";
	Graf::Matriu G(Graf::Tipus::K, 10);

	cout << "mida: " << G.mida() << endl;

	cout << "DFS:\n";
	Graf::DFS(G, 0, [](int v) {
		cout << v << endl;
	});
}
