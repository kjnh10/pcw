#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using pint = pair<int, int>;
using tint = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

struct edge {
  int to, cost;
  edge(){}
  edge(int to, int cost):to(to), cost(cost){}
};

vector<edge> graph[300];
int mincost[300];
int N, M;

int dijkstra(int s) {
  priority_queue<pint, vector<pint>, greater<pint> > que;
  fill(mincost, mincost + 300, inf);
  mincost[s] = 0;
  que.emplace(0, s);
  while(que.size()) {
    pint p = que.top(); que.pop();
    int v = p.second;
    if(mincost[v] < p.first) continue;
    for(edge &e : graph[v]) {
      if(e.cost + mincost[v] < mincost[e.to]) {
	mincost[e.to] = e.cost + mincost[v];
	que.emplace(mincost[e.to], e.to);
      }
    }
  }
  int res = 0;
  rep(i, N) chmax(res, mincost[i]);
  return res;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> M;
  rep(i, M) {
    int a, b, t;
    cin >> a >> b >> t;
    a--, b--;
    graph[a].emplace_back(b, t);
    graph[b].emplace_back(a, t);
  }
  int ans = inf;
  rep(i, N) chmin(ans, dijkstra(i));
  cout << ans << endl;

  return 0;
}
