#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,X,D;
int M[55];
vint G[55];

vpint A;
int sumM[55],sz[55];
void dfs(int v){
    sumM[v]=M[v];
    sz[v]=1;
    for(auto u:G[v]){
        dfs(u);
        sumM[v]+=sumM[u];
        sz[v]+=sz[u];
    }
    A.pb({sumM[v],sz[v]});
}

int dp[55][55*55*55];
const int INF=1001001001001001001ll;

signed main(){
    cin>>N>>X>>D;
    cin>>M[0];
    for(int i=1;i<N;i++){
        cin>>M[i];
        int p;cin>>p;
        p--;
        G[p].pb(i);
    }

    dfs(0);

    rep(i,A.size()){
        for(int j=i+1;j<A.size();j++){
            if(A[i].fi*A[j].se>A[j].fi*A[i].se)swap(A[i],A[j]);
        }
    }

    fill_n(*dp,55*55*55*55,INF);
    dp[0][0]=0;
    rep(i,N){
        rep(j,55*55*55){
            for(int k=0;k<=50&&k<=D&&j+k*A[i].se<55*55*55;k++)chmin(dp[i+1][j+k*A[i].se],dp[i][j]+A[i].fi*k);
        }
    }

    int ans=0;
    for(int i=0;i<55*55*55;i++){
        int x=X-dp[N][i];
        if(x<0)continue;
        int sum=i;
        for(int j=0;j<N;j++){
            int w=x/A[j].fi;
            if(A[j].se!=N)chmin(w,max(0ll,D-50));
            sum+=A[j].se*w;
            x-=A[j].fi*w;
        }
        chmax(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
