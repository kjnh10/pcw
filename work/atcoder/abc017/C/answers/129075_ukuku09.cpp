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
const int mod = 1e9 + 7;

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  int as[M+1] = {};
  int sum = 0;
  rep(i, N) {
    int l, r, s;
    cin >> l >> r >> s;
    sum += s;
    --l;
    as[l] += s;
    as[r] -= s;
  }
  reps(i, 1, M+1) as[i] += as[i-1];
  int mn = inf;
  rep(i, M) chmin(mn, as[i]);
  cout << sum - mn << endl;

  return 0;
}
