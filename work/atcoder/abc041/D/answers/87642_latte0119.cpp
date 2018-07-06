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

int N,M;
int G[16][16];
int dp[1<<16];
signed main(){
    cin>>N>>M;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a][b]=1;
        G[b][a]=-1;
    }

    dp[0]=1;
    for(int i=0;i<1<<N;i++){
        for(int j=0;j<N;j++){
            if(i>>j&1)continue;
            bool ok=true;
            rep(k,N){
                if(!(i>>k&1))continue;
                if(G[k][j]==-1)ok=false;
            }
            if(!ok)continue;
            dp[i|(1<<j)]+=dp[i];
        }
    }
    cout<<dp[(1<<N)-1]<<endl;
    return 0;
}
