#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 214748360

// Strongly Connected Components O(E + V)
class SCC {
public:
  vector<vector<int>> &G;
  vector<vector<int>> &rG;
  vector<bool> used;
  vector<int> vs;
  vector<int> cmp; // 頂点iが属するSCCのID
  int gc = 0; // group count
  vector<vector<int>> groups; // ID-iのSCCに属する頂点集合, SCCでトポロジカル順になる
  int n;
  void dfs(int v){
    used[v] = true;
    for(auto to : G[v]) if(!used[to]) dfs(to);
    vs.pb(v);
  }
  void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;
    groups[k].pb(v);
    for(auto to : rG[v]) if(!used[to]) rdfs(to, k);
  }
  // グラフと逆向きグラフから強連結成分分解をおこなう
  SCC(vector<vector<int>> &g, vector<vector<int>> &r) : G(g), rG(r){
    n = G.size();
    used = vector<bool>(n,false);
    cmp.resize(n);
    rep(i,n) if(!used[i]) dfs(i);
    fill(all(used), false);
    for(int i = vs.size()-1; i>=0; i--) if(!used[vs[i]]){
      groups.pb(vector<int>());
      rdfs(vs[i], gc++);
    }
  }
  inline bool same(int i, int j){ return cmp[i]==cmp[j]; }
};

int main(){
  int n;
  cin>>n;
  vector<vector<int>> v(n,vector<int>(n));
  rep(i,n)rep(j,n) cin>>v[i][j];

  vector<vector<int>> vec(n,vector<int>());
  vector<vector<int>> rev(n,vector<int>());
  rep(i,n)rep(j,n) if(v[i][j]){
    vec[i].pb(j);
    rev[j].pb(i);
  }

  SCC scc(vec,rev);

  // rebuild DAG
  int m = scc.gc;
  vector<vector<int>> dag(m,vector<int>());
  rep(i,n) for(auto to : vec[i]) if(scc.cmp[i] != scc.cmp[to]) dag[scc.cmp[i]].pb(scc.cmp[to]);
  rep(i,m) uniq(dag[i]);

  vector<vector<int>> reach(m, vector<int>(m, false));
  // reach[i][j] scc[i] からscc[j]へ到達可能か．

  // build reach[i][j] O(V*E)?
  vector<bool> visited(m, false);
  function<void(int)> dfs = [&](int d){
    visited[d]=true;
    for(auto to : dag[d]){
      reach[d][to] = true;
      if(!visited[to]) dfs(to);
      rep(i,m) reach[d][i] |= reach[to][i];
    }
  };
  rep(i,m) if(!visited[i]) dfs(i);

  vector<vector<int>> dp(m, vector<int>(m,0));
  // [i][j] のsccにいる

  rep(i,m)rep(j,i){
    dp[i][j] = scc.groups[i].size() + scc.groups[j].size();
  }
  rep(i,m) dp[i][i] = scc.groups[i].size();

  rep(i,m) rep(j,i){ // 常にiが大きい
    rep(k,m){
      if(j<k && k<i && reach[j][k] && !reach[k][i]) dp[i][k] = max<int>(dp[i][k], dp[i][j] + scc.groups[k].size());
      if(k>i && reach[i][k]) dp[k][j] = max<int>(dp[k][j], dp[i][j] + scc.groups[k].size());
      if(k>i && reach[j][k]) dp[k][i] = max<int>(dp[k][i], dp[i][j] + scc.groups[k].size());
    }
  }
//rep(i,m)dbg(dp[i]);
  int res=0;
  rep(i,m) rep(j,m) res = max<int>(res, dp[i][j]);

  cout << res << endl;

  return 0;
}
