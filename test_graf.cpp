#include <iostream>
#include <string>
#include "graf/type.hpp"
#include "graf/arlogithm.hpp"

static void fatal(string msg) {
	cout << "\e[1;31m" << msg << "\e[0m" << endl;
	exit(1);
}

static void graf_matriu_Mida() {
	for (int i = 0; i < 30; i++) {
		cout << "test: graf matriu Mida() case " << i << endl;
		Graf::LlistaAdj G(Graf::Tipus::K, i);
		cout << G.Mida() << "==" << (i*i-i)/2 << endl;
		if (G.Mida() != (i*i-i)/2)
			fatal("Graf LlistaAdj -> MIDA()");
	}

        for (int i = 0; i < 30; i++) {
                cout << "test: graf matriu Mida() case T" << i << endl;
                Graf::LlistaAdj G(Graf::Tipus::T, i);
                int expected = (i > 0) ? i-1 : 0;  
                cout << G.Mida() << " == " << expected << " (arestes esperades)" << endl;
                if (G.Mida() != expected)
                        fatal("Graf LlistaAdj T -> MIDA()");
        }
        
        
        for (int i = 0; i < 30; i++) {
                cout << "test: graf matriu Mida() case C" << i << endl;
                Graf::LlistaAdj G(Graf::Tipus::C, i);
                int expected = i;  
                cout << G.Mida() << " == " << expected << " (arestes esperades)" << endl;
                if (G.Mida() != expected)
                        fatal("Graf LlistaAdj C -> MIDA()");
        }
        
        
        for (int i = 4; i < 30; i++) {  
                cout << "test: graf matriu Mida() case W" << i << endl;
                Graf::LlistaAdj G(Graf::Tipus::W, i);
                int expected = 2*i - 2;  
                cout << G.Mida() << " == " << expected << " (arestes esperades)" << endl;
                if (G.Mida() != expected)
                        fatal("Graf LlistaAdj W -> MIDA()");
        }
}

static void dfs_graf_matriu() {
	Graf::LlistaAdj G(Graf::Tipus::K, 30);
	cout << "0 to 30 range???\n";
	Graf::DFS(G, 10, [](int v) {
		cout << v << endl;
	});
}

int main() {
	graf_matriu_Mida();
	//dfs_graf_matriu();
	// TODO graus max i min
	
	cout << "end of tests!!!\n\nOK\n\n";
}
