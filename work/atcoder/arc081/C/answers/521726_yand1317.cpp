#include <cstdio>
#include <algorithm>
static const int MAXN = 1e5 + 4;

int n;
int a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    std::sort(a, a + n);
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n - 1; ++i) if (a[i] == a[i + 1]) {
        s2 = s1; s1 = a[i];
        ++i;
    }

    printf("%lld\n", (long long)s1 * s2);
    return 0;
}
