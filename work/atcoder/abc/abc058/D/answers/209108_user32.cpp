#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int64_t kMod = 1000 * 1000 * 1000 + 7;

int64_t Calc(const vector<int64_t>& X) {
  int N = X.size() - 1;

  vector<int64_t> L(N);
  for (int i = 0; i < N; ++i) {
    L[i] = (X[i + 1] - X[i]) % kMod;
  }

  vector<int64_t> S(N);
  S[0] = L[0];
  for (int i = 1; i < N; ++i) {
    S[i] = (S[i - 1] + L[i]) % kMod;
  }

  int64_t current = 0;
  for (auto s : S) {
    current = (current + s) % kMod;
  }
  int64_t total = current;

  for (int i = 0; i < N; ++i) {
    int64_t diff = (1LL * (N - i) * L[i]) % kMod;
    current = (current + kMod - diff) % kMod;
    total = (total + current) % kMod;
  }

  assert(current == 0);

  return total;
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<int64_t> X(N);
  for (auto& x : X) {
    cin >> x;
  }

  vector<int64_t> Y(M);
  for (auto& y : Y) {
    cin >> y;
  }

  int64_t W = Calc(X);
  int64_t H = Calc(Y);
  cout << (W * H) % kMod << '\n';

  return 0;
}
