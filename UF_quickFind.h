
#pragma once
#include <stddef.h>
using namespace std;

class UF_quickFind {
	int* p;
	size_t nb;
public:
	UF_quickFind(size_t n) : p(new int[n]), nb(n) {
		for (size_t i = 0; i < n; ++i) {
			p[i] = i;
		}
	}

	~UF_quickFind() {
		delete[] p;
	}

	bool connected(int a, int b) {
		return p[a] == p[b];
	}

	void Union(int a, int b) {
		int temp = p[a];
		for (size_t i = 0; i < nb; ++i) {
			if (p[i] == temp)
				p[i] = p[b];
		}
	}
};

