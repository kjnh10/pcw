#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

using ll = long long;
using ldb = long double;

#define forn(i, x, n) for (int i = x; i < (int)(n); ++i)
#define forcin(a, n) for (int i = 0; i < n; cin >> a[i], ++i)
#define forb(i, x, n) for (int i = (int)(x); i >= n; --i)
#define mmax(a, b, c) max(a, max(b, c))
#define mmin(a, b, c) min(a, min(b, c))
#define pb push_back
#define mp make_pair

const int N = 100500 * 3;
const long double eps = 1e-11;

int a[N];
int x, y;
int ti;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int t, a, b;
        cin >> t >> a >> b;
        int dist = abs(x - a) + abs(y - b);
        if (dist % 2 != (t - ti) % 2 || (t - ti) < dist) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}
