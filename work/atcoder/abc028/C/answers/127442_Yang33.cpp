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
#include<set>
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

/* -----  xtimex  Problem: ABC028 C / Link: http://abc028.contest.atcoder.jp/tasks/abc028_c ----- */
/* ------問題------

異なる整数が 5 個与えられます。
この中から 3 つ選んでその和で表すことの出来る整数のうち、3 番目に大きいものを出力してください。

-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

int a[5];
set<int >s;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    FOR(i,0,5)
    cin >> a[i];

    FOR(i, 0, 5)FOR(j, 0, 5)FOR(k, 0, 5) {
        if (i != j&&j != k&&k != i) {
            s.insert(a[i] + a[j] + a[k]);
        }
    }
    auto it = s.end();
    it--;
    it--;
    it--;

    ans = *it;
    cout << ans << endl;

    return 0;
}