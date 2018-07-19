#include <bits/stdc++.h>

using namespace std;

char s[12345];

int main() {
  scanf("%s", s);
  int len = strlen(s);
  long long ans = 0;
  for (int t = 0; t < (1 << (len - 1)); t++) {
    long long num = s[0] - '0';
    for (int i = 0; i < len - 1; i++) {
      if (t & (1 << i)) {
        ans += num;
        num = 0;
      }
      num = num * 10 + s[i + 1] - '0';
    }
    ans += num;
  }
  cout << ans << endl;
  return 0;
}
