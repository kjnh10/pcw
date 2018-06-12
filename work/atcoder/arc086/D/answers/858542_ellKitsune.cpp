#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[50];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    int ind = 0;
    forn(i, n) if (abs(a[ind]) < abs(a[i])) {
        ind = i;
    }
    if (a[ind] == 0) {
        cout << 0 << endl;
    } else if (a[ind] > 0) {
        cout << 2 * n << endl;
        forn(i, n) {
            cout << ind + 1 << ' ' << i + 1 << endl;
            cout << ind + 1 << ' ' << i + 1 << endl;
            ind = i;
        }
    } else {
        cout << 2 * n << endl;
        for (int i = n - 1; i >= 0; --i) {
            cout << ind + 1 << ' ' << i + 1 << endl;
            cout << ind + 1 << ' ' << i + 1 << endl;
            ind = i;
        }
    }
    return 0;
}
