```
#pragma once

using namespace std;
class UF_quickUnion {
	int *p;
	size_t nb;
	int *r;
public:
	UF_quickUnion(size_t n) : p(new int[n]), nb(n), r(new int[n]) {
		for (size_t i = 0; i < n; ++i) {
			p[i] = i;
			r[i] = 1;
		}
	}

	~UF_quickUnion() {
		delete[] p;
		delete[] r;
	}

	int root(int n) {
		while (p[n] != n)
			n = p[n];
		return n;
	}

	bool connected(int a, int b) {
		return root(a) == root(b);
	}

	void Union(int a, int b) {
		if (r[root(a)] <= r[root(b)]) {
			p[root(a)] = p[root(b)];
			r[root(b)] += r[root(a)];
		}
		else {
			r[root(a)] += r[root(b)];
			p[root(b)] = p[root(a)];
		}

	}


};
```