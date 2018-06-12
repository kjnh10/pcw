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

const int MOD = 1e9 + 7;
int D[1000010];
ll S[1000010];

void solve(){
	int n; scanf("%d", &n);
	D[0] = 1; D[1] = n;
	S[0] = 1; S[1] = n + 1;
	for(int i=2;i<=n;i++){
		D[i] = ((ll)(n-1) * (i-2) + (ll)(n - i + 1) * n + D[i-1] + (i>=3?S[i-3]:0)) % MOD;
		S[i] = (S[i-1] + D[i]) % MOD;
	}
	printf("%d\n", D[n]);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
}