#include <iostream>
#include <string>
#include "graf/type.hpp"
#include "graf/arlogithm.hpp"

static void fatal(string msg) {
	cout << "\e[1;31m" << msg << "\e[0m" << endl;
	exit(1);
}

static void graf_matriu_mida() {
	for (int i = 0; i < 30; i++) {
		cout << "test: graf matriu mida() case " << i << endl;
		Graf::Matriu G(Graf::Tipus::K, i);
		cout << G.mida() << "==" << (i*i-i)/2 << endl;
		if (G.mida() != (i*i-i)/2)
			fatal("Graf Matriu -> MIDA()");
	}

        for (int i = 0; i < 30; i++) {
                cout << "test: graf matriu mida() case T" << i << endl;
                Graf::Matriu G(Graf::Tipus::T, i);
                int expected = (i > 0) ? i-1 : 0;  
                cout << G.mida() << " == " << expected << " (arestes esperades)" << endl;
                if (G.mida() != expected)
                        fatal("Graf Matriu T -> MIDA()");
        }
        
        
        for (int i = 0; i < 30; i++) {
                cout << "test: graf matriu mida() case C" << i << endl;
                Graf::Matriu G(Graf::Tipus::C, i);
                int expected = i;  
                cout << G.mida() << " == " << expected << " (arestes esperades)" << endl;
                if (G.mida() != expected)
                        fatal("Graf Matriu C -> MIDA()");
        }
        
        
        for (int i = 4; i < 30; i++) {  
                cout << "test: graf matriu mida() case W" << i << endl;
                Graf::Matriu G(Graf::Tipus::W, i);
                int expected = 2*i - 2;  
                cout << G.mida() << " == " << expected << " (arestes esperades)" << endl;
                if (G.mida() != expected)
                        fatal("Graf Matriu W -> MIDA()");
        }
}

static void dfs_graf_matriu() {
	Graf::Matriu G(Graf::Tipus::K, 30);
	cout << "0 to 30 range???\n";
	Graf::DFS(G, 10, [](int v) {
		cout << v << endl;
	});
}

int main() {
	graf_matriu_mida();
	//dfs_graf_matriu();
	
	cout << "end of tests!!!\n\nOK\n\n";
}
