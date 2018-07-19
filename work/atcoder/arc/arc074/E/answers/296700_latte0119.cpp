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

const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int dp[303][303][303];
int N,M;
int L[333],R[333],X[333];

vpint qs[333];

signed main(){
    cin>>N>>M;
    rep(i,M)cin>>L[i]>>R[i]>>X[i],L[i]--;

    rep(i,M){
        qs[R[i]].pb({L[i],X[i]});
    }

    for(auto t:qs[1]){
        if(t.se!=1){
            cout<<0<<endl;
            return 0;
        }
    }
    dp[1][N][N]=3;
    for(int i=1;i<N;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<=N;k++){
                if(dp[i][j][k]==0)continue;
                if(j==N&&k==N){
                    add(dp[i+1][N][N],dp[i][j][k]);
                    add(dp[i+1][i-1][N],dp[i][j][k]*2%mod);
                }
                else if(k==N){
                    add(dp[i+1][j][N],dp[i][j][k]);
                    add(dp[i+1][i-1][N],dp[i][j][k]);
                    add(dp[i+1][i-1][j],dp[i][j][k]);
                }
                else{
                    add(dp[i+1][j][k],dp[i][j][k]);
                    add(dp[i+1][i-1][k],dp[i][j][k]);
                    add(dp[i+1][i-1][j],dp[i][j][k]);
                }
            }
        }
        for(auto &t:qs[i+1]){
            for(int j=0;j<=N;j++){
                for(int k=0;k<=N;k++){
                    if(dp[i+1][j][k]==0)continue;
                    if(t.se==3){
                        if(k==N||t.fi>k)dp[i+1][j][k]=0;
                    }
                    else if(t.se==2){
                        if(j==N||t.fi>j||(k!=N&&t.fi<=k))dp[i+1][j][k]=0;
                    }
                    else if(t.se==1){
                        if(j!=N&&t.fi<=j)dp[i+1][j][k]=0;
                    }
                }
            }
        }
    }

    int ans=0;
    rep(i,N+1)rep(j,N+1)add(ans,dp[N][i][j]);
    cout<<ans<<endl;
    return 0;
}
