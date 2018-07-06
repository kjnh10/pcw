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

  int R, C, K;
  cin >> R >> C >> K;

  string s[500];
  rep(i, R) cin >> s[i];

  pint r[500][500];
  rep(i, 500) rep(j, 500) r[i][j] = pint(0, 0);
  rep(j, C) rep(i, R) if(s[i][j] == 'o') {
    for(int k = 0; i-k >= 0; k++) {
      if(s[i-k][j] == 'x') break;
      r[i][j].first++;
    }
    for(int k = 0; i+k < R; k++) {
      if(s[i+k][j] == 'x') break;
      r[i][j].second++;
    }
  }

  int ans = 0;
  rep(i, R) rep(j, C) if(s[i][j] == 'o') {
    bool flag = true;
    for(int k = 0; k < K; k++) {
      if(j+k < 0 || C <= j+k || s[i][j+k] == 'x' ||
	 r[i][j+k].first < K-k || r[i][j+k].second < K-k) {
	flag = false;
	break;
      }
      if(j-k < 0 || C <= j-k || s[i][j-k] == 'x' ||
	 r[i][j-k].first < K-k || r[i][j-k].second < K-k) {
	flag = false;
	break;
      }
    }
    if(flag) ans++;
  }

  cout << ans << endl;

  return 0;
}
