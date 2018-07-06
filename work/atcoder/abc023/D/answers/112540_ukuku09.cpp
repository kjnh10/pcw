#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

#define MAX_N 100000

int n;
int h[MAX_N], s[MAX_N];

bool check(int mb)
{
  double t[MAX_N];
  rep(i, n) {
    if(mb < h[i]) return false;
    t[i] = (double)(mb - h[i]) / s[i];
  }
  sort(t, t + n);
  rep(i, n) {
    if(t[i] < i) return false;
  }
  return true;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n;
  rep(i, n) cin >> h[i] >> s[i];
  int lb = 0, ub = 200000000000000;
  while(lb + 1 < ub) {
    int mb = (lb + ub) / 2;
    if(check(mb)) ub = mb;
    else lb = mb;
  }
  cout << ub << endl;

  return 0;
}
