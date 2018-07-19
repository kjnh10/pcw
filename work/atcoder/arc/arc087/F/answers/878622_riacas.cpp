#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;
const int mod = 1000000007;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll inv(ll x) {
  return mpow(x, mod-2);
}

vvi g;
vi sz;
vl fac(10000, 1);
vl invfac(10000, 1);

void dfs(int v, int p) {
  sz[v] = 1;
  for (int nv : g[v]) {
    if (nv == p) continue;
    dfs(nv, v);
    sz[v] += sz[nv];
  }
}

vl mul(const vl & a, const vl & b) {
  vl res(a.size() + b.size() - 1);
  for (int i = 0; i < a.size(); ++i) for (int j = 0; j < b.size(); ++j) {
    res[i+j] = (res[i+j] + a[i] * b[j]) % mod;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 2; i < fac.size(); ++i) {
    fac[i] = fac[i-1] * i % mod;
    invfac[i] = inv(fac[i]);
  }
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    sz.assign(n, 0);
    dfs(i, -1);
    bool ok = 1, eq = 0;
    for (int v : g[i]) {
      if (sz[v] * 2 > n) {
        ok = 0;
      }
      if (sz[v] * 2 == n) eq = 1;
    }
    if (ok) {
      if (eq) {
        ll res = fac[n/2] * fac[n/2] % mod;
        cout << res << endl;
      } else {
        ll prod = 1;
        for (int v : g[i]) prod = prod * mpow(fac[sz[v]], 2) % mod;
        vl res(1, 1);
        for (int v : g[i]) {
          vl x(sz[v] + 1);
          for (int j = 0; j < x.size(); ++j) {
            x[j] = invfac[j] * mpow(invfac[sz[v] - j], 2) % mod;
          }
          res = mul(res, x);
        }
        ll sum = 0;
        for (int j = 0; j < res.size(); ++j) {
          int zn = j % 2 ? -1 : 1;
          sum = (sum + zn * res[j] * fac[n - j]) % mod;
        }
        sum = sum * prod % mod;
        cout << (sum % mod + mod) % mod << endl;
      }
      break;
    }
  }
  return 0;
}