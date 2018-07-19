#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;

int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}

int N,C;
int A[444],B[444];

int dp[444][444];

int table[444][444];

signed main(){
    cin>>N>>C;
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];

    for(int i=0;i<=C;i++){
        for(int j=1;j<=400;j++){
            table[i][j]=(table[i][j-1]+mpow(j,i))%mod;
        }
    }

    dp[0][0]=1;
    rep(i,N){
        for(int j=0;j<=C;j++){
            for(int k=0;j+k<=C;k++){
                int tmp=(table[k][B[i]]-table[k][A[i]-1]+mod)%mod;
                dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j]*tmp)%mod;
            }
        }
    }

    cout<<dp[N][C]<<endl;
    return 0;
}
