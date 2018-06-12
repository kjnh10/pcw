/**
 *    author:  tourist
 *    created: 02.09.2017 15:07:12       
**/
#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

inline int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int x) {
  return power(x, md - 2);
}

const int N = 12345;

int x[N], y[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  int ans = power(2, n);
  add(ans, md - 1);
  add(ans, md - n);
  add(ans, md - n * (n - 1) / 2);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int a = y[j] - y[i];
      int b = x[i] - x[j];
      int c = -a * x[i] - b * y[i];
      int cnt = 2;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) {
          continue;
        }
        int z = a * x[k] + b * y[k] + c;
        if (z != 0) {
          continue;
        }
        if (k < j) {
          break;
        }
        cnt++;
      }
      add(ans, md - power(2, cnt));
      add(ans, 1);
      add(ans, cnt);
      add(ans, cnt * (cnt - 1) / 2);
    }
  }
  printf("%d\n", ans);
  return 0;
}
