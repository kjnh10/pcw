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

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  string x;
  cin >> x;
  string choku = "choku";
  bool flag = true;
  rep(i, x.size()) {
    if(choku.find(x[i]) == -1) flag = false;
    else if(x[i] == 'c') {
      if(i+1 >= x.size() || x[i+1] != 'h') flag = false;
    } else if(x[i] == 'h') {
      if(i-1 < 0 || x[i-1] != 'c') flag = false;
    }
    if(!flag) break;
  }
  cout << (flag ? "YES" : "NO") << endl;

  return 0;
}
