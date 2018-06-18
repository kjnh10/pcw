#include<bits/stdc++.h>
using namespace std;

int n;
int a[60];
int mx, mxid;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) {
            mx = a[i];
            mxid = 1;
        }
        else {
            if (abs(a[i]) > abs(mx)) {
                mx = a[i];
                mxid = i;
            }
        }
    }

    cout << 2*n - 2 << endl;
    for (int i = 1; i <= n; i++) {
        if (i == mxid) continue;
        cout << mxid << " " << i << endl;
        a[i] += mx;
    }

    if (mx > 0) {
        for (int i = 2; i <= n; i++) {
            cout << i-1 << " " << i << endl;
            a[i] += a[i-1];
        }
    } else {
        for (int i = n-1; i > 0; i--) {
            cout << i+1 << " " << i << endl;
            a[i] += a[i+1];
        }
    }

    return 0;
}
