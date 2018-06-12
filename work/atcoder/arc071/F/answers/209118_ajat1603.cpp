#include "bits/stdc++.h"
using namespace std;
const int N = 2e6 + 6;
const int mod = 1e9 + 7;
int n;
int dp[N + 2];
int sm[N + 2];
int main(){
	scanf("%d" , &n);
	sm[N + 1] = 0;
	for(int i = N ; i > n ; --i){
		dp[i] = 1;
		sm[i] = (sm[i + 1] + dp[i]) % mod;
	}
	dp[n] = n;
	sm[n] = (sm[n + 1] + dp[n]) % mod;
	for(int pos = n - 1 ; pos >= 1 ; --pos){
		long long res = 0;
		res += dp[pos + 1];
		res += 1LL * (n - 1LL) * (n - 1LL);
		res += sm[pos + 3] - sm[pos + n + 2];
		res %= mod;
		res += mod;
		res %= mod;
		dp[pos] = res;
		sm[pos] = (sm[pos + 1] + res) % mod;
	}
	printf("%d\n" , dp[1]);
}