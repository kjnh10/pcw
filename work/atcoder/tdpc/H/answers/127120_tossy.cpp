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

#define INF 2147483600
#define long long long // for codeforces

int main(){
  vector<vector<pair<int,int>>> vec(50);
  // color -> [w,v]
  int n,w,c;
  cin>>n>>w>>c;
  rep(i,n){
    int a,b,col;
    cin>>a>>b>>col;
    col--;
    vec[col].pb(mp(a,b));
  }

  vector<vector<int>> dp(c+1,vector<int>(w+1,-INF));
  dp[0][0]=0;
  rep(col,50) if(vec[col].size()>0){
    vector<int> d(w+1,-INF);
    d[0]=0;
    for(auto p : vec[col]){
      int nw = p.fi, nv = p.se;
      for(int i=w; i-nw>=0; i--) if(d[i-nw]>-INF) d[i] = max(d[i], d[i-nw]+nv);
    }
    vector<pair<int,int>> vv;
    rep(i,w+1) if(d[i]>0) vv.pb(mp(i,d[i]));

    vector<vector<int>> nxt(c+1,vector<int>(w+1,-INF));
    rep(i,c) rep(j,w) if(dp[i][j]>-INF){
      nxt[i][j] = max(nxt[i][j], dp[i][j]);
      for(auto p : vv){
        if(j+p.fi<=w) nxt[i+1][j+p.fi] = max(nxt[i+1][j+p.fi], dp[i][j] + p.se);
        else break;
      }
    }
    rep(i,c+1) nxt[i][w] = max(nxt[i][w], dp[i][w]);
    rep(j,w+1) nxt[c][j] = max(nxt[c][j], dp[c][j]);
    swap(nxt, dp);
  }

  int res = 0;
  rep(i,c+1)rep(j,w+1) res = max(res, dp[i][j]);
  cout<<res<<endl;

  return 0;
}
