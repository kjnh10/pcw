#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
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

const int N = 1234567;

int fact[N], invfact[N];

inline int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  invfact[N - 1] = inv(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    invfact[i] = mul(invfact[i + 1], i + 1);
  }
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int ans = 0;
  int rb = 0, rc = 0;
  for (int sum = 0; sum <= b + c; sum++) {
    int coeff = mul(power(3, b + c - sum), fact[a + sum - 1]);
    int what = power(2, sum);
    if (sum > b) {
      add(rb, rb);
      add(rb, C(sum - 1, b));
      add(what, md - rb);
    }
    if (sum > c) {
      add(rc, rc);
      add(rc, C(sum - 1, c));
      add(what, md - rc);
    }
    what = mul(what, invfact[sum]);
    add(ans, mul(coeff, what));
  }
  printf("%d\n", mul(ans, invfact[a - 1]));
  return 0;
}
