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

int N;
int A[111111];
int dp[111111];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];
    fill_n(dp,111111,1001001001);
    dp[0]=0;
    for(int i=0;i<N;i++){
        for(int j=1;j<=2;j++){
            if(i+j>=N)break;
            chmin(dp[i+j],dp[i]+abs(A[i+j]-A[i]));
        }
    }
    cout<<dp[N-1]<<endl;
    return 0;
}
