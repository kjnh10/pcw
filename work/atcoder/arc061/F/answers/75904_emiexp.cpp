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

int N, M, K;
i64 fact[909090], frev[909090];
i64 invs[909090];

i64 modpow(i64 a, i64 p = MOD - 2)
{
	if (p == 0) return 1;
	i64 tmp = modpow(a, p / 2);
	tmp = tmp * tmp % MOD;
	if (p % 2) tmp = tmp * a % MOD;
	return tmp;
}

i64 C(int a, int b)
{
	if (a < b) return 0;
	return fact[a] * frev[b] % MOD * frev[a - b] % MOD;
}

int main()
{
	fact[0] = 1; frev[0] = 1;
	invs[0] = 1;
	invs[1] = 1;
	for (int i = 2; i < 909090; ++i) invs[i] = MOD - MOD / i * invs[MOD % i] % MOD;
	for (int i = 1; i < 909090; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
		frev[i] = frev[i - 1] * invs[i] % MOD;
	}

	scanf("%d%d%d", &N, &M, &K);

	if (M > K) swap(M, K);
	i64 ret = 0, cur = 1;
	for (int w = 0; w <= M + K; ++w) {
		ADD(ret, C(N - 1 + w, w) * cur % MOD * modpow(3, M + K - w));
		cur = cur * 2 % MOD;
		
		int lo = min(w, M);
		if (w >= M) {
			ADD(cur, MOD - C(w, M));
		}
		if (w >= K) {
			ADD(cur, MOD - C(w, w - K));
		}
	}
	printf("%lld\n", ret);

	return 0;
}
