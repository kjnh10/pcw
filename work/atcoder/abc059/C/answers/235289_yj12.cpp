#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

// #define FL fflush(stdout)

#define MOD 1000000007
#define INF 2000000000
#define MAXN 100010

int GLL(LL& x) {
  return scanf("%lld", &x);
}

int GI(int& x) {
  return scanf("%d", &x);
}

LL n, cnt = 0;
LL A[MAXN];

LL solve(int i, bool target, LL prev) {
  LL a = A[i] + prev;
  LL diff = 0;
  if ((a > 0) != target) {
    if (target == 1) { // A < 0
      diff = 1 - a;
    }
    else {  // A > 0
      diff = -1 - a;
    }
    cnt += abs(diff);
  }
  else if (a == 0) {
    if (target == 1) { // A < 0
      diff = 1 - a;
    }
    else {  // A > 0
      diff = -1 - a;
    }
    cnt += abs(diff);
  }
  return diff;
}

int main() {
  GLL(n);
  FORN(i, n) GLL(A[i]);
  FORN(i, n-1) A[i+1] += A[i];

  LL diff = 0; bool sign = 1;
  FORN(i, n) {
    diff += solve(i, sign, diff);
    sign ^= 1;
  }


  LL ans1 = cnt; cnt = 0;
  diff = 0; sign = 0;
  FORN(i, n) {
    diff += solve(i, sign, diff);
    sign ^= 1;
  }
  LL ans2 = cnt;

  printf("%lld\n", min(ans1, ans2));
  return 0;
}
