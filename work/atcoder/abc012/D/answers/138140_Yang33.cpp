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

/* -----  xtimex  Problem: ABC012 D / Link: https://abc012.contest.atcoder.jp/tasks/abc012_4 ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

ll N, M;
ll d[300][300];
ll ans = 0LL;

void warshall_floyd(ll n) {
    FOR(k, 0, n) {
        FOR(i, 0, n) {
            if (d[i][k] == INF)continue;
            FOR(j, 0, n) {
                if (d[k][j] == INF)continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    
    cin >> N >> M;

    FOR(i, 0, N)FOR(j, 0, N) {
        d[i][j] = INF;
        if (i == j)d[i][j] = 0;
    }

    int a, b, t;
    FOR(i, 0, M) {
        cin >> a >> b >> t;
        a--; b--;
        d[a][b] = t;
        d[b][a] = t;
    }
   
    warshall_floyd(N);
    ans = INF * 10;
    FOR(i, 0, N) {
        ll max_t = -1;
        FOR(j, 0, N) {
            max_t = max(max_t, d[i][j]);
        }
        ans = min(ans, max_t);
    }

    cout << ans << endl;

    return 0;
}