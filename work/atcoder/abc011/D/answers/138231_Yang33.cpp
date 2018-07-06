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

/* -----  xtimex  Problem: ABC011 D / Link: https://abc011.contest.atcoder.jp/tasks/abc011_4  ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

#define MAX_N 1010
ll N, D, X, Y;
double comb[MAX_N][MAX_N];
double ans = 0.0;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> D >> X >> Y;

    if (X % D != 0 || Y % D != 0) {
        cout << 0 << endl;
        return 0;
    }
    X /= D; Y /= D;

    FOR(i, 0, MAX_N)FOR(j, 0, MAX_N)comb[i][j] = 0;

    comb[0][0] = 1;

    FOR(i, 1, MAX_N) {
        comb[i][0] = comb[i - 1][0]/2;
        FOR(j, 1, MAX_N) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) / 2;
        }
    }
    FOR(i, 0, N + 1) {
        if ((i + X) % 2 == 1 || i - X < 0 || i + X < 0) continue;

        int right = (i + X) / 2, left = (i - X) / 2;
        int j = N - i;

        if ((j + Y) % 2 == 1 || j - Y < 0 || j + Y < 0) continue;

        int up = (j + Y) / 2, down = (j - Y) / 2;
        ans += comb[N][i] * comb[i][right] * comb[N-i][up];
    }
    printf("%.10lf\n", ans);

    return 0;
}