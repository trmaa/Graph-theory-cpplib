#pragma once

#include <vector>
#include <queue>
#include "type.hpp"

using namespace std;

namespace Graf {
	static void DFS_impl(const LlistaAdj& G, int v, vector<bool>& seen, void (*visit)(int)) {
		visit(v);
		seen[v] = true;

		for (int u : G.at(v))
			if (!seen[u]) DFS_impl(G, u, seen, visit);
	}

	inline void DFS(const LlistaAdj& G, int v, void (*cb)(int)) {
		vector<bool> seen(G.Ordre());
		DFS_impl(G, v, seen, cb);
	}

	static void BFS_impl(const LlistaAdj& G, int v, vector<bool>& seen, void (*visit)(int)) {
                queue<int> q;
                
                visit(v);
                seen[v] = true;
                q.push(v);

                while (!q.empty()) {
                        int current = q.front();
                        q.pop();

                        for (int u : G.at(current))
                                if (!seen[u]) {
                                        visit(u);
                                        seen[u] = true;
                                        q.push(u);
                                }
                }
        }

        inline void BFS(const LlistaAdj& G, int v, void (*cb)(int)) {
                vector<bool> seen(G.Ordre());
                BFS_impl(G, v, seen, cb);
        }	

	inline int grau(const LlistaAdj& G, int v) {
		return G.at(v).size();
	}
};
