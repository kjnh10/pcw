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
#define VVB vector<vector<bool> >
#define rep(i,a) for (ll i=0;i<a;i++)
#define nrep(i,n,a) for (ll i=n;i<a;i++)
#define mrep(i,a) for(ll i=a;i>=0;i--)
#define INF 1145141919810
#define VMIN(vec) *std::max_element(vec.begin(),vec.end())
#define VMIN(vec) *std::max_element(vec.begin(),vec.end())
#define VSUM(vec) std::accumulate(vec.begin(),vec.end(),0LL)
#define LTS(n) to_string(n)
#define STL(str) stoll(str)

using namespace std;

ll mod = 1e9 + 7;
ll d, l;

ll solv(ll x, ll y,VVL &dp, VVL &comb){
	if (x*y == d + l) return comb[d + l][d];
	if (x*y < d + l) return 0;
	if (dp[x][y]!=-1) return dp[x][y];
	ll res = (comb[x*y][d + l] * comb[d + l][d])%mod;
	rep(i, x) rep(j, y){
		if (!i && !j) continue;
		res -= (i + 1)*(j + 1)*solv(x - i, y - j,dp, comb);
		res = (res%mod + mod) % mod;
	}return dp[x][y] = res;
}

int main() {
	ll r, c, x, y;
	cin >> r >> c >> x >> y >> d >> l;
	VVL comb(r*c + 1, VL(r*c + 1,1));
	nrep(i, 2, r*c + 1) nrep(j, 1, i) comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1])%mod;
	VVL dp(x + 1, VL(y + 1, -1));
	ll res = solv(x, y,dp, comb);
	res = (r - x + 1)*(c - y + 1)*res;
	res %= mod;
	cout << res << endl;
	return 0;
}

