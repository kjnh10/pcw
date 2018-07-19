#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

llong N, A, B;
llong hs[100100];

bool ok(llong k)
{
    llong base = k * B;
    llong* pt = upper_bound(hs, hs + N, base);
    size_t idx = pt - hs;
    llong cnt = 0;
    FOR (i, idx, N)
    {
        llong rest = hs[i] - base;
        cnt += rest / (A - B) + bool(rest % (A - B));
    }
    return cnt <= k;
}

int main()
{
    cin >> N >> A >> B;
    FO (i, N)
        cin >> hs[i];
    sort(hs, hs + N);
    llong l = 0, r = INT_MAX;
    while (l < r)
    {
        llong mid = (l + r) / 2;
        if (!ok(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << r << endl;
    return 0;
}