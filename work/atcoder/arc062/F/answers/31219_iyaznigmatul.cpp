#include <bits/stdc++.h>

using namespace std;

int const MOD = 1000000007;
int const N = 555;

int from[N], to[N];
int c[N][N];
int dsu[N], sz[N], pv[N];
int ff[42];
set<int> sv[N];
int mul(int a, int b) {
  return (int) ((long long) a * b % MOD);
}

int get(int *p, int x) {
  return x == p[x] ? x : (p[x] = get(p, p[x]));
}

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int modpow(int a, int b) {
  int ret = 1;
  while (b > 0) {
    if (b & 1) {
      ret = mul(ret, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}

int solve2(int n, int k) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int g = gcd(i, n);
    int pw = 1;
    for (int j = 0; j < g; j++) {
      pw = mul(pw, k);
    }
    ans = (ans + pw) % MOD;
  }
  ans = mul(ans, modpow(n, MOD - 2));
  return ans;
}

int main() {
  for (int i = 0; i < N; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", from + i, to + i);
    --from[i];
    --to[i];
  }
  for (int i = 0; i < m; i++) dsu[i] = i;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      int cn = 0;
      ff[cn++] = from[i];
      ff[cn++] = to[i];
      ff[cn++] = from[j];
      ff[cn++] = to[j];
      set<int> q;
      int rem = -1;
      for (int e = 0; e < cn; e++) {
        if (q.find(ff[e]) == q.end()) {
          q.insert(ff[e]);
        } else {
          q.erase(ff[e]);
          rem = ff[e];
        }
      }
      if (q.size() > 2) continue;
      int v = *q.begin();
      q.erase(q.begin());
      int u = *q.begin();
      q.erase(q.begin());
      for (int e = 0; e < n; e++) pv[e] = e;
      for (int e = 0; e < m; e++) {
        if (e == i || e == j) continue;
        if (from[e] == rem || to[e] == rem) continue;
        pv[get(pv, from[e])] = get(pv, to[e]);
      }
      if (get(pv, v) == get(pv, u)) {
        dsu[get(dsu, i)] = get(dsu, j);
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < m; i++) {
    sz[get(dsu, i)]++;
    sv[get(dsu, i)].insert(from[i]);
    sv[get(dsu, i)].insert(to[i]);
  }
  for (int i = 0; i < m; i++) {
    if (get(dsu, i) == i) {
      if ((int) sv[i].size() == sz[i]) {
        ans = mul(ans, solve2(sz[i], k));
      } else {
        ans = mul(ans, c[sz[i] + k - 1][k - 1]);
      }
    }
  }
  printf("%d\n", ans);
}
