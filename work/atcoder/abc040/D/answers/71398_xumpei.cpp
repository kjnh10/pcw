#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> size;

	UnionFind(int n) : parent(n), size(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int operator[](int x) {
		if (parent[x] == x) {
			return x;
		} else {
			return parent[x] = operator[](parent[x]);
		}
	}

	bool merge(int x, int y) {
		x = operator[](x);
		y = operator[](y);
		if (x == y) return false;
		if (size[x] < size[y]) swap(x, y);
		parent[y] = x;
		size[x] += size[y];
		return true;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> es(m);
	
	for (int i = 0; i < m; i++) {
		int a, b, y;
		scanf("%d %d %d", &a, &b, &y);
		a--; b--;
		es[i] = make_tuple(y, a, b);
	}
	sort(es.rbegin(), es.rend());

	int q;
	cin >> q;
	vector<tuple<int, int, int>> wvi(q);
	for (int i = 0; i < q; i++) {
		int v, w;
		scanf("%d %d", &v, &w);
		v--;

		wvi[i] = make_tuple(w, v, i);
	}
	sort(wvi.rbegin(), wvi.rend());

	UnionFind uf(n);

	vector<int> ans(q);
	int i = 0;
	for (auto t : wvi) {
		int w, v, id;
		tie(w, v, id) = t;

		while (i < m && get<0>(es[i]) > w) {
			uf.merge(get<1>(es[i]), get<2>(es[i]));
			i++;
		}

		ans[id] = uf.size[uf[v]];
	}

	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
}