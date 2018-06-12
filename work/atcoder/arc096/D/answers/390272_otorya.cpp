#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll in[100050][2];
ll sum[100050];

ll mx1[100050];
ll mx2[100050];
int main() {
	ll N, C, i, j;
	scanf("%lld %lld", &N, &C);
	for (i = 1; i <= N; i++) scanf("%lld %lld", &in[i][0], &in[i][1]);
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + in[i][1];

	ll ans = 0;
	ans = max(ans, sum[N] - C);

	for (i = 1; i <= N; i++) mx1[i] = max(mx1[i - 1], sum[i] - 2 * in[i][0]);
	for (i = N; i >= 1; i--) mx2[i] = max(mx2[i + 1], (sum[N] - sum[i - 1]) - (C - in[i][0]));
	for (i = 0; i <= N; i++) ans = max(ans, mx1[i] + mx2[i + 1]);

	for (i = 1; i <= N; i++) mx1[i] = max(mx1[i - 1], sum[i] - in[i][0]);
	for (i = N; i >= 1; i--) mx2[i] = max(mx2[i + 1], (sum[N] - sum[i - 1]) - 2 * (C - in[i][0]));
	for (i = 0; i <= N; i++) ans = max(ans, mx1[i] + mx2[i + 1]);
	return !printf("%lld\n", ans);
}