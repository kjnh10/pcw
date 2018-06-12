#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int xx1, yy1, r, xx2, yy2, xx3, yy3;

int sq(int n) {
  return n * n;
}

bool in(int xx, int yy) {
  return sq(xx - xx1) + sq(yy - yy1) <= r * r;
}

int main() {
  cin >> xx1 >> yy1 >> r;
  cin >> xx2 >> yy2 >> xx3 >> yy3;
  cout << (xx2 + r <= xx1 && xx1 <= xx3 - r && yy2 + r <= yy1 && yy1 <= yy3 - r ? "NO" : "YES") << endl;
  cout << (in(xx2, yy2) && in(xx2, yy3) && in(xx3, yy2) && in(xx3, yy3) ? "NO" : "YES") << endl;
  return 0;
}
