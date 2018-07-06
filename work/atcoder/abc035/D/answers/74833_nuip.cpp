#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
const ll MOD=1e9+7;
//--------------------
typedef ll Cost;
struct Edge{int to,cap,rev;Cost cost;};
typedef vector<Edge> Edges;
typedef vector<vector<Edge> > Graph;
typedef pair<Cost,int> Que;
Cost INF=1e15;

void add_edge(Graph &g,int from,int to,int cap,Cost cost=0){
  g[from].pb((Edge){to,cap,(int)g[to].size(),cost});
  //g[to].pb((Edge){from,0,(int)g[from].size()-1,-cost});
}
//dij

void dij(Graph &g,int s,vector<Cost> &d){
  priority_queue<Que,vector<Que>,greater<Que> > que;
  int V=g.size();
  d.resize(V);
  fill(all(d),INF);
  d[s]=0;
  que.push(Que(0,s));
  while(!que.empty()){
    Que p=que.top();que.pop();
    int v=p.Y;
    if(d[v]<p.X)continue;
    for(int i=0;i<g[v].size();i++){
      Edge e=g[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to]=d[v]+e.cost;
        que.push(Que(d[e.to],e.to));
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m,t;
  cin>>n>>m>>t;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  Graph g(n),h(n);
  int x,y,z;
  rep(i,m){
    cin>>x>>y>>z; --x; --y;
    add_edge(g,x,y,0,z);
    add_edge(h,y,x,0,z);
  }
  vector<ll> d1,d2;
  dij(g,0,d1);
  dij(h,0,d2);
  ll re=0;
  rep(i,n) re=max(re,max(0ll,t-d1[i]-d2[i])*a[i]);
  cout<<re<<endl;
  return 0;
}
