#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
  int n;
  LL T;
  scanf("%d %lld", &n, &T);
  LL ans = 0;
  for (int i = 0, p = 0, t; i < n; i ++) {
    scanf("%d", &t);
    ans += T - max(0, p - t);
    p = t + T;
  }
  cout << ans << endl;
}