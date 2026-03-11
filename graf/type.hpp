#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace Graf {
	enum Tipus { K, T, C, W };

	class LlistaAdj : vector<vector<int>> {
	public:
		using vector<vector<int>>::at;

		/* TODO
		 * Grafs matriu a partir d'altres grafs
		 */

		LlistaAdj() = default;
		LlistaAdj(vector<vector<int>> custom);
		LlistaAdj(Tipus t, int size);

		int grau() const;
		int mida() const;

	private:
		void setupK(int size);
		void setupT(int size);
		void setupC(int size);
		void setupW(int size);
	};	

	LlistaAdj::LlistaAdj(vector<vector<int>> custom)
		: vector<vector<int>>(custom) {}

	LlistaAdj::LlistaAdj(Tipus t, int size) {
		switch (t) {
			case Tipus::K:
				setupK(size);
				break;
			case Tipus::T:
				setupT(size);
				break;
			case Tipus::C:
				setupC(size);
				break;
			case Tipus::W:
				setupW(size);
				break;
			default:
				cerr << "Mal tipus de graf\n";
		}
	}

	int LlistaAdj::grau() const { 
		return this->size(); 
	}

	int LlistaAdj::mida() const {
		int res = 0;
		vector<bool> seen(this->grau());
		for (int v = 0; v < this->grau(); v++) {
			for (int u : this->at(v))
				if (!seen[u])
					res++;
			seen[v] = true;
		}
		return res;
	}

	void LlistaAdj::setupK(int size) {
		cerr << "Graf complet K" << size << " -------------\n";
		for (int v = 0; v < size; v++) {
			cerr << v << "\t| ";
			vector<int> arr;
			for (int u = 0; u < size; u++)
				if (u != v) {
					arr.push_back(u);
					cerr << u << ' ';
				}
			this->push_back(arr);
			cerr << endl;
		}
		cerr << "-------------------------\n";
	}

	void LlistaAdj::setupT(int size) {
		cerr << "Graf camí T" << size << " -------------\n";
		for (int v = 0; v < size; v++) {
			cerr << v << "\t| ";
			vector<int> arr;

			if (v > 0) {
				arr.push_back(v-1);
				cerr << v-1 << ' ';
			}
			if (v < size - 1) {
				arr.push_back(v+1);
				cerr << v+1 << ' ';
			}

			this->push_back(arr);
			cerr << endl;
		}
		cerr << "-------------------------\n";
	}

	void LlistaAdj::setupC(int size) {
		cerr << "Graf cicle C" << size << " -------------\n";
		for (int v = 0; v < size; v++) {
			cerr << v << "\t| ";
			vector<int> arr;

			if (v > 0) {
				arr.push_back(v-1);
				cerr << v-1 << ' ';
			} else {
				arr.push_back(size-1);
				cerr << size-1 << ' ';
			}

			if (v < size - 1) {
				arr.push_back(v+1);
				cerr << v+1 << ' ';
			} else {
				if (size > 1) {
					arr.push_back(0);
					cerr << 0 << ' ';
				}
			}

			this->push_back(arr);
			cerr << endl;
		}
		cerr << "-------------------------\n";
	}

	void LlistaAdj::setupW(int size) {
		cerr << "Graf roda W" << size << " -------------\n";

		if (size < 4) {
			cerr << "Error: Un graf roda necessita almenys 4 vèrtexs\n";
			return;
		}

		int centre = size - 1;

		for (int v = 0; v < size; v++) {
			cerr << v << "\t| ";
			vector<int> arr;

			if (v == centre) {
				for (int u = 0; u < centre; u++) {
					arr.push_back(u);
					cerr << u << ' ';
				}
			} else {
				arr.push_back(centre);
				cerr << centre << ' ';

				if (v > 0) {
					arr.push_back(v-1);
					cerr << v-1 << ' ';
				} else {
					arr.push_back(centre-1);
					cerr << centre-1 << ' ';
				}

				if (v < centre - 1) {
					arr.push_back(v+1);
					cerr << v+1 << ' ';
				} else if (v == centre - 1 && centre > 1) {
					arr.push_back(0);
					cerr << 0 << ' ';
				}
			}

			this->push_back(arr);
			cerr << endl;
		}
		cerr << "-------------------------\n";
	}
};
