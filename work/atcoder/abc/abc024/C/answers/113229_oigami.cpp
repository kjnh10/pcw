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



void Calc() {

  int n, d, k;
  in, n, d, k;
  struct Data {
    int l, r;
    void In() {
      in, l, r;
    }
  };

  vector<Data> da(d);
  for (auto& i : da) {
    i.In();
  }
  struct Data2 {
    int s, t;
    void In() {
      in, s, t;
    }
  };
  vector<Data2> dk(k);
  for (auto& i : dk) {
    i.In();
  }
  vector<int> ans(k,-1);
  rep(i, d) {
    auto p = da[i];
    rep(j, k) if(ans[j]==-1){
      auto&m = dk[j];
      if (p.l <= m.s && m.s <= p.r) {
        if (m.s < m.t) {
          m.s = min(m.t, p.r);
        } else {
          m.s = max(m.t, p.l);
        }
        if (m.s == m.t) {
          ans[j] = i + 1;
        }
      }
    }
  }
  for (auto& i : ans) {
    cout << (i) << endl;
  }

}
