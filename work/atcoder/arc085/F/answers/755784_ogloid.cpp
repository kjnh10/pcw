#define DEB
#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

const int INF=5e8;

int n,q;
int br[200005];
int bsum[200005];
pi R[200005];
vector<int> Rend[200005];


int dp[200005];
int count0(int l,int r){
  return r-l-(bsum[r]-bsum[l]);
}
struct segtree{
  int val[800005];
  int n;
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n*2) val[i]=INF;
  }
  void set(int k,int a){
    a+=count0(k,::n);
    k+=n-1;
    chmin(val[k],a);
    while(k>0){
      k=(k-1)/2;
      chmin(val[k],a);
    }
  }
  int query(int a,int b,int i,int l,int r){
    if(a<=l && r<=b) return val[i];
    if(b<=l || r<=a) return INF;
    int md=(l+r)>>1;
    return min(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
  }
  int query(int l,int k){
    int res=query(l,k+1,0,0,n);
    return res-count0(k,::n);
  }
};


segtree seg;
int main(){
  cin>>n;
  REP(i,n){
    scanf("%d",&br[i]);
    bsum[i+1]=br[i]+bsum[i];
  }
  cin>>q;
  REP(i,q){
    scanf("%d%d",&R[i].fr,&R[i].sc);
    --R[i].fr;
    Rend[R[i].fr].pb(R[i].sc);
  }
  seg.init(n);
  REP(i,n+1) dp[i]=INF;

  dp[0]=0;
  seg.set(0,0);
  REP(i,n+1){
    for(auto r:Rend[i]){
      int tmp=seg.query(i,r);
      int val=min(dp[i]+count0(i,r),tmp);
      chmin(dp[r],val);
      seg.set(r,val);
    }
    chmin(dp[i+1],dp[i]+(br[i]));
  }
  cout<<dp[n]<<endl;
  return 0;
}



