#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  xtimex  Problem:  / Link:  ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

ll N, a, b, M;
vector<pair<int, int>>G[100];
ll ans = 0LL;

ll d[100], path[100];
bool used[100];

void dijkstra(int a) {
    FOR(i, 0, N) {
        d[i] = INF * 10;
        used[i] = false;
        path[i] = 0;
    }

    d[a] = 0;
    path[a] = 1;
    queue<int>Q;
    Q.push(a);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (used[u] == false) {
            used[u] = true;
            FOR(i, 0, G[u].size()) {
                int v = G[u][i].first; int cost_v = G[u][i].second;
                if (used[v] == false) {
                    Q.push(v);
                    if (d[v] > d[u] + cost_v) {
                        d[v] = d[u] + cost_v;
                        path[v] = path[u];
                    }
                    else if (d[v] == d[u] + cost_v) {
                        path[v] = (path[v] + path[u]) % MOD;
                    }
                }
            }
        }
    }

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> a >> b >> M;
    a--; b--;
    FOR(i, 0, M) {
        int x, y; cin >> x >> y;
        x--; y--;
        G[x].push_back(make_pair(y, 1));
        G[y].push_back(make_pair(x, 1));
    }

    dijkstra(a);

    ans = path[b] % MOD;

    cout << ans << endl;

    return 0;
}