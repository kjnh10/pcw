#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001

int a, b, c;

double f(double t) {
  return a * t + b * sin(c * t * pi) - 100;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> a >> b >> c;

  if(a >= b * c * pi) {
    double s = 0, e = 100;
    while (1) {
      double mid = (s + e) / 2.0;
      double ft = f(mid);
      if(abs(ft) < 1e-6) {
        printf("%.10f\n", mid);
        break;
      } else if (ft >= 1e-6) {
        e = mid;
      } else {
        s = mid;
      }
    }
  } else {
    double ttt = 2.0 / c;
    double t = acos((-1) * a / (b * c * pi)) / (c * pi) - ttt;
    double tt = 0;
    bool plus = false, minus = true;
    while (1) {
      t += ttt;
      if (f(t) > 0) {
        if (minus) break;
        plus = true;
        minus = false;
      } else {
        if (plus) break;
        minus = true;
        plus = false;
      }
      if (tt == 0) tt -= t;
      tt += ttt;
      if (f(tt) > 0) {
        if (minus) break;
        plus = true;
        minus = false;
      } else {
        if (plus) break;
        minus = true;
        plus = false;
      }
    }

    if (t > tt) {
      double tmp = t;
      t = tt;
      tt = tmp;
    }
    // cout << t << " " << tt << endl;
    // cout << f(t) << " " << f(tt) << endl;
    double s = t, e = tt;
    while (1) {
      double mid = (s + e) / 2.0;
      double ft = f(mid);
      if(abs(ft) < 1e-6) {
        // dbg(ft);
        printf("%.10f\n", mid);
        break;
      } else if (ft >= 1e-6) {
        e = mid;
      } else {
        s = mid;
      }
    }
  }

  return 0;
}