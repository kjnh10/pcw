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
    int n;
    int64_t d;
    cin >> n;
    cin >> d;

    int p[3] = { 2, 3, 5 };
    int k[3] = {}, l[3];
    int m = 1;
    for (int i = 0; i < 3; i++) {
        while (d % p[i] == 0) {
            d /= p[i];
            k[i]++;
        }
        l[i] = k[i] + 1;
        m *= l[i];
    }
    if (d != 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<double> dp(m);
    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        int i = m;
        for (int i2 = k[2]; i2 >= 0; i2--) {
            for (int i1 = k[1]; i1 >= 0; i1--) {
                for (int i0 = k[0]; i0 >= 0; i0--) {
                    i--;
                    // 1
                    double t = dp[i];
                    // 2-6
                    if (i0 > 0) t += dp[i - 1];
                    if (i1 > 0) t += dp[i - l[0]];
                    if (i0 > 1) t += dp[i - 2];
                    if (i2 > 0) t += dp[i - l[0] * l[1]];
                    if (i0 > 0 && i1 > 0) t += dp[i - l[0] - 1];
                    // -
                    if (i0 == k[0]) t += dp[i] * 2;
                    if (i1 == k[1]) t += dp[i];
                    if (i0 == k[0] && i1 == k[1]) t += dp[i];
                    if (i2 == k[2]) t += dp[i];
                    // 4
                    if (i0 == k[0] && i0 > 0) t += dp[i - 1];
                    // 6
                    if (i0 == k[0] && i1 == k[1]) {
                        if (i0 > 0) t += dp[i - 1];
                        if (i1 > 0) t += dp[i - l[0]];
                    } else if (i0 == k[0]) {
                        if (i1 > 0) t += dp[i - l[0]];
                    } else if (i1 == k[1]) {
                        if (i0 > 0) t += dp[i - 1];
                    }
                    dp[i] = t / 6;
                }
            }
        }
    }

    cout << fixed << setprecision(9) << dp[m - 1] << endl;
    return 0;
}
