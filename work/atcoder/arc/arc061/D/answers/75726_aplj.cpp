#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

int main() {
  map<pair<int, int>, int> M;
  int H = in();
  int W = in();
  int N = in();

  for (int i = 0; i < N; ++i) {
    int a = in() - 1;
    int b = in() - 1;
    for (int r = max(0, a - 2); r <= min(a, H - 3); ++r) {
      for (int c = max(0, b - 2); c <= min(b, W - 3); ++c) {
        M[make_pair(r, c)]++;
      }
    }
  }

  Int res[10] = {};
  res[0] = (H - 2LL) * (W - 2LL) - M.size();

  for (const auto& p : M) {
    ++res[p.second];
  }

  for (int i = 0; i <= 9; ++i) {
    printf("%lld\n", res[i]);
  }

  return 0;
}
