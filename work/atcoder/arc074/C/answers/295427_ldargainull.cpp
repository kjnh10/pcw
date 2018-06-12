#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <iomanip>

using namespace std;

mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);

typedef long long ll;

ll solve(int h, int w)
{
    ll ans = 1e18;
    for (int a = 0; a < h; a++)
    {
        ll cur = a * (ll) w;
        int x = h - a;
        int y = w;
        ll s1 = (x / 2) * (ll) w;
        ll s2 = (x / 2 + x % 2) * (ll) w;
        ans = min(ans, max(max(s1, s2), cur) - min(min(s1, s2), cur));
        s1 = x * (ll) (w / 2);
        s2 = x * (ll) (w / 2 + w % 2);
        ans = min(ans, max(max(s1, s2), cur) - min(min(s1, s2), cur));
    }
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int h, w;
    scanf("%d%d", &h, &w);
    printf("%lld\n", min(solve(h, w), solve(w, h)));
}