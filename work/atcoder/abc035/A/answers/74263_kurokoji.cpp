#include <bits/stdc++.h>
using namespace std;
  
// #define int long long
#define pb push_back
#define print(Target) cout << Target << '\n'

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPS(i, a, n) for (int i = (a); i < (n); i++)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

bool is_uruu(int y) {return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));}

signed main()
{
  ios::sync_with_stdio(false);
  double a, b;

  cin >> a >> b;
  if (a / b == 4.0 / 3.0) puts("4:3");
  else puts("16:9");
  return (0);
}