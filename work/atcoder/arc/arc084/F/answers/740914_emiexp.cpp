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
#include <bitset>
using namespace std;
#define MOD 998244353
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;
typedef bitset<4000> Num;

int N;
Num X, A[6];

Num in()
{
	char buf[4040];
	scanf("%s", buf);

	int len = strlen(buf);
	Num ret;
	for (int i = 0; i < len; ++i) {
		if (buf[i] == '1') ret.set(len - 1 - i);
	}
	return ret;
}

int msb(Num a)
{
	for (int i = 3999; i >= 0; --i) {
		if (a[i]) return i;
	}
	return -1;
}

Num gcd(Num a, Num b)
{
	for (;;) {
		int na = msb(a), nb = msb(b);
		if (na == -1) return b;
		if (nb == -1) return a;
		if (na < nb) {
			b ^= a << (nb - na);
		} else {
			a ^= b << (na - nb);
		}
	}
}

i64 toint(Num n)
{
	i64 ret = 0;
	for (int i = 3999; i >= 0; --i) {
		ret = ret * 2 % MOD;
		ret += n[i];
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	X = in();
	for (int i = 0; i < N; ++i) A[i] = in();

	Num g = A[0];
	for (int i = 1; i < N; ++i) {
		g = gcd(g, A[i]);
	}
	int mg = msb(g);
	i64 ret = toint(X >> mg);

	Num waf = X, relka;
	for (int i = 3999; i >= mg; --i) {
		if (waf[i]) {
			waf ^= g << (i - mg);
			relka ^= g << (i - mg);
		}
	}
	bool toolarge = false;
	for (int i = mg - 1; i >= 0; --i) {
		int xi = X[i];
		int wi = relka[i];

		if (xi > wi) break;
		if (xi < wi) {
			toolarge = true;
			break;
		}
	}
	if (!toolarge) ADD(ret, 1);

	printf("%lld\n", ret);

	return 0;
}
