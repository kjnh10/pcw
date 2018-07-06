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

/* -----  xtimex  Problem: ABC023 D / Link: http://abc023.contest.atcoder.jp/tasks/abc023_d ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----

蟻本より
最大値の最小化

 ----解説ここまで---- */


ll s[100010], h[100010];

bool f(ll x, ll N) {
    ll m[100010];

    FOR(i, 0, N) {
        if (x - h[i] < 0) {
            return false;
        }
        m[i]=((x - h[i]) / s[i]);
    }

    sort(m, m+N);

    FOR(i, 0, N) {
        if (m[i] < i)return false;
    }

    return true;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;
    
    FOR(i, 0, N) {
        cin >> h[i] >> s[i];
    }

    ll l = 0;
    ll r = 1000000000000000;

    while (r - l > 1) {
        ll mid = (l + r) / 2;

        if (f(mid, N)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << r << endl;

    return 0;
}