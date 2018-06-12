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

const int INF=1001001001001001001ll;

int N,M;
int G[15][15];
int dp[1<<15][15];

int latte[1<<15];

signed main(){
    cin>>N>>M;
    int ei=0;
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        G[a][b]=G[b][a]=c;
        ei+=c;
    }

    rep(i,1<<N){
        rep(j,N)for(int k=j+1;k<N;k++){
            if(!(i>>j&1))continue;
            if(!(i>>k&1))continue;
            latte[i]+=G[j][k];
        }
    }

    fill_n(*dp,(1<<15)*15,-INF);
    rep(i,1<<N)if(i&1)dp[i][0]=latte[i];

    rep(i,1<<N){
        rep(j,N){
            if(dp[i][j]==-INF)continue;
            int sup=(~i)&((1<<N)-1);
            int sub=sup;
            do{
                rep(k,N){
                    if(!(sub>>k&1))continue;
                    if(G[j][k]==0)continue;
                    chmax(dp[i|sub][k],dp[i][j]+G[j][k]+latte[sub]);
                }
                sub=(sub-1)&sup;
            }while(sub!=sup);
        }
    }

    cout<<ei-dp[(1<<N)-1][N-1]<<endl;
    return 0;
}
