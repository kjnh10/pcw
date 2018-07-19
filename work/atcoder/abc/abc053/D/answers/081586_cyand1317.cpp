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

    int count = std::unique(a, a + n) - &a[0];
    printf("%d\n", count - (count % 2 == 0 ? 1 : 0));

    return 0;
}
