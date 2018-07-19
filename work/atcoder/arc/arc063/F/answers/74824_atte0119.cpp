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

const int INF=1001001001001001001ll;
struct segtree{
    static const int SEG=1<<19;
    vector<int>dat,put;
    segtree():dat(SEG*2),put(SEG*2){}

    inline void push(int k){
        dat[k]+=put[k];
        if(k<SEG-1){
            put[k*2+1]+=put[k];
            put[k*2+2]+=put[k];
        }
        put[k]=0;
    }
    void add(int a,int b,int x,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            put[k]=x;
            push(k);
            return;
        }
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
        dat[k]=max(dat[k*2+1],dat[k*2+2]);
    }
    int query(int a,int b,int k=0,int l=0,int r=SEG){
        push(k);
        if(r<=a||b<=l)return -INF;
        if(a<=l&&r<=b)return dat[k];
        return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
    }
};

int W,H,N;
int X[333333],Y[333333];

int ans;

void solve(){
    vector<pint>ps;
    rep(i,N)ps.pb({X[i],Y[i]});
    sort(all(ps));

    vector<int>xs={0};
    rep(i,N)if(ps[i].fi)xs.pb(ps[i].fi);

    stack<pint>up,dw;
    up.push({0,H/2});
    dw.push({0,H/2});
    rep(i,N)ps[i].fi=lower_bound(all(xs),ps[i].fi)-xs.begin();

    segtree seg;
    for(int i=0;i<xs.size();i++)seg.add(i,i+1,-xs[i]);
    rep(i,N){
        seg.add(up.top().fi,ps[i].fi,H/2);
        seg.add(dw.top().fi,ps[i].fi,H/2);
        chmax(ans,xs[ps[i].fi]+seg.query(0,ps[i].fi));
        seg.add(up.top().fi,ps[i].fi,-H/2);
        seg.add(dw.top().fi,ps[i].fi,-H/2);
        if(ps[i].se<=H/2){
            while(up.top().se<ps[i].se){
                pint p=up.top();
                up.pop();
                seg.add(up.top().fi,p.fi,-(H/2-p.se));
            }
            seg.add(up.top().fi,ps[i].fi,H/2-ps[i].se);
            up.push(ps[i]);
        }
        else{
            while(dw.top().se>ps[i].se){
                pint p=dw.top();
                dw.pop();
                seg.add(dw.top().fi,p.fi,-(p.se-H/2));
            }
            seg.add(dw.top().fi,ps[i].fi,ps[i].se-H/2);
            dw.push(ps[i]);
        }
    }

    seg.add(up.top().fi,xs.size(),H/2);
    seg.add(dw.top().fi,xs.size(),H/2);
    chmax(ans,W+seg.query(0,xs.size()));
}

signed main(){
    cin>>W>>H>>N;
    rep(i,N)cin>>X[i]>>Y[i],X[i]*=2,Y[i]*=2;
    W*=2;H*=2;

    rep(t,2){
        solve();
        swap(H,W);
        rep(i,N)swap(X[i],Y[i]);
    }

    cout<<ans<<endl;
    return 0;
}
