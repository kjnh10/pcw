#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using pint = pair<int, int>;
using tint = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;

#define MAX_N 202020

typedef long long int64;

const int64 mod = 1e9 + 7;

inline int64 extgcd(int64 a, int64 b, int64 &x, int64 &y)
{
  int64 d = a;
  if(b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
  else x = 1, y = 0;
  return d;
}

inline int64 modPow(int64 x, int64 n)
{
  if(n == 0) return 1;
  int64 ret = modPow(x, n/2);
  (ret *= ret) %= mod;
  if(n & 1) (ret *= x) %= mod;
  return ret;
}

inline int64 modInv(int64 a)
{
  return modPow(a, mod - 2);
}

inline int64 modFact(int n)
{
  int64 ret = 1;
  while(n > 1) (ret *= n--) %= mod;
  return ret;
}

inline int64 modComb(int64 n, int64 r)
{
  static int64 fact[MAX_N], invfact[MAX_N];
  if(fact[0] == 0) {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < MAX_N; i++) {
      fact[i] = fact[i-1] * i % mod;
      invfact[i] = modInv(fact[i]);
    }
  }
  if(r < 0 || n < r) return 0;
  return fact[n] * invfact[r] % mod * invfact[n-r] % mod;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n, k;
  cin >> n >> k;
  cout << modComb(n+k-1, k) << endl;

  return 0;
}
