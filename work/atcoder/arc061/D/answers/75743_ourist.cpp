#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int ans[42];
pair <int, int> a[N], b[N];

int main() {
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
    for (int dx = 0; dx < 3; dx++) {
      for (int dy = 0; dy < 3; dy++) {
        b[i * 9 + dx * 3 + dy].first = a[i].first - dx;
        b[i * 9 + dx * 3 + dy].second = a[i].second - dy;
      }
    }
  }
  sort(a, a + n);
  sort(b, b + n * 9);
  long long total = (h - 2) * 1LL * (w - 2);
  for (int i = 0; i < n * 9; i++) {
    int x = b[i].first;
    int y = b[i].second;
    if (i > 0 && x == b[i - 1].first && y == b[i - 1].second) {
      continue;
    }
    if (x < 1 || y < 1 || x > h - 2 || y > w - 2) {
      continue;
    }
    int cnt = 0;
    for (int dx = 0; dx < 3; dx++) {
      for (int dy = 0; dy < 3; dy++) {
        pair <int, int> p = make_pair(x + dx, y + dy);
        int pos = lower_bound(a, a + n, p) - a;
        if (pos < n && a[pos] == p) {
          cnt++;
        }
      }
    }
    ans[cnt]++;
    total--;
  }
  cout << total << endl;
  for (int j = 1; j <= 9; j++) {
    cout << ans[j] << endl;
  }
  return 0;
}
