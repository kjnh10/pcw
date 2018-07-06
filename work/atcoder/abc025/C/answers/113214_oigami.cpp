#include "bits/stdc++.h"
#ifndef err
#define err(...)(void)0
#endif
using namespace std;
using ll = long long;
using ull = decltype(1ull);
template<class T>int size(T&&a) { return a.size(); }
#define REP(t,a)for(typename make_signed<decltype(a.second)>::type t=a.first,_l##t=a.second;t<_l##t;t++)
#define RREP(t,a)for(typename make_signed<decltype(a.second)>::type t=a.second-1,_l##t=a.first;t>=_l##t;t--)
template<class B>pair<int, B>make_pair(B b) { return{ 0,b }; }
#define rep(t,...)REP(t,make_pair(__VA_ARGS__))
#define rrep(t,...)RREP(t,make_pair(__VA_ARGS__))
#define all(a)begin(a),end(a)
#define rall(a)a.rbegin(),a.rend()

void Calc();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cin.exceptions(istream::failbit | istream::badbit);
  cout << fixed << setprecision(15); Calc(); cout.flush(); return 0;
}
template<class A>void amax(A&a, A b) { a = max(a, b); }
template<class A>void amin(A&a, A b) { a = min(a, b); }
struct Scanner {
  template<class A = string>A Next() { A a; cin >> a; return a; }
  template<class A = int>vector<A>Array(int n) { vector<A>a(n); for (A&i : a) cin >> i; return a; }
  string Line() const { string s; getline(cin, s); return s; }
  template<class A>Scanner&operator,(A&a) { a = Next<A>(); return *this; }
  template<class A>operator A() { return Next<A>(); }
}in;

/*---------------------------------------------------------------------*/
vector<vector<int>> b(2), c(3);
pair<int, int> dfs(vector<vector<int>>& m, int t) {
  const int INF = 1e9 - 1;

  pair<int, int> ans = { 0,0 };
  bool isOk = false;
  for (auto& k : m) {
    for (auto& j : k) {
      if (j == 0) {
        j = t + 1;
        auto p = dfs(m, 1 - t);
        if (isOk == false) {
          ans = p;
          isOk = true;
        }
        if (t == 0) {
          if (ans.first - ans.second < p.first - p.second) {
            ans = p;
          }
        } else if (ans.first - ans.second > p.first - p.second) {
          ans = p;
        }
        j = 0;
      }
    }
  }
  if (isOk == false) {
    rep(i, 2)rep(j, 3) {
      if (m[i][j] == m[i + 1][j])ans.first += b[i][j];
      else ans.second += b[i][j];
    }
    rep(i, 3)rep(j, 2) {
      if (m[i][j] == m[i][j + 1])ans.first += c[i][j];
      else ans.second += c[i][j];
    }
  }
  return ans;
}

void Calc() {

  rep(i, 2)b[i] = in.Array(3);
  rep(i, 3)c[i] = in.Array(2);

  vector<vector<int>> m(3);
  for (auto& i : m) {
    i.resize(3);
  }


  auto p = dfs(m, 0);
  cout << (p.first) << endl;
  cout << (p.second) << endl;

}
