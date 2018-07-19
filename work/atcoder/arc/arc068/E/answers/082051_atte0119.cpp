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

struct BIT{
    int N;
    vector<int>dat;
    void init(int n){
        N=n;
        dat.resize(N+1);
    }
    BIT(){}
    BIT(int n){init(n);}

    void add(int k,int x){
        for(k++;k<=N;k+=k&-k)dat[k]+=x;
    }
    int sum(int k){
        int ret=0;
        for(k++;k;k-=k&-k)ret+=dat[k];
        return ret;
    }
};

int N,M;
vint lis[111111];

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N){
        int l,r;
        scanf("%lld%lld",&l,&r);
        r++;
        lis[r-l].pb(l);
    }

    BIT bit;bit.init(M+114);
    int latte=N;
    for(int d=1;d<=M;d++){
        for(auto l:lis[d]){
            int r=l+d;
            bit.add(r,-1);bit.add(l,1);
        }
        latte-=lis[d].size();
        int ans=latte;
        for(int x=d;x<=M;x+=d)ans+=bit.sum(x);
        printf("%lld\n",ans);
    }
    return 0;
}
