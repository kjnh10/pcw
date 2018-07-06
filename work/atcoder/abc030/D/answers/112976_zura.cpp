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
  int n, a;
  string k;
  cin >> n >> a >> k;

  int b[n + 1][2] = {};
  rep(i, n) {
    cin >> b[i + 1][0];
  }

  int s = 0, t = 0, tmp = a;
  while(b[tmp][1] == 0) {
    b[tmp][1] = ++t;
    tmp = b[tmp][0];
  }
  s = b[tmp][1] - 1;
  t -= s;

  auto num = 0;
  if(k.length() < 10) {
    num = stoi(k);
    if (num <= s) {
      tmp = a;
    } else {
      num = (num + t - s % t) % t;
    }
  } else {
    rep(i, k.length()) {
      num = (num * 10 + (k[i] - '0')) % t;
    }
    num = (num + t - s % t) % t;
  }
  rep(i, num) {
    tmp = b[tmp][0];
  }
  print(tmp);

  return 0;
}