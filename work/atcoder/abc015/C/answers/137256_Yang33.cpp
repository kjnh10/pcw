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

/* -----  xtimex  Problem: ABC015 C / Link: http://abc015.contest.atcoder.jp/tasks/abc015_3 ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

ll N, K;
int t[10][10];
ll ans = 0LL;

void dfs(int i, int x) {
    if (i == N) {
        if (x == 0) {
            cout << "Found" << endl;
            exit(0);
        }
        return;
    }
    FOR(j, 0, K) {
        dfs(i + 1, x ^ (t[i][j]));
    }

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    
    FOR(i, 0, N)FOR(j, 0, K)cin >> t[i][j];
    
    dfs(0, 0);
    
    cout << "Nothing" << endl;

    return 0;
}