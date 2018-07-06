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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cin.exceptions(istream::failbit | istream::badbit);
  cout << fixed << setprecision(15); Calc(); cout.flush(); return 0;
}
template<class A>void amax(A&a, A b) { a = max(a, b); }
template<class A>void amin(A&a, A b) { a = min(a, b); }
struct Scanner
{
  template<class A = string>A Next() { A a; cin >> a; return a; }
  template<class A = int>vector<A>Array(int n) { vector<A>a(n); for ( A&i : a ) cin >> i; return a; }
  string Line() const { string s; getline(cin, s); return s; }
  template<class A>Scanner&operator,(A&a) { a = Next<A>(); return *this; }
  template<class A>operator A() { return Next<A>(); }
}in;
/*---------------------------------------------------------------------*/

void Calc()
{
  int n, k;
  in, n, k;
  auto s = in.Array(n);
  if ( std::find(all(s), 0) != s.end() )
  {
    cout << s.size() << endl;
    return;
  }
  if ( k == 0 )
  {
    cout << 0 << endl;
    return;
  }
  err(n, k, s);
  ll now = s[0];
  int maxi = 0;
  int l = 0;
  rep(ss, 1, s.size())
  {
    int i = s[ss];
    now *= i;
    err(now);
    while ( k < now )
    {
      now /= s[l];
      l++;
    }
    amax(maxi, (int) ss - l + 1);
  }
  cout << (maxi) << endl;

}
