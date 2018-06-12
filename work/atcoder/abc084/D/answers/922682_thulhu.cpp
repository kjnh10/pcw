#include <bits/stdc++.h>

using namespace std;

int f[123456];

bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return x > 1;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  for (int i = 1; i <= 100000; i++) {
    f[i] = f[i - 1] + (prime(i) && prime((i + 1) / 2));
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", f[r] - f[l - 1]);
  }
  return 0;
}