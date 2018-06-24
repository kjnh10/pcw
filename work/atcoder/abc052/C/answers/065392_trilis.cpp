#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int n;
long long pw[2000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int ii = i;
        for (int j = 2; j * j <= ii; j++) {
            while (ii % j == 0) {
                ii /= j;
                pw[j]++;
            }
        }
        if (ii != 1) {
            pw[ii]++;
        }
    }
    long long ans = 1;
    for (int j = 0; j <= n; j++) {
        ans = (ans * (pw[j] + 1)) % MOD;
    }
    cout << ans << "\n";
}

