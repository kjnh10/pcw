// clang-format off

#include <bits/stdc++.h>

#define int long long int
#define main signed main()
#define bye return 0
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define each(p, v) for (auto p = (v).begin(); p != (v).end(); p++)
#define all(v) (v).begin(), (v).end()
#define prec(n) fixed << setprecision(n)
#define exact(x) { return (x); }
#define dump(x) cerr << "(L" << __LINE__ << ") " << #x << " = " << (x) << endl

#define sum(v) accumulate(all(v), 0)
#define stlice(s, l) substr(s, (s) + (l) + 1)
#define odd(n) ((n) % 2)
#define even(n) (!((n) % 2))

#define INF 1e9
#define MOD (1e9 + 7)

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define str string
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<str>

using namespace std;

// clang-format on

main {
  string a, b, c;
  cin >> a >> b >> c;
  cout << ((a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0]) ? "YES" : "NO")
       << endl;
  bye;
}
