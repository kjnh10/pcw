#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>

#define reps(i,f,n) for(ll i=f; i<ll(n); ++i)
#define rep(i,n) reps(i,0,n)

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;

ll dp[2010][2010];
const ll INF = 1001001001001001001ll;

signed main()
{
    ll n, k;
    cin >> n >> k;
    
    vi a(n+1);
    rep(i, n){
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    
    dp[0][0] = 0;
    rep(j, n) dp[0][j+1] = INF;
    
    dp[1][0] = 0;
    dp[1][1] = 1;
    reps(j, 1, n) dp[1][j+1] = INF;
    
    reps(i, 1, n){
        dp[i+1][0] = dp[i][0];
        rep(j, n){
            dp[i+1][j+1] = dp[i][j+1];
            if(dp[i][j] < INF){
                ll x = 1 + dp[i][j]*a[i+1] / a[i] - dp[i][j];
                if(x <= a[i+1] - a[i]){
                    dp[i+1][j+1] = min(dp[i][j+1], dp[i][j] + x);
                }
            }
        }
    }
    
    bool ok = false;
    for(ll j=n; j>=0; --j){
        if(!ok && dp[n][j] < INF){
            ok = true;
            if(dp[n][j] < k){
                cout << 1 << endl;
                break;
            }
        }
        if(dp[n][j] <= k){
            cout << j << endl;
            break;
        }
    }
}
