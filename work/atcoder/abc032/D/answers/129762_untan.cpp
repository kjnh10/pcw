#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<functional>
#include<numeric>
#include<sstream>
#include<math.h>
#include <iomanip>
#define ll long long
#define PLL pair<ll,ll>
#define VS vector<string>
#define VL vector<ll>
#define VB vector<bool>
#define VPLL vector<pair<ll,ll> >
#define VVL vector<vector<ll> >
#define VVVL vector<vector<vector<ll> > >
#define VVB vector<vector<bool> >
#define rep(i,a) for (ll i=0;i<a;i++)
#define nrep(i,n,a) for (ll i=n;i<a;i++)
#define mrep(i,a) for(ll i=a;i>=0;i--)
#define INF 1000000000000000000
#define PI 3.141592653589793238
#define vmin(vec) *std::min_element(vec.begin(),vec.end())
#define vmax(vec) *std::max_element(vec.begin(),vec.end())
#define vsum(vec) std::accumulate(vec.begin(),vec.end(),0LL)
#define ksort(vec) sort(vec.begin(), vec.end(), greater<ll>())
#define ssort(vec) (vec.begin(),vec.end())
#define VPLLsort(vec) sort(vec.begin(), vec.end(),[](PLL &a, PLL &b){ return a.first < b.first; });
#define LTS(n) to_string(n)
#define STL(str) stoll(str)
using namespace std;

ll n, W, V;

ll dfs(VVL &dp, VL &v, VL &w, ll index, ll weight){
	if (index == n) return 0;
	if (weight > W) return 0;
	if (dp[index][weight] != -1) return dp[index][weight];
	if (weight + w[index] <= W){
		return dp[index][weight] = max(dfs(dp, v, w, index + 1, weight + w[index]) + v[index], dfs(dp, v, w, index + 1, weight));
	}
	else{
		return dp[index][weight] = dfs(dp, v, w, index + 1, weight);
	}
}

ll dfs(VL &v, VL &w, ll index, ll weight){
	if (index == n) return 0;
	if (weight > W) return 0;
	if (weight + w[index] <= W){
		return max(dfs(v, w, index + 1, weight + w[index]) + v[index], dfs(v, w, index + 1, weight));
	}
	else{
		return dfs(v, w, index + 1, weight);
	}
}


int main() {
	cin >> n >> W;
	ll ans;
	V = 0;
	bool case2 = true;
	bool case3 = true;
	VL v(n), w(n);
	rep(i, n){
		cin >> v[i] >> w[i];
		if (w[i] > 1000) case2 = false;
		if (v[i] > 1000) case3 = false;
		V += v[i];
	}
	if (n <= 30 && W >= 100000){
		ans = dfs(v, w, 0, 0);
		cout << ans << endl;
	}
	else if (W <= 100000 || case2){
		VVL dp(n + 1, VL(W + 1, -1));
		ans = dfs(dp, v, w, 0, 0);
		cout << ans << endl;
	}
	else if (case3){
		VVL dp(n + 1, VL(V + 1));

		dp[0][0] = 0;
		nrep(i, 1, V+1) dp[0][i] = INF;
		nrep(i, 1, n+1) rep(j, V+1) {
			if (j < v[i-1]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i-1]] + w[i-1]);
			}
		}

		ans = 0;
		nrep(i, 1, V+1) if (dp[n][i] <= W) ans = i;
		cout << ans << endl;
	}
	return 0;
}