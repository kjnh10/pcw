//In the name of Allah

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N];
long long ps[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (!i) {
      ps[0] = a[0];
    }
    else {
      ps[i] = ps[i - 1] + a[i];
    }
  }
  long long d1 = 0, d2 = 0, ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      if (ps[i] + d1 >= 0) {
        ans1 += ps[i] + d1 + 1;
        d1 -= ps[i] + d1 + 1;
      }
      if (ps[i] + d2 <= 0) {
        ans2 += - ps[i] - d2 + 1;
        d2 += - ps[i] - d2 + 1;
      }
    }
    else {
      if (ps[i] + d1 <= 0) {
        ans1 += - ps[i] - d1 + 1;
        d1 += - ps[i] - d1 + 1;
      }
      if (ps[i] + d2 >= 0) {
        ans2 += ps[i] + d2 + 1;
        d2 -= ps[i] + d2 + 1;
      }
    }
  }
  printf("%lld\n", min(ans1, ans2));
  return 0;
}