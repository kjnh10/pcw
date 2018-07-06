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

pair<int, int> ps[1<<16];
int dp[200200];
int dp2[200][200200];

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N, W, v[200], w[200];
  int mxv = 0, mxw = 0;
  cin >> N >> W;
  rep(i, N) {
    cin >> v[i] >> w[i];
    mxv = max(mxv, v[i]);
    mxw = max(mxw, w[i]);
  }

  if(N <= 30) {
    int n2 = N/2;
    rep(i, 1<<n2) {
      int smv = 0, smw = 0;
      rep(j, n2) {
	if((i>>j)&1) smv += v[j], smw += w[j];
      }
      ps[i] = make_pair(smw, smv);
    }
    sort(ps, ps + (1<<n2));
    int m = 1;
    reps(i, 1, 1<<n2) {
      if(ps[m-1].second < ps[i].second) ps[m++] = ps[i];
    }
    int res = 0;
    rep(i, 1<<(N-n2)) {
      int smv = 0, smw = 0;
      rep(j, N-n2) {
	if((i>>j)&1) smv += v[n2+j], smw += w[n2+j];
      }
      if(smw <= W) {
	int tmp = (lower_bound(ps, ps + m, make_pair(W-smw, inf))-1)->second;
	res = max(res, smv + tmp);
      }
    }
    cout << res << endl;
    return 0;
  }

  if(mxw <= 1000) {
    W = min(W, N*mxw);
    rep(i, N) {
      for(int j = W; j >= w[i]; j--) {
	dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
      }
    }
    cout << dp[W] << endl;
    return 0;
  }

  if(mxv <= 1000) {
    int V = N*mxv;
    fill(dp2[0], dp2[200], inf);
    dp2[0][0] = 0;
    rep(i, N) rep(j, V+1) {
      if(j < v[i]) dp2[i+1][j] = dp2[i][j];
      else dp2[i+1][j] = min(dp2[i][j], dp2[i][j-v[i]] + w[i]);
    }
    int res = 0;
    rep(i, V+1) if(dp2[N][i] <= W) res = i;
    cout << res << endl;
    return 0;
  }


  return 0;
}
