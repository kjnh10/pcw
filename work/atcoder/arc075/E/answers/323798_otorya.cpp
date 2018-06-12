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

int bit[600000];
void update(int p, int v) {
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += v;
}
int getsum(int p) {
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}

ll in[200050];
ll sum[200050];
vector <ll> Vx;
int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		in[i] -= K;
		sum[i] = sum[i - 1] + in[i];
	}
	for (i = 0; i <= N; i++) Vx.push_back(sum[i]);
	sort(all(Vx));
	Vx.erase(unique(all(Vx)), Vx.end());
	
	ll ans = 0;
	for (i = 0; i <= N; i++) {
		int t = lower_bound(all(Vx), sum[i]) - Vx.begin() + 1;
		ans += getsum(t);
		update(t, 1);
	}
	return !printf("%lld\n", ans);
}