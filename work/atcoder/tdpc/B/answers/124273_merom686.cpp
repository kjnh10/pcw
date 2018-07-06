#include <iostream>
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
    int A, B;
    cin >> A >> B;
    vector<int> a(A + 1), b(B + 1);
    for (int i = 0; i < A; i++) {
        cin >> a[A - i];
    }
    for (int j = 0; j < B; j++) {
        cin >> b[B - j];
    }

    // dp[j][j][t]は手番tで残りAがj個、Bがj個のときの先手のスコア
    vector<int[1024][2]> dp(B + 1);
    for (int i = 1; i <= A; i++) {
        dp[0][i][0] = dp[0][i - 1][1] + a[i];
        dp[0][i][1] = dp[0][i - 1][0];
    }
    for (int j = 1; j <= B; j++) {
        dp[j][0][0] = dp[j - 1][0][1] + b[j];
        dp[j][0][1] = dp[j - 1][0][0];
    }
    for (int j = 1; j <= B; j++) {
        for (int i = 1; i <= A; i++) {
            dp[j][i][0] = max(dp[j][i - 1][1] + a[i], dp[j - 1][i][1] + b[j]);
            dp[j][i][1] = min(dp[j][i - 1][0], dp[j - 1][i][0]);
        }
    }

    cout << dp[B][A][0] << endl;
    return 0;
}
