#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    ll x;
    cin >> x;
    ll best = 1;
    for (ll a = 2; a*a <= x; ++a) {
        for (ll b = a*a; b <= x; b *= a) {
            best = max(best, b);
        }
    }
    cout << best << '\n';
}

