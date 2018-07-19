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
#define debug(x) cout<<#x<<": "<<x<<endl
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  xtimex  Problem: ABC030 D / Link: http://abc030.contest.atcoder.jp/tasks/abc030_d ----- */
/* ------問題------


*/
/* -----解説等-----

thank quora users.

*/

ll N, a;
string k;
ll b[100001];
ll id[100001];
ll ans = 0LL;

ll digitsmod(string s, ll mod) {
    ll reminder = 0;
    FOR(i, 0, s.size()) {
        reminder = (reminder * 10 + (s[i] - '0')) % mod;
    }
    return reminder;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> a >> k;
    FOR(i, 1, N + 1) {
        cin >> b[i];
    }

    if (k.size() < 6) {
        int kk = stoi(k);
        FOR(i, 0, kk) {
            a = b[a];
        }
        cout << a << endl;
        return 0;
    }


    /* dig */
    /*FOR(i, 1, N + 1) {
        id[i] = -1;
    }*/
    int pos = a;
    ll cnt = 1;
    while (id[pos] == 0) {
        id[pos] = cnt++;
        pos = b[pos];
    }
    /*for (; id[cnt] < 0; cnt++) {
        id[pos] = cnt;
        pos = b[pos];
    }*/

    ll loop = cnt - id[pos];
    ll knum = digitsmod(k, loop);
    knum += loop * 100;

    FOR(i, 0, knum) {
        a = b[a];
    }

    cout << a << endl;

    return 0;
}