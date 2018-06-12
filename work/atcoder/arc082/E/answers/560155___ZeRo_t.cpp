#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 20000;
const int MOD = 998244353;
int powi(int a, int b)
{
    int c = 1;
    for (; b; b >>= 1, a = 1ll * a * a % MOD)
        if (b & 1) c = 1ll * c * a % MOD;
    return c;
}
map <int, int> M;
int xi[N], yi[N];
int ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> xi[i] >> yi[i];
    ans = powi(2, n) - n - 1;
    for (int i = 1; i <= n; ++ i)
    {
        M.clear();
        for (int j = i + 1; j <= n; ++ j)
        {
            int d = (1ll * (yi[j] - yi[i]) * powi(xi[j] - xi[i], MOD - 2) % MOD + MOD) % MOD;
            if (xi[j] - xi[i] == 0) d = -1;
            M[d] ++;
        }
        for (map <int, int> :: iterator it = M.begin(); it != M.end(); ++ it)
            ans = (ans - (powi(2, it -> second) - 1)) % MOD;
    }
    ans = (ans + MOD) % MOD;
    cout << ans;
}
