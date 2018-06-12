#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;
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

lint fact[1005], invf[1005];

int n, a, b, c, d;
int dp[1005][1005];
int bino[1005][1005];
lint prec[1005][1005];

lint partition(int x, int s, int c){
	if(~prec[x][s]) return prec[x][s];
	lint ret = 1;
	for(int i=0; i<c; i++){
		ret *= bino[x - s * i][s];
		ret %= mod;
	}
	return prec[x][s] = ret;
}

int f(int x, int s){
	if(s < a) return x == 0;
	if(~dp[x][s]) return dp[x][s];
	int ret = f(x, s-1);
	if(c * s <= x){
		lint ppart = partition(x, s, c);
		for(int i=c; i<=d && i * s <= x; i++){
			ret += 1ll * f(x - i * s, s - 1) * (ppart * invf[i] % mod) % mod;
			ret %= mod;
			ppart *= bino[x - s * i][s];
			ppart %= mod;
		}
	}
	return dp[x][s] = ret;
}

int main(){
	cin >> n >> a >> b >> c >> d;
	memset(dp, -1, sizeof(dp));
	memset(prec, -1, sizeof(prec));
	for(int i=0; i<=n; i++){
		bino[i][0] = 1;
		for(int j=1; j<=i; j++){
			bino[i][j] = (bino[i-1][j-1] + bino[i-1][j]) % mod;
		}
	}
	fact[0] = invf[0] = 1;
	for(int i=1; i<=n; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] =ipow(fact[i], mod-2);
	}
	cout << f(n, b);
}

