#include <bits/stdc++.h>
using namespace std;

long long F(long long a, long long b, long long c)
{
    return max({a,b,c}) - min({a,b,c});
}

long long foo(long long X, long long a, long long b)
{
    return min(F(X, a / 2 * b, (a - a / 2) * b), F(X, a * (b / 2), a * (b - b / 2)));
}

int main()
{
    int h, w;
    cin >> h >> w;

    long long ans = 1e18;

    for (int i = 1; i < h; i++)
    {
        ans = min(ans, foo(i * 1ll * w, h - i, w));
    }

    for (int i = 1; i < w; i++)
    {
        ans = min(ans, foo(i * 1ll * h, h, w - i));
    }

    printf("%lld\n", ans);
}
