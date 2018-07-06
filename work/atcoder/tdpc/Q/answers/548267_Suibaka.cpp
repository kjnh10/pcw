#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1e9 + 7;

int main() {
    int N, L;
    cin >> N >> L;
    vector<vector<int>> w(16, vector<int>(1 << 8));
    for(int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        int b = 0;
        for(int j = 0; j < (int)s.size(); ++j) {
            b |= (s[j] - '0') << j;
        }
        w[s.size()][b] = 1;
    }

    vector<vector<vector<int>>> dp(128, vector<vector<int>>(1 << 7, vector<int>(1 << 8)));
    dp[0][0][1] = 1;
    for(int i = 0; i < L; ++i) {
        for(int j = 0; j < 1 << 7; ++j) { // 直前の 7 文字
            for(int k = 0; k < 1 << 8; ++k) { // 区切りの位置
                if(dp[i][j][k] == 0) {
                    continue;
                }
                for(int l = 0; l < 2; ++l) {  // 次に追加する文字 0 or 1
                    int f = 0;
                    for(int m = 0; m < 8; ++m) {
                        if(k >> m & 1 && w[m + 1][((j << 1) + l) & ((1 << (m + 1)) - 1)]) {
                            f = 1;
                        }
                    }
                    int nj = (j << 1) & 127 | l;
                    int nk = (k << 1) & 255 | f;
                    (dp[i + 1][nj][nk] += dp[i][j][k]) %= M;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < 1 << 7; ++i) {
        for(int j = 0; j < 1 << 7; ++j) {
            (res += dp[L][i][(j << 1) + 1]) %= M;
        }
    }
    cout << res << endl;
}
