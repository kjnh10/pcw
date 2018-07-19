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

/* -----  xtimex  Problem: ABC026 D / Link: http://abc026.contest.atcoder.jp/tasks/abc026_d ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

int a, b, c;
ll ans = 0LL;
double pi = acos(-1.0);

bool f(double t) {
    return a*t + b*sin(c*pi*t) >= 100.0;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> a >> b >> c;

    double l = 0.0, r = 100000.0, mid;

    FOR (i, 0, 100000) {
        mid = (l + r) / 2.0;
        if (f(mid)) r = mid;
        else l = mid;
    }

    printf("%.12f\n", l);

    return 0;
}