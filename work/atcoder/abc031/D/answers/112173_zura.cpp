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
  int k, n;
  cin >> k >> n;

  vector<string> v(n);
  vector<string> w(n);
  vector<int> wl(n);
  rep(i, n) {
    cin >> v[i] >> w[i];
    wl[i] = w[i].length();
  }

  vector<int> sl(k + 1);
  vector<string> s(k + 1);
  rep(i, k + 1) sl[i] = 1;

  while(true) {
    bool ok = true;
    rep(i, n) {
      int tmp = 0;
      rep(j, v[i].length()) {
        tmp += sl[v[i][j] - '0'];
      }
      if (tmp != wl[i]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      rep(i, n) {
        int tmp = 0;
        rep(j, v[i].length()) {
          s[v[i][j] - '0'] = w[i].substr(tmp, sl[v[i][j] - '0']);
          tmp += sl[v[i][j] - '0'];
        }
      }
      repl(i, 1, k + 1) {
        print(s[i]);
      }
      break;
    } else {
      int up = 1;
      repl(i, 1, k + 1) {
        sl[i] += up;
        if (sl[i] > 3) {
          sl[i] -= 3;
          up = 1;
        } else {
          up = 0;
        }
      }
    }
  }

  return 0;
}