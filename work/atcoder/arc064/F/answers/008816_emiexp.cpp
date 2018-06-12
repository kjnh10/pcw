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
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, K;
vector<int> divs;

i64 modpow(i64 a, int p)
{
	if (p == 0) return 1;
	i64 ret = modpow(a, p / 2);
	ret = ret * ret % MOD;
	if (p % 2 == 1) ret = ret * a % MOD;
	return ret;
}

int mebius(int v)
{
	int ret = 1;
	for (int p : divs) if (p > 1 && v % p == 0) {
		v /= p;
		if (v % p == 0) return 0;
		ret *= -1;
	}
	return ret;
}

map<int, int> meb;
map<int, i64> ori;

int main()
{
	scanf("%d%d", &N, &K);

	for (int i = 1; i * i <= N; ++i) {
		if (N % i == 0) {
			divs.push_back(i);
			if (N != i * i) divs.push_back(N / i);
		}
	}
	sort(divs.begin(), divs.end());
	for (int a : divs) meb[a] = mebius(a);

	if (N % 2 == 0) {
		for (int a : divs) if ((N / a) % 2 == 0) {
			ori[a] = modpow(K, a);
		}
		i64 ret = 0;
		for (int a : divs) if ((N / a) % 2 == 0) {
			i64 tmp = 0;
			for (int b : divs) if (a % b == 0) {
				ADD(tmp, MOD + ori[b] * meb[a / b]);
			}
			ADD(ret, tmp * a);
		}
		printf("%lld\n", ret);
	} else {
		for (int a : divs) {
			ori[a] = modpow(K, (a + 1) / 2);
		}
		i64 ret = 0;
		for (int a : divs) {
			i64 tmp = 0;
			for (int b : divs) if (a % b == 0) {
				ADD(tmp, MOD + ori[b] * meb[a / b]);
			}
			ADD(ret, tmp * a);
		}
		printf("%lld\n", ret);
	}
	return 0;
}
