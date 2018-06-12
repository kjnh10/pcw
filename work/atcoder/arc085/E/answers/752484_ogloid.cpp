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

const lint INF=1e18;

int src,sink;
static const int MAX_SIZE=105;
struct edge{
  int to;
  lint cap;
  int rev;
  edge(int st,lint sc,int sr){
    to=st;cap=sc;rev=sr;
  }
};
vector<edge> g[MAX_SIZE];
int rankk[MAX_SIZE],seen[MAX_SIZE];
void add_edge(int from,int to,lint cap){
  g[from].pb(edge(to,cap,g[to].size()));
  g[to].pb(edge(from,0,g[from].size()-1));
}
void bfs(int v){
  memset(rankk,-1,sizeof(rankk));
  rankk[v]=0;
  queue<int>q;q.push(v);
  while(!q.empty()){
    int cur=q.front();q.pop();
    REP(i,g[cur].size()){
      edge& e=g[cur][i];
      if(e.cap>0 && rankk[e.to]==-1){
        rankk[e.to]=rankk[cur]+1;
        q.push(e.to);
      }
    }
  }
}
lint dfs(int v,lint f){
  if(v==sink) return f;
  for(int& i=seen[v];i<g[v].size();++i){
    edge& e=g[v][i];
    if(e.cap>0 && rankk[e.to]>rankk[v]){
      int d=dfs(e.to,min(e.cap,f));
      if(d>0){
        e.cap-=d;
        g[e.to][e.rev].cap+=d;
        return d;
      }
    }
  }
  return 0;
}
lint max_flow(int s,int t){
  src=s;sink=t;
  lint flow=0;
  while(1){
    bfs(src);
    if(rankk[sink]==-1) return flow;
    lint f;
    memset(seen,0,sizeof(seen));
    while((f=dfs(src,INF))>0){
      flow+=f;
    }
  }
}
int n;
int ar[105];

int main(){
  cin>>n;
  int S=n+1,T=n+2;
  lint ans=0;
  for(int i=1;i<=n;++i){
    cin>>ar[i];
    if(ar[i]>0) add_edge(i,T,ar[i]);
    else add_edge(S,i,-ar[i]);
    ans+=max(0,ar[i]);
  }


  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j) if(j%i==0){
      add_edge(i,j,INF);
    }
  }
  ans-=max_flow(S,T);
  cout<<ans<<endl;
  return 0;
}



