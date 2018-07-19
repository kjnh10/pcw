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

char in[2050][2050];
int dp[2050][2050];

int r[2050];
int sz[2050];
int root(int x) {
	return (r[x] == x) ? x : (r[x] = root(r[x]));
}
int mymerge(int a, int b) {
	a = root(a), b = root(b);
	if (a == b) return a;
	r[a] = b;
	sz[b] += sz[a];
	return b;
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s", in[i] + 1);
	
	for (i = 1; i < N; i++) {
		dp[i][M] = 1;
		for (j = M - 1; j >= 1; j--) {
			if ((in[i][j] == in[i + 1][j]) ^ (in[i][j + 1] == in[i + 1][j + 1])) dp[i][j] = 1;
			else dp[i][j] = 1 + dp[i][j + 1];
		}
	}

	int ans = 0;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) r[j] = j, sz[j] = 1;
		vector <pii> Vu;
		for (j = 1; j < N; j++) Vu.emplace_back(dp[j][i], j);
		sort(all(Vu));

		int p = (int)Vu.size() - 1;
		ans = max(ans, M + 1 - i);
		for (j = M; j >= 1; j--) {
			while (p >= 0) {
				if (Vu[p].first < j) break;
				int t = mymerge(Vu[p].second, Vu[p].second + 1);
				ans = max(ans, j * sz[t]);
				p--;
			}
		}
	}
	return !printf("%d\n", ans);
}