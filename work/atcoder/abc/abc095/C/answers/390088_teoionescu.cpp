#include <bits/stdc++.h>
using namespace std;


int main() {

    int Ca, Cb, Cc, X, Y;
    cin >> Ca >> Cb >> Cc >> X >> Y;
    long long ans = -1;
    for(int c=0; c <= max(X, Y); c++) {
        long long parans = 2 * c * Cc + max(0, X - c) * Ca + max(0, Y - c) * Cb;
        if(ans == -1) {
            ans = parans;
        } else {
            ans = min(ans, parans);
        }
    }
    cout << ans << '\n';

    return 0;
}