#include <bits/stdc++.h>
using namespace std;

#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)a.size())

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const vector<string> A = {"dreamer", "eraser", "dream", "erase"};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  vector<bool> ok(SZ(s) + 1);
  ok[0] = true;
  for (int i = 0; i < SZ(s); i++) {
    if (ok[i]) {
      for (const auto &add : A) {
        if (i + SZ(add) <= SZ(s) && s.substr(i, SZ(add)) == add) {
          ok[i + SZ(add)] = true;
        }
      }
    }
  }
  cout << (ok[SZ(s)] ? "YES" : "NO") << endl;
  return 0;
}

