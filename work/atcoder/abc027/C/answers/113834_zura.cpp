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
  ll n, x = 1;
  cin >> n;

  ll i = 0, tmp = n;
  while(tmp != 1) {
    tmp = tmp / 2;
    i++;
  }

  ll turn = 0;
  if (i % 2 == 0) {
    while(x <= n) {
      if (turn % 2 == 0) {
        x = 2 * x + 1;
      } else {
        x = 2 * x;
      }
      turn++;
    }
  } else {
    while(x <= n) {
      if (turn % 2 == 0) {
        x = 2 * x;
      } else {
        x = 2 * x + 1;
      }
      turn++;
    }
  }
  print(((turn % 2 == 0) ? "Takahashi": "Aoki"));


  return 0;
}