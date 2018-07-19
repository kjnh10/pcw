#include <bits/stdc++.h>
using namespace std;

int i, n;
string s, rs;
map<char, char> M;

string Solve(char start, char last) {
  string rs;
  while(rs.size() != s.size()) rs += " ";

  rs[0] = start; rs[n - 1] = last;

  for(i = 0; i < n - 1; ++i)
    if(s[i] == 'o') rs[(i + n + 1) % n] = (rs[i] == 'S' ? rs[(i + n - 1) % n] : M[rs[(i + n - 1) % n]]);
    else rs[(i + n + 1) % n] = (rs[i] == 'W' ? rs[(i - 1 + n) % n] : M[rs[(i + n - 1) % n]]);

  for(i = 0; i < n; ++i) {
    int st = (i + n - 1) % n;
    int dr = (i + n + 1) % n;
    if(rs[i] == 'S') {
      if(s[i] == 'o' && rs[st] != rs[dr]) return "-1";
      if(s[i] == 'x' && rs[st] == rs[dr]) return "-1";
    } else {
      if(s[i] == 'o' && rs[st] == rs[dr]) return "-1";
      if(s[i] == 'x' && rs[st] != rs[dr]) return "-1";
    }
  }

  return rs;
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n >> s;

  M['S'] = 'W'; M['W'] = 'S';

  rs = Solve('S', 'S');
  if(rs != "-1") return cout << rs << '\n', 0;
  rs = Solve('S', 'W');
  if(rs != "-1") return cout << rs << '\n', 0;
  rs = Solve('W', 'S');
  if(rs != "-1") return cout << rs << '\n', 0;

  cout << Solve('W', 'W') << '\n';

  return 0;
}