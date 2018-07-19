#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

const int mod=1000000007;

int N;
vint G[111111];

int dp1[111111],dp2[111111];
void dfs(int v,int p){
    dp1[v]=dp2[v]=1;
    for(auto to:G[v]){
        if(to==p)continue;
        dfs(to,v);
        dp1[v]=dp1[v]*dp2[to]%mod;
        dp2[v]=dp2[v]*(dp1[to]+dp2[to])%mod;
    }
}

signed main(){
    cin>>N;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(0,-1);
    cout<<(dp1[0]+dp2[0])%mod<<endl;
    return 0;
}
