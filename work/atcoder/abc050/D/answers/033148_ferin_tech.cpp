#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265359

map<pair<ll, ll>, ll> dp;

ll func(ll s, ll x) {
  if(dp.count(make_pair(s, x)) == 1) return dp[make_pair(s, x)];
  if((s == 0 && x == 0) || (s == 1 && x == 0) || (s == 0 && x == 1)) return 1;
  ll ans = func(s/2, x/2) % MOD;
  if(s >= 1 && x >= 1) ans = (ans + func((s-1)/2,(x-1)/2)) % MOD;
  if(s >= 2) ans = (ans + func((s-2)/2, x/2)) % MOD;

  return dp[make_pair(s, x)] = ans % MOD;
}

int main(void)
{
  ll n;
  cin >> n;
  cout << func(n, n) << endl;

  return 0;
}