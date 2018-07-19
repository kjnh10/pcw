#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

constexpr ll mod = 1e9+7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> dp(N+1, 0);
    dp[0] = 1;
    vector<int> f(N, 0);
    vector<ll> cnt(M, 0);
    int l = 0;
    ll sum = 0;
    for(int i=0; i<N; ++i) {
        sum = (sum + dp[i]) % mod;
        cin >> f[i];
        f[i]--;
        cnt[f[i]]++;
        while(cnt[f[i]] > 1) {
            cnt[f[l]]--;
            sum -= dp[l++];
            while(sum < 0) {
                sum += mod;
            }
        }
        dp[i+1] = sum;
    }
    cout << dp[N] << endl;
}
