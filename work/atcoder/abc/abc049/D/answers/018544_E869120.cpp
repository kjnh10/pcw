#include<iostream>
#include<vector>
#include<map>
using namespace std;
class UnionFind {
private:
	unsigned size_; std::vector<unsigned> par, rank;
public:
	UnionFind() : size_(0), par(std::vector<unsigned>()), rank(std::vector<unsigned>()) {};
	UnionFind(unsigned size__) : size_(size__) {
		par.resize(size_); rank.resize(size_);
		for (unsigned i = 0; i < size_; i++) par[i] = i, rank[i] = 0;
	}
	unsigned size() { return size_; }
	unsigned root(unsigned x) { return par[x] == x ? x : par[x] = root(par[x]); }
	bool same(unsigned x, unsigned y) { return root(x) == root(y); }
	void unite(unsigned x, unsigned y) {
		x = root(x), y = root(y);
		if (x == y) return;
		if (rank[x] < rank[y]) par[x] = y;
		else if (rank[x] == rank[y]) par[y] = x, rank[x]++;
		else par[y] = x;
	}
	bool operator==(const UnionFind &u) { return par == u.par; }
	bool operator!=(const UnionFind &u) { return par != u.par; }
};

int n, m, p, a, b;
int main() {
	cin >> p >> n >> m;
	UnionFind UF1(p + 1), UF2(p + 1);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		UF1.unite(a, b);
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		UF2.unite(a, b);
	}
	map<pair<int, int>, int>E;
	for (int i = 1; i <= p; i++) {
		E[make_pair(UF1.root(i), UF2.root(i))]++;
	}
	for (int i = 1; i <= p; i++) {
		if (i >= 2)cout << " ";
		cout << E[make_pair(UF1.root(i), UF2.root(i))];
	}
	cout << endl;
	return 0;
}