#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int maxN = 1005;
int x[maxN][3];
main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) cin >> x[i][j];
    }
    int mx = 0;
    for (int mask = 0; mask < 8; mask++) {
        vector < int > all;
        for (int i = 1; i <= n; i++) {
            int t = mask;
            int val = 0;
            for (int j = 0; j < 3; j++) {
                if (t & 1) val += x[i][j];
                else val -= x[i][j];
                t /= 2;
            }
            all.push_back(val);
        }
        sort(all.begin(), all.end());
        reverse(all.begin(), all.end());
        int cur = 0;
        for (int i = 0; i < m; i++) cur += all[i];
        mx = max(mx, cur);
    }
    cout << mx;
    return 0;
}
