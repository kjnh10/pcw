#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

char S[2][100010];
int P[2][100010][2];
int L[2];

void solve(){
	scanf("%s%s", S[0]+1, S[1]+1);
	int q;
	rep(u, 2){
		int N = (int)strlen(S[u] + 1);
		L[u] = N;
		for(int i=1;i<=N;i++){
			int c = (S[u][i] - 'A');
			int d[2] = {};
			d[c] = 1;
			rep(t, 2){
				P[u][i][t] = P[u][i-1][t] + d[t];
			}
		}
	}
	scanf("%d", &q);
	rep(i, q){
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		int x[2][2] = {};
		rep(u, 2)rep(v, 2){
			if(u == 0)x[u][v] = P[u][b][v] - P[u][a-1][v];
			else x[u][v] = P[u][d][v] - P[u][c-1][v];
		}
		int y[2] = {};
		rep(u, 2){
			y[u] = (x[u][0] - x[u][1]) % 3;
			if(y[u] < 0)y[u] += 3;
		}
		if(y[0] == y[1])puts("YES");
		else puts("NO");
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
}