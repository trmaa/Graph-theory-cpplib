#pragma once

#include <vector>
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

	inline int grau(const LlistaAdj& G, int v) {
		return G.at(v).size();
	}

	// TODO BFS
};
