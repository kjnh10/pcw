#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
  long long h, w;
  scanf("%lld%lld", &h, &w);
  long long ans = LLONG_MAX;
  for (int magic = 0; magic < 2; magic++) {
    swap(h, w);
    for (int i = 1; i < h; i++) {
      long long p1 = i * w;
      {
        long long p2 = (h - i) * (w / 2);
        long long p3 = (h - i) * (w - w / 2);
        ans = min(ans, max(p1, max(p2, p3)) - min(p1, min(p2, p3)));
      }
      {
        long long hh = h - i;
        long long p2 = (hh / 2) * w;
        long long p3 = (hh - hh / 2) * w;
        ans = min(ans, max(p1, max(p2, p3)) - min(p1, min(p2, p3)));
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}