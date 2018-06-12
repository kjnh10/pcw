#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
  int A, B;
  cin >> A >> B;
  if (A == 0) {
    cout << "! " << string(B, '0') << endl;
    return 0;
  }
  if (A <= B) {
    cout << "Impossible" << endl;
    return 0;
  }
  const int N = A + B;
  int honto = 0, y = 0, n = 0;
  for (int i = 1; i < N; ++i) {
    cout << "? " << i << " " << honto << endl;
    string s;
    cin >> s;
    if (s == "Y") ++y;
    else ++n;
    if (n > y) {
      honto = i;
      y = 0; n = 0;
    }
  }
  vector<int> res(N);
  res[honto] = 1;
  REP(i,N) {
    if (i == honto) continue;
    cout << "? " << honto << " " << i << endl;
    string s;
    cin >> s;
    if (s == "Y") res[i] = 1;
    else res[i] = 0;
  }
  cout << "! ";
  REP(i,N) cout << res[i];
  cout << endl;
  return 0;
}
