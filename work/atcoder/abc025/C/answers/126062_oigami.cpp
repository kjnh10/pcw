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
vector<string> v(3);
vector<vector<int>> b(2), c(3);
struct Data
{
  int a, b;
  bool operator<(Data d)
  {
    return a - b < d.a - d.b;
  }
};
Data dfs(int now, int t)
{
  bool isOk = false;
  Data ans = {};
  for ( auto& i : v )
  {
    for ( auto& j : i )
    {
      if ( j == 0 )
      {
        j = t + 1;
        auto d = dfs(now + 1, 1 - t);
        if ( isOk == false )
        {
          ans = d;
        }
        else
        {
          if ( t==0 )
          {
            if ( ans < d )
            {
              ans = d;
            }
          }
          else
          {
            if ( ans < d )
            {
            }
            else
            {
              ans = d;
            }
          }
        }
        isOk = true;
        j = 0;
      }
    }
  }
  if ( isOk == false )
  {
    rep(i, 2)rep(j, 3)
    {
      if ( v[i][j] == v[i + 1][j] ) ans.a += b[i][j];
      else ans.b += b[i][j];
    }
    rep(i, 3)rep(j, 2)
    {
      if ( v[i][j] == v[i][j + 1] ) ans.a += c[i][j];
      else ans.b += c[i][j];
    }
  }
  return ans;
}
void Calc()
{
  for ( auto& i : v )
  {
    i.resize(3);
  }
  for ( auto& i : b )
  {
    i = in.Array(3);
  }
  for ( auto& i : c )
  {
    i = in.Array(2);
  }
  auto p = dfs(0, 0);
  cout << p.a << endl;
  cout << p.b << endl;
}
