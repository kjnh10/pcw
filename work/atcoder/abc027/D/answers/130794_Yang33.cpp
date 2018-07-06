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

/* -----  xtimex  Problem: ABC027 D / Link: http://abc027.contest.atcoder.jp/tasks/abc027_d ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

string N;
vector<int>V;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int Nsize = N.size();

    int p = 0, m = 0;
    FORR(i, Nsize - 1, -1) {
        if (N[i] == '+') {
            p++;
            continue;
        }
        else if (N[i] == '-') {
            m++;
            continue;
        }
        V.push_back(p - m);
    }

    int Vsize = V.size();

    sort(V.begin(), V.end());
    FOR(i, 0, Vsize / 2) {
        ans -= V[i];
    }
    FOR(i, Vsize / 2, Vsize) {
        ans += V[i];
    }

    cout << ans << endl;

    return 0;
}