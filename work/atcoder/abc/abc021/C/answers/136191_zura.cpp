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

#define INF (ll)1e16
#define MAX_N 1000000001
#define MOD ((ll)1e9 + 7)

int main(){
  cin.sync_with_stdio(false);
  int n, a, b, m;
  cin >> n >> a >> b >> m;
  a--, b--;

  ll r[n][n] = {};
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    r[x][y] = r[y][x] = 1;
  }

  ll visited[n + 1][2] = {};
  queue<P> q;
  q.push(P(a, 2));
  visited[a][0] = visited[a][1] = 1;
  while(!q.empty()) {
    P p = q.front();
    q.pop();

    rep(i, n) {
      if (r[p.fi][i] == 1) {
        if (visited[i][0] == 0 || p.se < visited[i][0]) {
          visited[i][0] = p.se;
          visited[i][1] = visited[p.fi][1];
          q.push(P(i, p.se + 1));
        } else if (p.se == visited[i][0]) {
          visited[i][1] += visited[p.fi][1];
          visited[i][1] %= MOD;
        }
      }
    }
  }

  print(visited[b][1]);

  return 0;
}