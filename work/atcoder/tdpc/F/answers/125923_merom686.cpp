#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <functional>
#include <cstring>
#include <cmath>
#include <random>
using namespace std;

int main() {
    const int Q = 1000000007;
    int n, k;
    cin >> n >> k;

    vector<int64_t> dp(n + 1), p2(n);
    dp[k - 1] = 1;
    dp[k] = 2;

    p2[0] = 1;
    for (int i = 1; i < n; i++) {
        p2[i] = p2[i - 1] * 2 % Q;
    }

    for (int i = k + 1; i < n; i++) {
        int j = i - 1 - k;
        dp[i] = (dp[i - 1] * 2 + (p2[j] - dp[j])) % Q;
    }

    cout << (p2[n - 2] - (dp[n - 1] - dp[n - 2]) + Q) % Q << endl;
}
