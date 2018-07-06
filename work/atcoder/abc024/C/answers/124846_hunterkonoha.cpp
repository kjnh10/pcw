#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <array>
#include <float.h>
#include <map>
#include <iomanip>
#include <queue>

using namespace std;

using ULL = unsigned long long;
constexpr ULL DIV = 1e9 + 7;

int moving[10001][2];
int people[101];
int p[101][2];
int dp[101];
int ans[101];

int main() {
  int N, D, K;
  cin >> N >> D >> K;
  for (int i = 0; i < D; ++i) {
    cin >> moving[i][0] >> moving[i][1];
  }
  for (int i = 0; i < K; ++i) {
    cin >> p[i][0] >> p[i][1];
    dp[i] = p[i][0];
    ans[i] = 0;
  }
  for (int i = 0; i < D; ++i) {
    for (int j = 0; j < K; ++j) {
      if (p[j][0] < p[j][1]) {
        if (dp[j] >= p[j][1] && ans[j] == 0) {
          ans[j] = i;
        }
        if (dp[j] >= moving[i][0] && dp[j] <= moving[i][1]) {
          dp[j] = moving[i][1];
        }
      }
      else {
        if (dp[j] <= p[j][1] && ans[j] == 0) {
          ans[j] = i;
        }
        if (dp[j] >= moving[i][0] && dp[j] <= moving[i][1]) {
          dp[j] = moving[i][0];
        }
      }

    }
  }
  for (int i = 0; i < K; ++i) {
    if (ans[i] == 0)ans[i] = D;
    cout << ans[i] << endl;
  }
  return 0;
}