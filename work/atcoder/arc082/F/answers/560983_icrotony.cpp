#include <bits/stdc++.h>
using namespace std;
struct jer {
  int ahi, alo, curhi, curlo;
  bool asc;
};
int r[100005];
jer changes[100005];
int main() {
  int x, k;
  scanf("%d %d", &x, &k);
  jer lastchange = {x, 0, x, 0, false};
  changes[0] = lastchange;
  int last = 0;
  for (int i = 1; i <= k + 1; i++) {
    if (i == k + 1) {
      r[i] = 1000000001;
    } else {
      scanf("%d", &r[i]);
    }
    int dt = r[i] - last;
    last = r[i];
    if (i % 2 == 1) {
      changes[i].ahi = lastchange.ahi;
      changes[i].curhi = max(0, lastchange.curhi - dt);
      changes[i].curlo = max(0, lastchange.curlo - dt);
      changes[i].alo = changes[i].ahi - (changes[i].curhi - changes[i].curlo);
      changes[i].asc = true;
    } else {
      changes[i].alo = lastchange.alo;
      changes[i].curhi = min(x, lastchange.curhi + dt);
      changes[i].curlo = min(x, lastchange.curlo + dt);
      changes[i].ahi = changes[i].alo + (changes[i].curhi - changes[i].curlo);
      changes[i].asc = false;
    }
    lastchange = changes[i];
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int t, a;
    scanf("%d %d", &t, &a);
    int offset = upper_bound(r, r + k + 2, t) - r - 1;
    int p = 0;
    if (a > changes[offset].ahi) {
      p = changes[offset].curhi;
    } else if (a < changes[offset].alo) {
      p = changes[offset].curlo;
    } else {
      p = changes[offset].curlo + a - changes[offset].alo;
    }
    p += (changes[offset].asc ? 1 : -1) * (t - r[offset]);
    p = min(x, p);
    p = max(0, p);
    printf("%d\n", p);
  }
  return 0;
}
