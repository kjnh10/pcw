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
#define MOD (ll)(1e9 + 7)

ll factInv(ll);

int main(){
  cin.sync_with_stdio(false);
  ll a, b, c;
  cin >> a >> b >> c;

  ll ab = (a * b) % MOD, ac = (a * c) % MOD, bc = (b * c) % MOD;

  ll cc = ((bc - ab) % MOD) * factInv((ac - bc + ab) % MOD) % MOD;
  if (cc < 0) cc += MOD;
  ll rr = ((bc - ac) % MOD) * factInv((ab - bc + ac) % MOD) % MOD;
  if (rr < 0) rr += MOD;

  cout << rr << " " << cc << endl;

  return 0;
}

ll factInv(ll x) {
  ll res = 1;
  ll n = MOD - 2;
  while(n > 0) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}