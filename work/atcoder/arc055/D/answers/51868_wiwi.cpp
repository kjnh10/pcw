#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

int N, K;
bool vis[1010][1010][2];
double mem[1010][1010][2];

double search(int n, int k, bool b) {
  if (n == N) return b ? 1.0 : 0.0;

  double &res = mem[n][k][b];
  if (vis[n][k][b]) return res;
  vis[n][k][b] = true;
  res = 0.0;

  double p1 = 1.0 / (n + 1), p2 = 1.0 - p1;
  { // Case 1: next = top
    double e = search(n + 1, k, false);  // do not eat
    if (k + 1 <= K) e = max(e, search(n + 1, k + 1, true));  // eat
    res += p1 * e;
  }
  { // Case 2: next != top
    res += p2 * search(n + 1, k, b);
  }
  return res;
}

int main() {
  for (; 2 == scanf("%d%d", &N, &K); ) {
    memset(vis, 0, sizeof(vis));
    printf("%.10f\n", search(0, 0, false));
  }
}
