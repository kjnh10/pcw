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

struct UF{
    vint par;
    vint sz;
    void init(int n){
        par.resize(n);
        sz.resize(n,1);
        rep(i,n)par[i]=i;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        sz[x]+=sz[y];
        par[y]=x;
    }
};

int N,M;
int ans[100000];
signed main(){
    cin>>N>>M;
    vector<tuple<int,int,int>>vec;
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        vec.pb(make_tuple(-c,a,b));
    }

    int Q;cin>>Q;
    rep(i,Q){
        int v,w;
        cin>>v>>w;
        v--;
        vec.pb(make_tuple(-w,i-1001001001,v));
    }
    sort(all(vec));
    UF uf;uf.init(N);
    rep(i,vec.size()){
        if(get<1>(vec[i])<0){
            int v,w,idx;
            tie(w,idx,v)=vec[i];
            w=-w;
            idx+=1001001001;
            ans[idx]=uf.sz[uf.find(v)];
        }
        else{
            int c,a,b;
            tie(c,a,b)=vec[i];
            uf.unite(a,b);
        }
    }

    rep(i,Q)printf("%lld\n",ans[i]);
    return 0;
}
