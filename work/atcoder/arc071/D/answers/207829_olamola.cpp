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

int n[2];
int a[2][100010];

const int MOD = 1e9 + 7;

void solve(){
	ll ans = 1;
	scanf("%d%d", n, n+1);
	rep(i, 2)rep(j, n[i])scanf("%d", a[i]+j);
	rep(u, 2){
		ll cnt = 0;
		for(int j=1;j<n[u];j++){
			ll b = (ll)j * (n[u]-j) % MOD;
			b = b * (a[u][j] - a[u][j-1]) % MOD;
			cnt = (cnt + b) % MOD;
		}
		ans = ans * cnt % MOD;
	}
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
}