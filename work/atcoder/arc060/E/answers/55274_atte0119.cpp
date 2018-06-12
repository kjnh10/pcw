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

int N;
int X[100000];
int L;

int to[20][100000];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&X[i]);
    scanf("%lld",&L);
    rep(i,N){
        int lb=i,ub=N;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(X[mid]<=X[i]+L)lb=mid;
            else ub=mid;
        }
        to[0][i]=lb;
    }

    rep(i,19){
        rep(j,N){
            to[i+1][j]=to[i][to[i][j]];
        }
    }

    int Q;scanf("%lld",&Q);
    while(Q--){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        if(a>b)swap(a,b);
        int ans=0;
        for(int i=19;i>=0;i--){
            if(to[i][a]<b){
                ans+=(1<<i);
                a=to[i][a];
            }
        }
        printf("%lld\n",ans+1);
    }
    return 0;
}
