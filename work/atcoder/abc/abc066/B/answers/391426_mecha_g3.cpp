#include<algorithm>
#include<cmath>
#include<cstdint>
#include<cstdio>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(b); ++i)
#define rep(i,n) for(int i=0; i<n; ++i)
#define all(v) begin(v), end(v)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

int main() {
  std::ios::sync_with_stdio(false);

  string s;
  cin >> s;

  for(;;) {
    s = s.substr(0, s.size()-1);
    if (s.size() % 2 == 0) {
      if (s.substr(0, s.size() / 2) == s.substr(s.size() / 2)) {
        cout << s.size() << endl;
        return 0;
      }
    }
  }
  return 0;
}
