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

/* -----  xtimex  Problem: ABC022 D / Link: http://abc022.contest.atcoder.jp/tasks/abc022_d ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

ll N;
ll ax[100000], bx[100000], ay[100000], by[100000];
double gax = 0.0, gay = 0.0, gbx = 0.0, gby = 0.0;
double ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> ax[i] >> ay[i];
        gax += ax[i]; gay += ay[i];
    }
    FOR(i, 0, N) {
        cin >> bx[i] >> by[i];
        gbx += bx[i]; gby += by[i];
    }
    gax = gax / N;
    gay = gay / N;
    gbx = gbx / N;
    gby = gby / N;

    double a = 0.0, b = 0.0;

    FOR(i, 0, N) {
        a += ((gax - ax[i])*(gax - ax[i]) + (gay - ay[i])*(gay - ay[i]));
        b += ((gbx - bx[i])*(gbx - bx[i]) + (gby - by[i])*(gby - by[i]));
    }
    ans = sqrt(b / a);
    printf("%.12f\n", ans);

    return 0;
}