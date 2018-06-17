#include <bits/stdc++.h>

using namespace std;

#define N 1
int a, b, c, d, e, f;

bool can(int i, int j) {
    bool ok = false;
    for (int l = 0; l * a <= j; l++) {
        if ((j - l * a) % b == 0) {
            ok = true;
            break;
        }
    }
    if (!ok)
        return false;
    ok = false;
    for (int l = 0; l * c <= i; l++) {
        if ((i - l * c) % d == 0) {
            ok = true;
            break;
        }
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    double cc = -1;
    int cci = -1, ccj = -1;
    for (int j = a; j <= f / 100; j++) {
        for (int i = 0; i <= e * j; i++)
            if (can(i, j) && i + j * 100 <= f) {
                if (cc < 1.0 * i / j)
                    cc = 1.0 * i / j, cci = i, ccj = j;
            }
    }
    cout << (cci + ccj * 100) << " " << cci << endl;
    return 0;
}
