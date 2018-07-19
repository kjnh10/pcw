#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long long H, W;
    cin >> H >> W;

    long long a, b, c, ans = 1e18;
    for (long long i = 1; i <= H; i++) {
        a = i * W;
        b = ((H * W - a) % 2 != 0) ? (H - i) * (W / 2) : (H * W - a) / 2;
        c = H * W - a - b;
        ans = min(ans, max(a, max(b, c)) - min(a, min(b, c)));
    }

    for (long long i = 1; i <= W; i++) {
        a = i * H;
        b = ((H * W - a) % 2 != 0) ? (W - i) * (H / 2) : (H * W - a) / 2;        
        c = H * W - a - b;
        ans = min(ans, max(a, max(b, c)) - min(a, min(b, c)));
    }

    cout << ans << endl;

    return 0;
}