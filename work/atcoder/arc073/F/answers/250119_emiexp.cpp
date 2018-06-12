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

int N, Q, A, B;
int X[202020];

struct segtree
{
	static const int DEPTH = 18;
	static const int N = 1 << DEPTH;
	i64 val[2 * N];
	i64 ofs;

	void init()
	{
		for (int i = 0; i < 2 * N; ++i) val[i] = (1LL << 60LL);
		ofs = 0;
	}
	void update(int p, i64 v)
	{
		p += N;
		val[p] = v - ofs;
		p >>= 1;
		while (p) {
			val[p] = min(val[p * 2], val[p * 2 + 1]);
			p >>= 1;
		}
	}
	void add_all(i64 val)
	{
		ofs += val;
	}
	i64 query(int L, int R)
	{
		i64 ret = 1LL << 60LL;
		L += N; R += N;
		while (L < R) {
			if (L & 1) ret = min(ret, val[L++]);
			if (R & 1) ret = min(ret, val[--R]);
			L >>= 1; R >>= 1;
		}
		return ret + ofs;
	}
};

segtree lf, rg;

void upd(int p, i64 v)
{
	lf.update(p, v - p);
	rg.update(p, v + p);
}
i64 query(int p)
{
	i64 ret = lf.query(0, p + 1) + p;
	ret = min(ret, rg.query(p, segtree::N) - p);
	return ret;
}

int main()
{
	scanf("%d%d%d%d", &N, &Q, &A, &B);

	lf.init();
	rg.init();
	
	int last_pos = A;
	upd(B, 0LL);

	for (int i = 0; i < Q; ++i) {
		scanf("%d", X + i);

		i64 a = query(X[i]);
		lf.add_all(abs(X[i] - last_pos));
		rg.add_all(abs(X[i] - last_pos));
		upd(last_pos, a);
		last_pos = X[i];
	}

	i64 ret = 1LL << 60LL;
	for (int i = 1; i <= N; ++i) {
		ret = min(ret, lf.query(i, i + 1) + i);
	}
	printf("%lld\n", ret);
	return 0;
}
