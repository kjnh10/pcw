#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

const lli MOD = 1000000007;
lli pow(lli a,lli n,lli mod = 1000000007){
	lli ret = 1;
	for(;n!=0;n=n>>1){
		if(n&1) ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret;
}
lli invarse(lli x){
	return pow(x,MOD-2);
}


lli factrial(lli x){
	static lli dp[100001];
	if(dp[x]) return dp[x];
	if(x == 0) 	return dp[x] = 1;
				return dp[x] = (factrial(x-1) * x) % MOD;
}

lli combination(lli n,lli k){
    return (((factrial(n) * invarse(factrial(k))) % MOD) * invarse(factrial(n-k))) % MOD;
}


lli n,m;
vll d;
mat dp;
lli u;
vll ans;
vll ans_;
bool f;
int main(){
    cin >> n >> m;
    if(n < 0) n = abs(n),f = true;
    lli i;
    for(i = 1;i*i < n;i++){
        if(n % i == 0) d.push_back(i),d.push_back(n/i);
    }
    if(i*i == n) d.push_back(i);
    sort(d.begin(),d.end());
    i = 0;
    for(lli t = 1;t < m;i++) t <<= 1;
    u = i+1;
    dp = mat(u,vll(d.size()));
    for(lli i = 0;i < d.size();i++) dp[0][i] = 1;
    for(lli i = 0;i < u-1;i++){
        for(lli j = 0;j < d.size();j++){
            for(lli k = 0;k < d.size();k++){
                lli mul = d[j]*d[k];
                lli t = lower_bound(d.begin(),d.end(),mul) - d.begin();
                if(t == d.size()) break;
                if(d[t] == mul) dp[i+1][t] += (dp[i][j]*dp[i][k]) % MOD,dp[i+1][t] %= MOD;
            }
        }
    }
    ans = vll(d.size(),0);
    lli m_ = m;
    for(lli i = 0;m_ > 0;m_ >>= 1,i++){
        if(m_ & 1){
            if(ans.back() == 0){
                for(lli j = 0;j < d.size();j++){
                    ans[j] = dp[i][j];
                }
                continue;
            }
            ans_ = vll(d.size(),0);
            for(lli j = 0;j < d.size();j++){
                for(lli k = 0;k < d.size();k++){
                    lli mul = d[j]*d[k];
                    lli t = lower_bound(d.begin(),d.end(),mul) - d.begin();
                    if(t == d.size()) break;
                    if(d[t] == mul) ans_[t] += (ans[j]*dp[i][k]) % MOD,ans_[j] %= MOD;
                }
            }
            swap(ans,ans_);
        }
    }
    lli c = 0;
    for(lli i = (f ? 1 : 0);i <= m;i += 2){
        c += combination(m,i);
        c %= MOD;
    }
    cout << ans.back()*c % MOD << endl;

}