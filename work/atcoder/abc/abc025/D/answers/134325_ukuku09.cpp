#include <bits/stdc++.h>

using namespace std;

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

const int mod = 1e9 + 7;

int x[25], p[25];

int dp[1<<25];

bool check(int bit, int idx) {
  int x = idx%5, y = idx/5;
  if(0 < x && x < 4) {
    bool l = (bit>>(idx-1))&1;
    bool r = (bit>>(idx+1))&1;
    if(l^r) return false;
  }
  if(0 < y && y < 4) {
    bool u = (bit>>(idx-5))&1;
    bool d = (bit>>(idx+5))&1;
    if(u^d) return false;
  }
  return true;
}

int solve(int bit, int num) {
  if(bit == (1<<25)-1) return 1;
  int &res = dp[bit];
  if(~res) return res;
  res = 0;
  if(~p[num]) {
    if(check(bit, p[num])) res = solve(bit|(1<<p[num]), num+1);
  } else {
    rep(i, 25) {
      if(~x[i]) continue;
      if((bit>>i)&1) continue;
      if(check(bit, i)) (res += solve(bit|(1<<i), num+1)) %= mod;
    }
  }
  return res;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  memset(p, -1, sizeof(p));
  rep(i, 25) {
    cin >> x[i];
    --x[i];
    if(~x[i]) p[x[i]] = i;
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0) << endl;

  return 0;
}
