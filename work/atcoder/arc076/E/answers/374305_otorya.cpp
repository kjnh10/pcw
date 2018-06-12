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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll R, C;
ll ch(ll x, ll y) {
	if (x != 0 && x != R && y != 0 && y != C) return -1;
	if (y == 0) return x;
	else if (x == R) return R + y;
	else if (y == C) return R + C + (R - x);
	else return 2 * R + C + (C - y);
}

pll in[100050];
vector <ll> Vx;

int bit[530000];
void update(int p, int v) {
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += v;
}
int getsum(int p) {
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}

int main() {
	int N, i;
	scanf("%lld %lld %d", &R, &C, &N);
	for (i = 1; i <= N; i++) {
		ll x1, y1, x2, y2;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		ll t1 = ch(x1, y1), t2 = ch(x2, y2);
		if (t1 == -1 || t2 == -1) {
			i--;
			N--;
			continue;
		}
		if (t1 > t2) swap(t1, t2);
		in[i] = pll(t1, t2);
	}
	if (!N) return !printf("YES\n");

	for (i = 1; i <= N; i++) {
		Vx.push_back(in[i].first);
		Vx.push_back(in[i].second);
	}
	sort(all(Vx));
	Vx.erase(unique(all(Vx)), Vx.end());
	for (i = 1; i <= N; i++) {
		in[i].first = lower_bound(all(Vx), in[i].first) - Vx.begin() + 1;
		in[i].second = lower_bound(all(Vx), in[i].second) - Vx.begin() + 1;
	}
	sort(in + 1, in + N + 1);

	for (i = 1; i <= N; i++) {
		int t = getsum(in[i].second) - getsum(in[i].first);
		if (t) return !printf("NO\n");
		update(in[i].second, 1);
	}
	return !printf("YES\n");
}