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
#include<stdlib.h>
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

/* -----  xtimex  Problem: ABC029 D / Link: http://abc029.contest.atcoder.jp/tasks/abc029_d ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----

digit dp

 ----解説ここまで---- */

string N;
ll dp[30][100][2];

ll rec(int x,int cnt,int ok) {
    if (dp[x][cnt][ok] != -1)return dp[x][cnt][ok];
    if (x == N.size())return cnt;

    if (ok == 0) {
        ll tmp = 0;
        for (int i = 0; i < N[x] - '0'; i++) {
            tmp += rec(x + 1, cnt + (i == 1), 1);
        }
        tmp += rec(x + 1, cnt + (N[x] == '1'), 0);
        return dp[x][cnt][ok] = tmp;
    }
    else {
        ll tmp = 0;
        for (int i = 0; i < 10; i++) {
            tmp += rec(x + 1, cnt + (i == 1), 1);
        }
        return dp[x][cnt][ok] = tmp;
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    memset(dp, -1, sizeof(dp));

    cin >> N;

    cout << rec(0,0,0) << endl;

    return 0;
}