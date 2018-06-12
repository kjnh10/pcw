#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair

const int N = 200200;
int n;
pll a[N];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);


    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a[i].first, &a[i].second);
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }
    ll l1 = a[0].first, r1 = a[0].first, l2 = a[0].second, r2 = a[0].second;
    for (int i = 0; i < n; i++)
    {
        l1 = min(l1, a[i].first);
        r1 = max(r1, a[i].first);
        l2 = min(l2, a[i].second);
        r2 = max(r2, a[i].second);
    }
    ll ans = (r1 - l1) * (r2 - l2);
    ll len = max(r1, r2) - min(l1, l2);
    sort(a, a + n);
    ll l3 = max(r1, r2), r3 = a[n - 1].first;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, len * (r3 - min(l3, (i == n ? l3 : a[i].first))));
        if (i == n) break;
        l3 = min(l3, a[i].second);
        r3 = max(r3, a[i].second);
    }
    printf("%lld\n", ans);

    return 0;
}