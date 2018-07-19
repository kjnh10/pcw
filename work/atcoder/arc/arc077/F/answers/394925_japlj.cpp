#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

string f(const string& s) {
  const int n = s.size();
  vector<int> Z(n);

  Z[0] = n;
  for (int i = 1, j = 0; i < n; ) {
    while (i + j < n && s[j] == s[i + j]) {
      ++j;
    }
    Z[i] = j;
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < n && k + Z[k] < j) {
      Z[i + k] = Z[k];
      ++k;
    }
    i += k;
    j -= k;
  }

  int r = 0;
  for (int i = 1; i * 2 < n; ++i) {
    if (Z[n - i] == i) {
      r = i;
    }
  }

  return s.substr(0, n - r) + s.substr(0, n - r);
}

Int len[1024], res[26], cnt[1024][26];
string A0, A1;

void solve(int k, Int L, Int R) {
  // cerr<<k<<' '<<L<<' '<<R<<endl;
  if (len[k] == R - L) {
    for (int i = 0; i < 26; ++i) {
      res[i] += cnt[k][i];
    }
    return;
  }
  if (k <= 1) {
    const string& s = (k == 0 ? A0 : A1);
    for (int i = L; i < R; ++i) {
      res[s[i] - 'a']++;
    }
    return;
  }
  if (L < len[k - 1]) solve(k - 1, L, min(R, len[k - 1]));
  if (R > len[k - 1]) solve(k - 2, max(L, len[k - 1]) - len[k - 1], R - len[k - 1]);
}

int main() {
  string S;
  cin >> S;

  Int L, R;
  cin >> L >> R;
  --L;

  const string S1 = f(S);
  const string S2 = f(S1);

  A0 = S1.substr(S.size() / 2, S1.size() / 2 - S.size() / 2);
  A1 = S2.substr(S1.size() / 2, S2.size() / 2 - S1.size() / 2);

  for (const char c : A0) cnt[0][c - 'a']++;
  for (const char c : A1) cnt[1][c - 'a']++;

  int k = 1;
  len[0] = A0.size();
  len[1] = A1.size();
  for (int i = 2; ; ++i) {
    len[i] = len[i - 1] + len[i - 2];
    for (int j = 0; j < 26; ++j) {
      cnt[i][j] = cnt[i - 1][j] + cnt[i - 2][j];
    }
    if (len[i] > INFLL) {
      k = i;
      break;
    }
  }

  S = S.substr(S.size() / 2);
 
  fill(res, res + 26, 0);
  if (L < S.size()) {
    while (L < S.size() && L < R) {
      res[S[L] - 'a']++;
      ++L;
    }
  }
  L -= S.size();
  R -= S.size();

  if (R - L > 0) {
    for (int i = 0; i <= k; ++i) {
      if (L < len[i]) solve(i, L, min(R, len[i]));
      L -= len[i];
      R -= len[i];
      if (R <= 0) break;
      if (L < 0) L = 0;
    }
  }

  for (int i = 0; i < 26; ++i) {
    printf("%lld%c", res[i], i+1 == 26 ? '\n' : ' ');
  }

  return 0;
}
