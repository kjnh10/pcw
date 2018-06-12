#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 111;
const int M = N * 3;
int dp[N][N][M];
int a[N], b[N];
int W;
int n;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &W);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i], &b[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            for (int h = 0; h <= 3 * j; h++)
            {
                dp[i + 1][j][h] = max(dp[i + 1][j][h], dp[i][j][h]);
                dp[i + 1][j + 1][h + a[i] - a[0]] = max(dp[i + 1][j + 1][h + a[i] - a[0]], dp[i][j][h] + b[i]);
            }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 3 * i; j++)
        {
            ll curW = (ll)a[0] * i + j;
            if (curW <= W)
                ans = max(ans, dp[n][i][j]);
        }
    printf("%d\n", ans);

    return 0;
}