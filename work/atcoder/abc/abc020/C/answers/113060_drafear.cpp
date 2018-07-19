#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    EACH(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    REP(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector< vector<T> >& vec) {
    REP(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}

struct Edge {
    ll tx, ty, cost;
};

struct Node {
    ll x, y, cost;
};

bool operator>(const Node& n1, const Node& n2) {
    return n1.cost > n2.cost;
}

ll H, W, T;
ll sx, sy, gx, gy;

const ll dx[] = {0, 1, 0, -1};
const ll dy[] = {-1, 0, 1, 0};

vector<string> C;
bool inRange(ll x, ll y) {
    return 0 <= x && x < W && 0 <= y && y < H;
}
bool check(ll c) {
    vector< vector< vector<Edge> > > G(H, vector<vector<Edge>>(W));
    REP(y, H) REP(x, W) {
        REP(d, 4) {
            ll nx = x + dx[d];
            ll ny = y + dy[d];
            if (!inRange(nx, ny)) continue;
            G[y][x].pb({nx, ny, (C[ny][nx] == '#' ? c : 1)});
        }
    }
    priority_queue<Node, vector<Node>, greater<Node>> Q;
    vector< vector<ll> > dist(H, vector<ll>(W, linf));
    Q.push({sx, sy, 0});
    dist[sy][sx] = 0;
    while ( !Q.empty() ) {
        Node node = Q.top(); Q.pop();
        ll x = node.x;
        ll y = node.y;
        ll cost = node.cost;
        if (cost > dist[y][x]) continue;
        EACH(e, G[y][x]) {
            if (!inRange(e.tx, e.ty)) continue;
            if (dist[y][x] + e.cost < dist[e.ty][e.tx]) {
                dist[e.ty][e.tx] = dist[y][x] + e.cost;
                Q.push({e.tx, e.ty, dist[e.ty][e.tx]});
            }
        }
    }
    return dist[gy][gx] <= T;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> H >> W >> T;
    C.resize(H); cin >> C;
    REP(y, H) REP(x, W) {
        if (C[y][x] == 'S') {
            sx = x, sy = y;
        }
        if (C[y][x] == 'G') {
            gx = x, gy = y;
        }
    }
    ll l = 1, r = T;
    REP(t, 50) {
        ll m = (l + r) / 2;
        if (check(m)) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << l << endl;
}
