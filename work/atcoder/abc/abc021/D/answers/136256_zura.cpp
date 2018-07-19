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
#define MAX_N 100001
#define MOD ((ll)1e9 + 7)

ll f[MAX_N], fi[MAX_N];

void factInv(ll x, int i) {
  ll res = 1, n = MOD - 2;
  while(n > 0) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  fi[i] = res;
}

void fact() {
  f[0] = 1;
  factInv(f[0], 0);
  repl(i, 1, MAX_N) {
    f[i] = f[i - 1] * i % MOD;
    factInv(f[i], i);
  }
}

int main(){
  cin.sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;

  fact();

  ll p = ((n > k) ? k + 1 : n + 1);
  ll sum = 0;
  repl(i, 1, p) {
    sum = (sum + ((f[n] * fi[n - i] % MOD) * fi[i] % MOD) *
           ((f[k - 1] * fi[k - i] % MOD) * fi[i - 1] % MOD) % MOD) % MOD;
  }

  print(sum);

  return 0;
}