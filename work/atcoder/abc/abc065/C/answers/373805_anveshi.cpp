// Anve$hi $hukla
#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(false);cin.tie(NULL);}}$;

typedef long long LL;
const long long Mod = 1e9 + 7;

int main() {
    long long n, m;
    cin >> n >> m;
    if(n > m) {
        swap(n, m);
    }
    if(m - n > 1) {
        cout << 0 << endl;
        return 0;
    } else {
        long long ans = 1;
        if(m == n)
            ans = 2;
        for(long long i = 1; i <= n; i++) {
            ans = (ans * i) % Mod;
        }
        for(long long i = 1; i <= m; i++) {
            ans = (ans * i) % Mod;
        } 
        cout << ans << endl;
    }

    return 0;
}
