/**
 *    author:  tourist
 *    created: 02.09.2017 15:19:24       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int r[N], t[N], init[N];

int main() {
  int x, n;
  scanf("%d %d", &x, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", r + i);
  }
  int tt;
  scanf("%d", &tt);
  for (int i = 0; i < tt; i++) {
    scanf("%d %d", t + i, init + i);
  }
  int a = 0;
  int val_a = 0;
  int b = x;
  int val_b = x;
  int dir = -1;
  int out = -1;
  int ptr = 0;
  for (int i = 0; i <= n; i++) {
    while (ptr < tt && (i == n || t[ptr] <= r[i])) {
      int now = -1;
      if (init[ptr] <= a) {
        now = val_a;
      } else {
        if (init[ptr] >= b) {
          now = val_b;
        } else {
          now = val_a - out * (init[ptr] - a);
        }
      }
      now += (t[ptr] - (i == 0 ? 0 : r[i - 1])) * dir;
      now = max(now, 0);
      now = min(now, x);
      printf("%d\n", out == -1 ? now : x - now);
      ptr++;
    }
    if (i < n) {
      int pass = r[i] - (i == 0 ? 0 : r[i - 1]);
      val_a += dir * pass;
      val_b += dir * pass;
      if (val_a < 0) {
        a -= val_a;
        val_a = 0;
      }
      if (val_b < 0) {
        b += val_b;
        val_b = 0;
      }
      if (val_a > x) {
        a += (val_a - x);
        val_a = x;
      }
      if (val_b > x) {
        b -= (val_b - x);
        val_b = x;
      }
      if (a > b) {
        a = b = 0;
      }
      val_a = x - val_a;
      val_b = x - val_b;
      out = -out;
    }
//    cerr << "after " << i << ": " << a << " " << val_a << " " << b << " " << val_b << " " << out << endl;
  }
  return 0;
}
