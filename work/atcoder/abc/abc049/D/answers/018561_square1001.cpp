#ifndef ___Rank_Union_Find
#define ___Rank_Union_Find

#include <vector>

// ------ Class ------ //
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

#endif

#include <map>
#include <cstdio>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;
int N, K, L, p, q;
int main() {
	scanf("%d%d%d", &N, &K, &L);
	UnionFind uf1(N), uf2(N);
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &p, &q); p--, q--;
		uf1.unite(p, q);
	}
	for (int i = 0; i < L; i++) {
		scanf("%d%d", &p, &q); p--, q--;
		uf2.unite(p, q);
	}
	map<pair<int, int>, int> cnt;
	for (int i = 0; i < N; i++) {
		cnt[make_pair(uf1.root(i), uf2.root(i))]++;
	}
	for (int i = 0; i < N; i++) {
		printf(i ? " %d" : "%d", cnt[make_pair(uf1.root(i), uf2.root(i))]);
	}
	printf("\n");
	return 0;
}