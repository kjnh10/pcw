#include <bits/stdc++.h>
using namespace std;

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


int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;

  int a[n];
  rep(i, n) {
    cin >> a[i];
  }

  int ta = -INF;
  rep(i, n) {
    int ao = -INF, tmp = -INF;
    rep(j, n) {
      int odd = 0, even = 0;
      if (j == i) continue;
      if (j < i) {
        repl(k, j, i + 1) {
          if ((k - j) % 2 == 0) {
            odd += a[k];
          } else {
            even += a[k];
          }
        }
      } else if (i < j) {
        repl(k, i, j + 1) {
          if ((k - i) % 2 == 0) {
            odd += a[k];
          } else {
            even += a[k];
          }
        }
      }
      if (ao < even) {
        ao = even;
        tmp = odd;
      }
    }
    maxch(ta, tmp);
  }

  print(ta);

  return 0;
}