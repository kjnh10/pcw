#include <cstdio>
#include <map>
#include <cstdlib>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define ITR(c,it)  for(auto it = c.begin(); it != c.end(); it++)

typedef long long ll;

//------------------------------------------------------------------------------
map<int, int> prime_factor(int n) {
  map<int, int> res;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        res[i]++;
        n /= i;
      }
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

ll mod_inverse(ll x, ll mod) {
  return mod_pow(x, mod - 2, mod);
}

ll mod_comb(ll n, ll k, ll mod) {
  if (n < 0 || k < 0 || n < k) return 0;
  ll a = 1, b = 1;
  while(k > 0) {
    a = a * n-- % mod;
    b = b * k-- % mod;
  }
  return a * mod_inverse(b, mod) % mod;
}

//------------------------------------------------------------------------------
const int MOD = 1000000007;

int N, M;

void solve() {
  ll ans = 1;
  map<int, int> pf = prime_factor(abs(N));
  ITR(pf, it) {
    int k = it->second;
    ans = ans * mod_comb(M + k - 1, k, MOD) % MOD;
  }
  ans = ans * mod_pow(2, M - 1, MOD) % MOD;
  printf("%lld\n", ans);
}

void input() {
  scanf("%d%d", &N, &M);
}

int main() {
  input();
  solve();
  return 0;
}
