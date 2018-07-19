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

int in[100050][2];

int u[100050];

int r[100050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
vector <pair<ll, pii>> Vu;
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	for (i = 1; i <= N; i++) u[i] = r[i] = i;
	sort(u + 1, u + N + 1, [](int a, int b) {
		return in[a][0] < in[b][0];
	});
	for (i = 1; i < N; i++) Vu.emplace_back(in[u[i + 1]][0] - in[u[i]][0], pii(u[i], u[i + 1]));
	sort(u + 1, u + N + 1, [](int a, int b) {
		return in[a][1] < in[b][1];
	});
	for (i = 1; i < N; i++) Vu.emplace_back(in[u[i + 1]][1] - in[u[i]][1], pii(u[i], u[i + 1]));

	sort(all(Vu));
	ll ans = 0;
	for (auto it : Vu) {
		if (root(it.second.first) == root(it.second.second)) continue;
		ans += it.first;
		r[root(it.second.first)] = root(it.second.second);
	}
	return !printf("%lld\n", ans);
}