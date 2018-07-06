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

int K, N;
string v[55], w[55];

bool solve(vint& vec) {
  if(vec.size() == K) {
    vector<string> ans(K);
    rep(i, N) {
      int len = 0;
      for(char c : v[i]) len += vec[c];
      if(len != w[i].size()) return false;
      int idx = 0;
      for(char c : v[i]) {
	if(ans[c] == "") ans[c] = w[i].substr(idx, vec[c]);
	if(ans[c] != w[i].substr(idx, vec[c])) return false;
	idx += vec[c];
      }
    }
    for(string s : ans) cout << s << endl;
    return true;
  }
  for(int i = 1; i <= 3; i++) {
    vec.push_back(i);
    if(solve(vec)) return true;
    vec.pop_back();
  }
  return false;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> K >> N;
  rep(i, N) cin >> v[i] >> w[i];
  rep(i, N) for(char& c : v[i]) c -= '1';
  vint vec;
  solve(vec);

  return 0;
}
