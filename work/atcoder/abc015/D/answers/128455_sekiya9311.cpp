#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

const int MAX_W = 10101;
const int MAX_K = 55;
int dp[MAX_W][MAX_K], _dp[MAX_W][MAX_K];
int W, N, K;

int main(void) {
    memset(_dp, 0, sizeof(_dp));
    scanf("%d", &W);
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        memcpy(dp, _dp, sizeof(dp));
        memset(_dp, 0, sizeof(dp));
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = 0; i < MAX_W; i++) {
            for (int j = 0; j < MAX_K; j++) {
                chmax(_dp[i][j], dp[i][j]);
                if (i + a < MAX_W && j + 1 < MAX_K) {
                    chmax(_dp[i + a][j + 1], dp[i][j] + b);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= K; j++) {
            chmax(ans, _dp[i][j]);
        }
    }
    cout << ans << endl;
}
