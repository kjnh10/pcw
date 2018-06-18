#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct para
{
    ll w, v;
};

bool porownanie(para a, para b)
{
    if (a.w < b.w)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, w;
    cin >> n >> w;
    vector<para> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].w >> p[i].v;
    sort(p.begin(), p.end(), porownanie);
    vector<ll> a, b, c, d;
    for (int i = 0; i < n; ++i)
    {
        if (p[i].w == p[0].w)
            a.push_back(p[i].v);
        if (p[i].w == p[0].w + 1)
            b.push_back(p[i].v);
        if (p[i].w == p[0].w + 2)
            c.push_back(p[i].v);
        if (p[i].w == p[0].w + 3)
            d.push_back(p[i].v);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    reverse(d.begin(), d.end());
    for (int i = 1; i < a.size(); ++i)
        a[i] += a[i - 1];
    for (int i = 1; i < b.size(); ++i)
        b[i] += b[i - 1];
    for (int i = 1; i < c.size(); ++i)
        c[i] += c[i - 1];
    for (int i = 1; i < d.size(); ++i)
        d[i] += d[i - 1];
    ll odp = 0;
    for (int i = 0; i <= a.size(); ++i)
    {
        for (int j = 0; j <= b.size(); ++j)
        {
            for (int k = 0; k <= c.size(); ++k)
            {
                ll wag = i * p[0].w + j * (p[0].w + 1) + k * (p[0].w + 2);
                if (wag > w)
                    continue;
                ll l = (w - wag) / (p[0].w + 3);
                if ((int) d.size() < l)
                    l = d.size();
                ll s = 0;
                if (i != 0)
                    s += a[i - 1];
                if (j != 0)
                    s += b[j - 1];
                if (k != 0)
                    s += c[k - 1];
                if (l != 0)
                    s += d[l - 1];
                if (s > odp)
                odp = s;
            }
        }
    }
    cout << odp;
    return 0;
}
