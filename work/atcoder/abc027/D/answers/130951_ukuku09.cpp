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

  string s;
  cin >> s;
  vector<int> v;
  int cnt = 0;
  rep(i, s.size()) {
    if(s[i] == '+') cnt++;
    else if(s[i] == '-') cnt--;
    else v.push_back(cnt);
  }
  sort(all(v));
  int ans = 0;
  rep(i, v.size()/2) ans -= v[i], ans += v[v.size()/2+i];
  cout << ans << endl;

  return 0;
}
