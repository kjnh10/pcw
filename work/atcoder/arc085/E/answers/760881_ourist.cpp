/**
 *    author:  tourist
 *    created: 11.11.2017 15:06:47       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

int a[N];
int smash[N];
int n;

long long solve(int v) {
  if (3 * v > n) {
    long long res = 0;
    for (int i = v; i <= n; i++) {
      if (i % 2 == 0 && i / 2 >= v) {
        continue;
      }
      if (i + i > n) {
        if (a[i] > 0 && smash[i] == 0) {
          res += a[i];
        }
      } else {
        if (smash[i] == 0) {
          if (smash[i + i] > 0) {
            res += max(0, a[i]);
          } else {
            res += max(0, max(a[i], a[i] + a[i + i]));
          }
        }
      }
    }
    return res;
  }
  if (smash[v] > 0) {
    return solve(v + 1);
  }
  long long cur = a[v] + solve(v + 1);
  for (int i = v + v; i <= n; i += v) {
    smash[i]++;
  }
  cur = max(cur, solve(v + 1));
  for (int i = v + v; i <= n; i += v) {
    smash[i]--;
  }
  return cur;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  cout << solve(1) << endl;
  cerr << "time = " << clock() << " ms" << endl;
  return 0;
}
