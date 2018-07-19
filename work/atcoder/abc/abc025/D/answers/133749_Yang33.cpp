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
#include<bitset>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* -----  xtimex  Problem: ABC025 D / Link: http://abc025.contest.atcoder.jp/tasks/abc025_d ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----



 ----解説ここまで---- */

ll N;
int dp[1 << 25];
vector<int> v;
int masu[26];

ll ans = 0LL;

int countbit(int n) {
    int ret = 0;
    while (n) {
        n &= n - 1;
        ++ret;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    memset(masu, -1, sizeof(masu));

    FOR(i, 0, 25) {
        int a; cin >> a;
        if (a == 0) {
            v.push_back(i);
        }
        else {
            masu[a] = i;
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    FOR(i, 0, (1 << 25) - 1) {
        if (dp[i]) {
            int c = countbit(i) + 1;
            int r = masu[c];

            if (r != -1) {
                int y = r / 5, x = r % 5;
                if ((i&(1 << r)) == 0) {
                    if (y > 0 && y < 4 && ((i >> (r - 5)) ^ (i >> (r + 5))) & 1) continue;
                    if (x > 0 && x < 4 && ((i >> (r - 1)) ^ (i >> (r + 1))) & 1) continue;

                    dp[i | (1 << r)] = (dp[i | (1 << r)] + dp[i]) % MOD;
                }
            }
            else {
                FOR(s, 0, v.size()) {
                    int j = v[s];
                    int y = j / 5, x = j % 5;
                    if ((i&(1 << j)) == 0) {
                        if (y > 0 && y < 4 && ((i >> (j - 5)) ^ (i >> (j + 5))) & 1) continue;
                        if (x > 0 && x < 4 && ((i >> (j - 1)) ^ (i >> (j + 1))) & 1) continue;

                        dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i]) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[(1 << 25) - 1] << endl;

    return 0;
}