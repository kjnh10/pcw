#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr ll M = 1e9+7;
constexpr int MAX_D = 100001;

int main() {
    int N;
    cin >> N;
    vector<ll> v(MAX_D);
    for(int i=0; i<N; ++i) {
        int D;
        cin >> D;
        ++v[D];
    }
    vector<vector<ll>> dp(4, vector<ll>(MAX_D));
    dp[0] = v;
    for(int j=1; j<dp[0].size(); ++j) {
        dp[0][j] += dp[0][j-1];
    }
    for(int i=1; i<4; ++i) {
        for(int j=0; j<dp[i].size(); ++j) {
            dp[i][j] = dp[i-1][j/2] * v[j];
            dp[i][j] %= M;
        }
        if(i == 3) {
            break;
        }
        for(int j=1; j<dp[i].size(); ++j) {
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= M;
        }
    }
    ll res = 0;
    for(int j=0; j<dp[3].size(); ++j) {
        res += dp[3][j];
        res %= M;
    }
    cout << res << endl;
}
