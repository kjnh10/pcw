#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <utility>
#include <chrono>

using namespace std;

static const int INF = 1 << 28;
static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};
static const int  MOD = 1000000007;

#define D(x) cout << x << endl
#define d(x) cout << x

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

vi l, r;
int n, d, k;

int main() { 
  cin >> n >> d >> k;
  l.resize(d);
  r.resize(d);

  for (int i = 0; i < d; i++) {
    cin >> l[i] >> r[i];
  }

  int s, t;
  vi ans(d);
  for (int j = 0; j < k; j++) {
    cin >> s >> t;
    int ls = s;
    int rs = s;
    for (int i = 0; i < d; i++) {
      if ((l[i] <= ls && ls <= r[i]) || (l[i] <= rs && rs <= r[i])) {
        ls = min(ls, l[i]);
        rs = max(rs, r[i]);
        if (ls <= t && t <= rs) {
          ans[j] = i + 1;
          break;
        }
      }
    }
  }
  
  for (int i = 0; i < k; i++) {
    D(ans[i]);
  }

  return 0;
}
