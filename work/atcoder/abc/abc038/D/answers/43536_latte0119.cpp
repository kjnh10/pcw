#include<bits/stdc++.h>
using namespace std;

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
vector<pint>A;
const int INF=1001001001;
int dp[100010];
signed main(){
    cin>>N;
    A.resize(N);
    rep(i,N)cin>>A[i].first>>A[i].second,A[i].second*=-1;
    sort(all(A));
    fill_n(dp,100010,INF);
    dp[0]=0;

    for(int i=0;i<N;i++){
        A[i].second*=-1;
        *lower_bound(dp,dp+100010,A[i].second)=A[i].second;
    }

    for(int i=0;i<100010;i++)if(dp[i]==INF){
        cout<<i-1<<endl;
        return 0;
    }
    return 0;
}
