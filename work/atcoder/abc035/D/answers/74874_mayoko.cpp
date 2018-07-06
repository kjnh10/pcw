#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
#include<complex>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MAXN = 100100;
int A[MAXN];

struct edge {
    int v;
    ll w;
    edge() {}
    edge(int v, ll w) : v(v), w(w) {};
};

vector<ll> dijkstra(int n, vector<vector<edge> >& G, int s) {
    vector<ll> d(n, LLONG_MAX/10); d[s] = 0;
    priority_queue<pair<ll, int> > que;
    que.push(make_pair(0ll, s));
    while (!que.empty()) {
        auto p = que.top(); que.pop();
        int u = p.second;
        ll dist = -p.first;
        if (dist > d[u]) continue;
        for (edge e : G[u]) {
            if (d[e.v] > d[u]+e.w) {
                d[e.v] = d[u] + e.w;
                que.push(make_pair(-d[e.v], e.v));
            }
        }
    }
    return d;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, T;
    cin >> N >> M >> T;
    vector<vector<edge> > G(N), rG(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].emplace_back(b, c);
        rG[b].emplace_back(a, c);
    }
    auto d = dijkstra(N, G, 0);
    auto rd = dijkstra(N, rG, 0);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll need = d[i]+rd[i];
        if (need > T) continue;
        ans = max(ans, (T-need) * A[i]);
    }
    cout << ans << endl;
    return 0;
}
