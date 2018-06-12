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

char S[12];

int main() {
  scanf("%s", S);

  Int res = 0;
  int n = strlen(S);
  for (int i = 0; i < (1 << (n - 1)); ++i) {
    Int cur = 0;
    for (int j = 0; j < n; ++j) {
      cur = cur * 10 + S[j] - '0';
      if (i & (1 << j)) {
        res += cur;
        cur = 0;
      }
    }
    res += cur;
  }

  printf("%lld\n", res);

  return 0;
}
