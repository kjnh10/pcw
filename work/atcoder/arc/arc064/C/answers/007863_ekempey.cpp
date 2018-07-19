#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int64_t ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= x) {
            ans += a[i] - x;
            a[i] = x; 
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int over = max(0, a[i] + a[i + 1] - x);
        ans += over;
        a[i + 1] -= over;
    }
    cout << ans << endl;
}
