#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n, m;
int x[100000];

int solve(int n) {
    forn(i, n) {
        scanf("%d", x + i);
    }
    int sum = 0, ans = 0;
    forn(i, n) {
        ans = (ans + (LL)i * x[i] - sum) % MOD;
        sum += x[i];
        if (sum >= MOD) {
            sum -= MOD;
        }
        if (sum < 0) {
            sum += MOD;
        }
    }
    if (ans < 0) {
        ans += MOD;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    int ans1 = solve(n);
    int ans2 = solve(m);
    int ans = (LL)ans1 * ans2 % MOD;
    cout << ans << endl;
    return 0;
}
