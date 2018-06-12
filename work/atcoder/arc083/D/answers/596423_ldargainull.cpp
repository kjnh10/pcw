
/*
   О НЕТ! ОНИ ДОГОНЯЮТ!!!
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
   🐹🐹🐹🐹🐹🐹🐹🐹🐹🐹
*/

#include <cmath>
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
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 300 + 1;

int d[N][N];
int pr[N];

int get(int v)
{
    if (v == pr[v])
    {
        return v;
    }
    else
    {
        return pr[v] = get(pr[v]);
    }
}

void uni(int u, int v)
{
    pr[get(u)] = get(v);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            d[i][j] = x;
        }
    }
    vector <pair <int, pair <int, int> > > e;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int best = 2e9 + 7;
            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j)
                {
                    best = min(best, d[i][k] + d[k][j]);
                }
            }
            if (d[i][j] == best)
            {
                e.push_back({d[i][j], {i, j}});
            }
            else if (d[i][j] < best)
            {
                uni(i, j);
                ans += d[i][j];
            }
            else
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    sort(e.begin(), e.end());
    for (auto c : e)
    {
        int u = c.second.first, v = c.second.second;
        if (get(u) != get(v))
        {
            ans += c.first;
        }
    }
    printf("%lld\n", ans);
}
