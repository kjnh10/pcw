#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

typedef long long ll;
typedef vector<int> vi;
const ll MOD = 1000000007ll;

int f[26];

ll fact[2521];
ll inv(ll a){
    ll b=MOD-2;
    ll r=1;
    while(b){
        if(b&1)r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}
ll comb(ll a,ll b){
    if(b<0||b>a)return 0ll;
    return fact[a]*inv(fact[b])%MOD*inv(fact[a-b])%MOD;
}
ll perm(ll a,ll b){
    if(b<0||b>a)return 0ll;
    return fact[a]*inv(fact[b])%MOD;
}

// bunkatu[i][j][k] := iの分割、j個で、1の数がk個の通り数(重複順列計算済み)
ll bunkatu[11][11];
void dfs(int n,vi V,int upper,int rest){
    if(rest==0){
        ll add = fact[V.size()];
        int cont = 1;
        FOR(i,1,V.size()){
            if(V[i-1]==V[i])cont++;
            else{
                add = add * inv(fact[cont]) % MOD;
                cont = 1;
            }
        }
        add = add * inv(fact[cont]) % MOD;
        (bunkatu[n][V.size()] += add) %= MOD;
    }else{
        for(int x=1;x<=min(upper,rest);x++){
            V.push_back(x);
            dfs(n,V,x,rest-x);
            V.pop_back();
        }
    }
}

// dp[_][i][j] := i needed, j completed
ll dp[2][262][262];

int main(){
    REP(i,26)cin>>f[i];
    // precalc
    fact[0] = 1;
    FOR(i,1,2521)fact[i]=fact[i-1]*i%MOD;
    REP(i,11){
        vi V;
        dfs(i,V,i,i);
    }
    int cur = 0;
    dp[cur][0][1] = 1;
    REP(fi,26){
        int g = f[fi];
        if(g==0)continue;
        // cout << "g:" << g << endl;
        REP(i,262)REP(j,262)dp[cur^1][i][j]=0;
        REP(i,262)REP(j,262)if(dp[cur][i][j]){
            // cout << "  i:"<<i<<",j:"<<j<<" -> "<<dp[cur][i][j]<<endl;
            REP(toi,g+1){
                int toj = g-toi;
                REP(szi,toi+1)if(szi<=i){
                    REP(szj,toj+1)if(szj<=j){
                        int ni = i - szi + (g-szi-szj);
                        int nj = j + szj + szi*2;
                        ll mul = comb(i,szi) * comb(j,szj) % MOD;
                        (dp[cur^1][ni][nj] += mul * dp[cur][i][j] % MOD * bunkatu[toi][szi] % MOD * bunkatu[toj][szj] % MOD) %= MOD;
                    }
                }
            }
        }
        cur ^= 1;
    }
    ll ans = 0;
    REP(i,262)ans += dp[cur][0][i];
    cout << ans << endl;
}
