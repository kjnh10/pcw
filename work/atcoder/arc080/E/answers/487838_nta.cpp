#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct Val {
	int xs[2];
	Val() : xs{ INF, INF } {}
};
struct Sum {
	int mini[2];
	Sum() : mini{ INF, INF } {}
	Sum(const Val &val, int pos) { rep(k, 2) mini[k] = val.xs[k]; }
	Sum &operator+=(const Sum &that) { rep(k, 2) amin(mini[k], that.mini[k]); return *this; }
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};
struct Add {
	int flip;
	Add() : flip(0) { }
	Add &operator+=(const Add &that) { flip ^= that.flip; return *this; }
	void addToVal(Val &val, int pos) const { if (flip) swap(val.xs[0], val.xs[1]); }
	void addToSum(Sum &sum, int left, int right) const { if (flip) swap(sum.mini[0], sum.mini[1]); }
};

struct SegmentTree {
	vector<Val> leafs;
	vector<Sum> nodes;
	vector<Add> add;
	vector<int> leftpos, rightpos;
	int n, n2;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while (n < (int)u.size()) n *= 2;
		n2 = (n - 1) / 2 + 1;
		leafs = u; leafs.resize(n, Val());
		nodes.resize(n);
		for (int i = n - 1; i >= n2; -- i)
			nodes[i] = Sum(leafs[i * 2 - n], i * 2 - n) + Sum(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
		for (int i = n2 - 1; i > 0; -- i)
			nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
		add.assign(n, Add());

		leftpos.resize(n); rightpos.resize(n);
		for (int i = n - 1; i >= n2; -- i) {
			leftpos[i] = i * 2 - n;
			rightpos[i] = (i * 2 + 1 - n) + 1;
		}
		for (int i = n2 - 1; i > 0; -- i) {
			leftpos[i] = leftpos[i * 2];
			rightpos[i] = rightpos[i * 2 + 1];
		}
	}
	Val get(int i) {
		int indices[128];
		int k = getIndices(indices, i, i + 1);
		propagateRange(indices, k);
		return leafs[i];
	}
	Sum getRangeCommutative(int i, int j) {
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		Sum res = Sum();
		for (int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res += sum(l ++);
			if (r & 1) res += sum(-- r);
		}
		return res;
	}
	void set(int i, const Val &x) {
		int indices[128];
		int k = getIndices(indices, i, i + 1);
		propagateRange(indices, k);
		leafs[i] = x;
		mergeRange(indices, k);
	}
	void addToRange(int i, int j, const Add &x) {
		if (i >= j) return;
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		int l = i + n, r = j + n;
		if (l & 1) { int p = (l ++) - n; x.addToVal(leafs[p], p); }
		if (r & 1) { int p = (-- r) - n; x.addToVal(leafs[p], p); }
		for (l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) add[l ++] += x;
			if (r & 1) add[-- r] += x;
		}
		mergeRange(indices, k);
	}
private:
	int getIndices(int indices[], int i, int j) const {
		int k = 0, l, r;
		if (i >= j) return 0;
		for (l = (n + i) >> 1, r = (n + j - 1) >> 1; l != r; l >>= 1, r >>= 1) {
			indices[k ++] = l;
			indices[k ++] = r;
		}
		for (; l; l >>= 1) indices[k ++] = l;
		return k;
	}
	void propagateRange(int indices[], int k) {
		for (int i = k - 1; i >= 0; -- i)
			propagate(indices[i]);
	}
	void mergeRange(int indices[], int k) {
		for (int i = 0; i < k; ++ i)
			merge(indices[i]);
	}
	inline void propagate(int i) {
		if (i >= n) return;
		add[i].addToSum(nodes[i], leftpos[i], rightpos[i]);
		if (i * 2 < n) {
			add[i * 2] += add[i];
			add[i * 2 + 1] += add[i];
		} else {
			add[i].addToVal(leafs[i * 2 - n], i * 2 - n);
			add[i].addToVal(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
		}
		add[i] = Add();
	}
	inline void merge(int i) {
		if (i >= n) return;
		nodes[i] = sum(i * 2) + sum(i * 2 + 1);
	}
	inline Sum sum(int i) {
		propagate(i);
		return i < n ? nodes[i] : Sum(leafs[i - n], i - n);
	}
};

int main() {
	int N;
	while (~scanf("%d", &N)) {
		vector<int> p(N);
		for (int i = 0; i < N; ++ i)
			scanf("%d", &p[i]), -- p[i];
		vector<int> pos(N, -1);
		rep(i, N) pos[p[i]] = i;
		SegmentTree segt;
		vector<Val> initVals(N);
		rep(i, N) initVals[i].xs[i % 2] = p[i];
		segt.init(initVals);
		set<int> borders = {N};
		vector<int> ans;
		rep(k, N / 2) {
			int x = segt.getRangeCommutative(0, N).mini[0];
			int posx = pos[x];
			int R = *borders.lower_bound(posx + 1);
			int y = segt.getRangeCommutative(posx + 1, R).mini[1];
			int posy = pos[y];
			ans.push_back(x);
			ans.push_back(y);
			segt.set(posx, Val());
			segt.set(posy, Val());
			Add add;
			add.flip = 1;
			segt.addToRange(posx + 1, posy, add);
			borders.insert(posx);
			borders.insert(posy);
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}
