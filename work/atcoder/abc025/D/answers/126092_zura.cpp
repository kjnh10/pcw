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

#define INF INT_MAX/3
#define MAX_N 1000000001
#define MOD 1000000007

int dfs(int, int);
bool ok(int, int);

vector<int> dp(1 << 25, -1);
vector<int> position(26, -1);
vector<int> canfill;

int main(){
  cin.sync_with_stdio(false);
  rep(i, 25) {
    int tmp;
    cin >> tmp;
    if (tmp != 0) {
      position[tmp] = i;
    } else {
      canfill.pb(i);
    }
  }

  print(dfs(0, 1));

  return 0;
}

int dfs(int i, int r) {
  if (i == (1 << 25) - 1) return 1;
  if (dp[i] != -1) return dp[i];

  ll ret = 0;
  if (position[r] != -1) {
    if (ok(i, position[r])) {
      ret = dfs(i | (1 << position[r]), r + 1);
    }
  } else {
    rep(j, canfill.size()) {
      int k = canfill[j];
      if (ok(i, k)) {
        ret += dfs(i | (1 << k), r + 1);
        ret %= MOD;
      }
    }
  }
  return (dp[i] = ret % MOD);
}

bool ok(int i, int pos) {
  if ((i >> pos) & 1) return false;
  if (0 < pos % 5 && pos % 5 < 4 && ((i >> (pos + 1)) & 1) != ((i >> (pos - 1)) & 1)) return false;
  if (4 < pos && pos < 20 && ((i >> (pos + 5)) & 1) != ((i >> (pos - 5)) & 1)) return false;
  return true;
}