#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

// range add - range query
// T should be a commutative monoid
template <class T, int depth>
class segtree_impl
{
public:
	segtree_impl(const T def = T()) {
		for (int i = 1; i < 2 * kSize; ++i) lazy[i] = def;
		for (int i = 0; i < kSize; ++i) {
			data[i + kSize] = def;
		}
		for (int i = kSize - 1; i >= 1; --i) data[i] = data[i * 2] + data[i * 2 + 1];
	}
	void range_add(int l, int r, const T& v) {
		propagate(l, r);
		int pl = l + kSize, pr = r + kSize;
		while (pl != pr) {
			if (pl & 1) {
				lazy[pl] = lazy[pl] + v; ++pl;
			}
			if (pr & 1) {
				--pr; lazy[pr] = lazy[pr] + v;
			}
			pl >>= 1; pr >>= 1;
		}
		for (int i = 0; i <= depth; ++i) {
			int pl = (l + kSize) >> i, pr = (r - 1 + kSize) >> i;
			update(pl);
			if (pl != pr) update(pr);
		}
	}
	T range_query(int l, int r) {
		propagate(l, r);
		T ret = T();
		l += kSize; r += kSize;
		while (l < r) {
			if (l & 1) ret = ret + data[l++];
			if (r & 1) ret = ret + data[--r];
			l >>= 1; r >>= 1;
		}
		return ret;
	}
private:
	static const int kSize = 1 << depth;
	T data[kSize << 1], lazy[kSize << 1];
	void update(int p) {
		if (p >= kSize) data[p] = lazy[p];
		else data[p] = data[p * 2] + data[p * 2 + 1] + lazy[p];
	}
	void propagate(int p) {
		lazy[p * 2] = lazy[p * 2] + lazy[p]; update(p * 2);
		lazy[p * 2 + 1] = lazy[p * 2 + 1] + lazy[p]; update(p * 2 + 1);
		lazy[p] = T();
	}
	void propagate(int l, int r) {
		for (int i = depth; i > 0; --i) {
			int pl = (l + kSize) >> i, pr = (r - 1 + kSize) >> i;
			propagate(pl);
			if (pl != pr) propagate(pr);
		}
	}
};
struct hoge
{
	int v;

	hoge(int v = 1001001001) : v(v) {}
	operator int() const { return v; }
};

inline hoge operator+(const hoge& a, const hoge& b)
{
	return hoge(min(a.v, b.v));
}

template <class T, int depth>
struct simple_seg
{
public:
	simple_seg() {
		for (int i = 0; i < kSize; ++i) {
			data[i + kSize] = 1001001001;
		}
		for (int i = kSize - 1; i >= 1; --i) data[i] = 1001001001;
	}
	void point_upd(int p, const T &v) {
		p += kSize;
		while (p) {
			data[p] = min(data[p], v);
			p >>= 1;
		}
	}
	T range_query(int l, int r) {
		l += kSize;
		r += kSize;
		T ret = 1001001001;
		while (l < r) {
			if (l & 1) ret = min(ret, data[l++]);
			if (r & 1) ret = min(ret, data[--r]);
			l >>= 1; r >>= 1;
		}
		return ret;
	}

private:
	static const int kSize = 1 << depth;
	T data[kSize << 1];
};

int N, Q, L[202020], R[202020], B[202020];
int ones[202020], zeros[202020];

segtree_impl<hoge, 18> dpe;
simple_seg<int, 18> dpall;

int get_dpall(int p)
{
	return dpall.range_query(0, p + 1) + ones[p];
}
int get_dpe(int p)
{
	return dpe.range_query(p, p + 1).v + zeros[p];
}
void update_dpall(int p, int v)
{
	dpall.point_upd(p, v - ones[p]);
}
void update_dpe(int l, int r, int v)
{
	dpe.range_add(l, r, v - zeros[l]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", B + i);
	ones[0] = zeros[0] = 0;
	for (int i = 0; i < N; ++i) {
		ones[i + 1] = ones[i];
		zeros[i + 1] = zeros[i];
		(B[i] == 0 ? zeros : ones)[i + 1]++;
	}

	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		scanf("%d%d", L + i, R + i);
		--L[i];
	}

	vector<pair<int, int> > qs;
	for (int i = 0; i < Q; ++i) qs.push_back({ R[i], L[i] });
	sort(qs.begin(), qs.end());

	update_dpall(0, 0);

	for (auto q : qs) {
		int left = q.second, right = q.first;

		int lp = 1001001001;
		lp = min(lp, get_dpall(left));
		lp = min(lp, get_dpe(left));
		//printf("%d %d %d\n", left, right, lp);
		
		update_dpall(right, lp + zeros[right] - zeros[left]);
		update_dpe(left, right, lp);
	}

	printf("%d\n", get_dpall(N));

	return 0;
}
