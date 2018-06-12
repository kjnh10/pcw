#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 5005;
const int mod = 1e9 + 7;

lint ipow(lint x, lint p){
	lint ret = 1, piv = x % mod;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret % mod;
}
typedef pair<int, int> pi;

vector<int> gph[MAXN];
int sz[MAXN], msz[MAXN];

void dfs(int x, int p){
	sz[x] = 1;
	for(auto &i : gph[x]){
		if(i != p){
			dfs(i, x);
			sz[x] += sz[i];
			msz[x] = max(msz[x], sz[i]);
		}
	}
}

int cnt[MAXN];
int n, c;

void dfs2(int x, int p, int c){
	cnt[c]++;
	for(auto &i : gph[x]){
		if(i != p){
			dfs2(i, x, c);
		}
	}
}

int dp[MAXN][MAXN];
lint fact[MAXN], invf[MAXN];

int solve(int y, int i){
	lint ans = (fact[y] * invf[y - i] % mod) * (fact[y] * invf[y - i] % mod);
	ans %= mod;
	ans *= invf[i];
	ans %= mod;
	if(i % 2 == 1) ans = (mod - ans) % mod;
	return ans;
}

int f(int x, int y){
	if(x == c+1) return fact[y];
	if(~dp[x][y]) return dp[x][y];
	lint ret = f(x+1, y);
	for(int i=1; i<=cnt[x]; i++){
		ret += 1ll * f(x+1, y-i) * solve(cnt[x], i) % mod;
		ret %= mod;
	}
	return dp[x][y] = ret;
}

void solve(int r){
	fact[0] = 1;
	for(int i=1; i<=n; i++) fact[i] = 1ll * i * fact[i-1] % mod;
	for(int i=0; i<=n; i++) invf[i] = ipow(fact[i], mod - 2);
	for(auto &i : gph[r]){
		dfs2(i, r, ++c);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(1, n));
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, 0);
	pi cen(1e9, 0);
	for(int i=1; i<=n; i++){
		int cur = max(msz[i], n - sz[i]);
		cen = min(cen, pi(cur, i));
	}
	solve(cen.second);
}
