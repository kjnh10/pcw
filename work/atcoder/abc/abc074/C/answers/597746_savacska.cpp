#include <bits/stdc++.h>

using namespace std;
bool wat[3005], sug[3005];

int main()
{
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c, d, e, f, anss, ansb;
    cin >> a >> b >> c >> d >> e >> f;
    wat[0] = true;
    for (int i = 0; i <= f; i++)
    {
        if (wat[i])
        {
            if (i + 100 * a <= f)
                wat[i + 100 * a] = true;
            if (i + 100 * b <= f)
                wat[i + 100 * b] = true;
        }
    }

    sug[0] = true;
    for (int i = 0; i <= f; i++)
    {
        if (sug[i])
        {
            if (i + c <= f)
                sug[i + c] = true;
            if (i + d <= f)
                sug[i + d] = true;
        }
    }

    double maxs = -1;
    for (int A = 100; A <= f; A += 100)
    {
        for (int B = 0; B <= f - A; B++)
        {
            if (wat[A] && sug[B] && B <= A / 100 * e)
            {
                if (maxs < 1.0 * B / (A + B))
                {
                    maxs = 1.0 * B / (A + B);
                    anss = A + B;
                    ansb = B;
                }
            }
        }
    }
    cout << anss << ' ' << ansb;
    return 0;
}
