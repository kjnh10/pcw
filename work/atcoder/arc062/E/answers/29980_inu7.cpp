#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int cc[500][4];

struct abcd {
  int a, b, c, d;
  abcd() {}
  abcd(int _a, int _b, int _c, int _d) { a = _a; b = _b; c = _c; d = _d; }
  bool operator < (const abcd & another) const {
    if (a != another.a) return a < another.a;
    if (b != another.b) return b < another.b;
    if (c != another.c) return c < another.c;
    return d < another.d;
  };
};

int same(int a0, int a1, int a2, int a3, int b0, int b1, int b2, int b3) {
  int cc = 0;
  if (a0 == b0 && a1 == b1 && a2 == b2 && a3 == b3) cc ++;
  if (a0 == b1 && a1 == b2 && a2 == b3 && a3 == b0) cc ++;
  if (a0 == b2 && a1 == b3 && a2 == b0 && a3 == b1) cc ++;
  if (a0 == b3 && a1 == b0 && a2 == b1 && a3 == b2) cc ++;
  return cc;
}

int main()
{
  int n;
  cin >> n;
  map<abcd, int> cnt;
  for (int i=0; i<n; i++) {
    cin >> cc[i][0] >> cc[i][1] >> cc[i][2] >> cc[i][3];
    cnt[abcd(cc[i][0], cc[i][1], cc[i][2], cc[i][3])] ++;
    cnt[abcd(cc[i][1], cc[i][2], cc[i][3], cc[i][0])] ++;
    cnt[abcd(cc[i][2], cc[i][3], cc[i][0], cc[i][1])] ++;
    cnt[abcd(cc[i][3], cc[i][0], cc[i][1], cc[i][2])] ++;
  }

  long long res = 0;
  for (int i=0; i<n; i++)
    for (int j=i+1; j<n; j++) {
      int a0 = cc[i][0], a1 = cc[i][1], a2 = cc[i][2], a3 = cc[i][3];
      int b0 = cc[j][3], b1 = cc[j][2], b2 = cc[j][1], b3 = cc[j][0];
      for (int ord=0; ord<4; ord++) {
        int ll_cnt = cnt[abcd(a0, a3, b0, b1)];
        int rr_cnt = cnt[abcd(a2, a1, b2, b3)];
        int uu_cnt = cnt[abcd(a1, a0, b1, b2)];
        int dd_cnt = cnt[abcd(a3, a2, b3, b0)];
        ll_cnt -= same(a0, a1, a2, a3, a0, a3, b0, b1);
        ll_cnt -= same(b3, b2, b1, b0, a0, a3, b0, b1);
        rr_cnt -= same(a0, a1, a2, a3, a2, a1, b2, b3);
        rr_cnt -= same(b3, b2, b1, b0, a2, a1, b2, b3);
        uu_cnt -= same(a0, a1, a2, a3, a1, a0, b1, b2);
        uu_cnt -= same(b3, b2, b1, b0, a1, a0, b1, b2);
        dd_cnt -= same(a0, a1, a2, a3, a3, a2, b3, b0);
        dd_cnt -= same(b3, b2, b1, b0, a3, a2, b3, b0);

        rr_cnt -= same(a0, a3, b0, b1, a2, a1, b2, b3);
        uu_cnt -= same(a0, a3, b0, b1, a1, a0, b1, b2);
        uu_cnt -= same(a2, a1, b2, b3, a1, a0, b1, b2);
        dd_cnt -= same(a0, a3, b0, b1, a3, a2, b3, b0);
        dd_cnt -= same(a2, a1, b2, b3, a3, a2, b3, b0);
        dd_cnt -= same(a1, a0, b1, b2, a3, a2, b3, b0);
        res += 1LL * ll_cnt * rr_cnt * uu_cnt * dd_cnt;
//        printf("%d %d %d : %d %d %d %d\n", i,j,ord, ll_cnt, rr_cnt, uu_cnt, dd_cnt);
        int b4 = b0;
        b0 = b1;
        b1 = b2;
        b2 = b3;
        b3 = b4;
      }
    }
  cout << res / 3 << endl;
}
