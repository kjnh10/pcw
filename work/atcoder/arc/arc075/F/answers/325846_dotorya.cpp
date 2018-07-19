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
const db ERR = 1E-11;

map <pair<pll, bool>, ll> Mx;
int getdigit(ll x) {
	int rv = 0;
	while (x) {
		rv++;
		x /= 10;
	}
	return rv;
}

ll po10[20];
ll aa(int d, ll v, bool c) {
	if (d == 0) {
		if (v == 0) return 1;
		return 0;
	}
	if (d == 1) {
		if (v == 0) {
			if (c) return 9;
			return 10;
		}
		return 0;
	}
	if (Mx.count(mp(pll(d, v), c))) return Mx[mp(pll(d, v), c)];

	if (po10[d] <= abs(v)) return 0;
	int i, j;

	ll rv = 0;
	for (i = 0; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {
			if (c && (i == 0)) continue;

			ll t = po10[d - 1] * (j - i) + i - j;
			if ((v - t) % 10) continue;
			rv += aa(d - 2, (v - t) / 10, false);
		}
	}
	return Mx[mp(pll(d, v), c)] = rv;
}
int main() {
	ll D;
	scanf("%lld", &D);

	bool c = true;
	ll ans = 1;
	while (D % 10 == 0) {
		if (ans == 1) ans = 9;
		else ans *= 10;
		D /= 10;
		c = false;
	}

	po10[0] = 1;
	for (int i = 1; i <= 18; i++) po10[i] = po10[i - 1] * 10;

	ll ans2 = 0;
	for (int i = 1; i <= 18; i++) ans2 += aa(i, D, c);
	return !printf("%lld\n", ans * ans2);
}