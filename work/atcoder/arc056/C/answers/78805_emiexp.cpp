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
#include <cmath>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int main()
{
	i64 A, B, K, L;
	scanf("%lld%lld%lld%lld", &A, &B, &K, &L);
	i64 ret = A * K;
	i64 ret2 = A * (K % L) + B * (K / L);
	i64 ret3 = B * ((K - 1) / L + 1);
	printf("%lld\n", min(ret, min(ret2, ret3)));
	return 0;
}
