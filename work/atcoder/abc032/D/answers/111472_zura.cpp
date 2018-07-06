#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX
#define MAX_N 1000000001

void solve1();
void solve2();
void solve3();

int n, w;
vector<PL> v;

int main(){
  cin.sync_with_stdio(false);
  cin >> n >> w;

  if(n <= 30) {
    solve1();
  } else {
    bool ww = true;
    rep(i, n) {
      ll a, b;
      cin >> a >> b;
      if (b > 1000) ww = false;
      v.pb(PL(a, b));
    }
    if (ww) solve2();
    else solve3();
  }

  return 0;
}

void solve1() {
  vector<PL> a;
  a.pb(PL(0, 0));
  rep(i, n/2) {
    ll vi, wi;
    cin >> vi >> wi;
    if(wi > w) continue;
    repr(j, a.size()) {
      if(a[j].se + wi <= w) a.pb(PL(a[j].fi + vi, a[j].se + wi));
    }
  }

  sort(a.begin(), a.end(), [](PL x, PL y){
    if (x.se == y.se) return x.fi > y.fi;
    return y.se > x.se;
  });

  PL tmp = a[0];
  repl(i, 1, a.size()) {
    if(tmp.fi >= a[i].fi) {
      a.erase(a.begin() + i);
      i--;
    } else {
      tmp = a[i];
    }
  }

  vector<PL> b;
  b.pb(PL(0, 0));
  repl(i, n/2, n) {
    ll vi, wi;
    cin >> vi >> wi;
    if(wi > w) continue;
    repr(j, b.size()) {
      if(b[j].se + wi <= w) b.pb(PL(b[j].fi + vi, b[j].se + wi));
    }
  }

  sort(b.begin(), b.end(), [](PL x, PL y){
    if (x.se == y.se) return x.fi > y.fi;
    return y.se > x.se;
  });

  tmp = b[0];
  repl(i, 1, b.size()) {
    if(tmp.fi >= b[i].fi) {
      b.erase(b.begin() + i);
      i--;
    } else {
      tmp = b[i];
    }
  }

  ll ans = 0, j = a.size() - 1;
  rep(i, b.size()) {
    while(j > 0 && b[i].se + a[j].se > w) j--;
    maxch(ans, b[i].fi + a[j].fi);
  }

  print(ans);
}

void solve2() {
  ll dp[200001] = {};
  rep(i, n) {
    ll vi = v[i].fi, wi = v[i].se;
    repr(j, 200001) {
      if (dp[j] != 0) {
        maxch(dp[j + wi], dp[j] + vi);
      }
    }
    maxch(dp[wi], vi);
  }

  ll ans = 0;
  rep(i, 200001) {
    if(i > w) break;
    maxch(ans, dp[i]);
  }
  print(ans);
}

void solve3() {
  ll dp[200001] = {};
  rep(i, 200001) {
    dp[i] = INF;
  }

  rep(i, n) {
    ll vi = v[i].fi, wi = v[i].se;
    if (wi > w) continue;
    repr(j, 200001) {
      if (dp[j] != INF) {
        minch(dp[j + vi], dp[j] + wi);
      }
    }
    minch(dp[vi], wi);
  }

  repr(i, 200001) {
    if (dp[i] <= w) {
      print(i);
      break;
    }
  }
}