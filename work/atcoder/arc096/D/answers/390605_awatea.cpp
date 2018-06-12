#include <cstdio>
#include <algorithm>

using namespace std;

long long x[100002];
int v[100002];
long long a[100002];
long long b[100002];

int main() {
    int n, i;
    long long c, ans = 0;
    
    scanf("%d %lld", &n, &c);
    
    x[0] = 0;
    v[0] = 0;
    
    for (i = 1; i <= n; i++) scanf("%lld %d", &x[i], &v[i]);
    
    x[n + 1] = c;
    v[n + 1] = 0;
    
    for (i = 1; i <= n; i++) a[i] = a[i - 1] + v[i] - (x[i] - x[i - 1]);
    for (i = 1; i <= n; i++) a[i] = max(a[i], a[i - 1]);
    
    for (i = n; i >= 1; i--) b[i] = b[i + 1] + v[i] - (x[i + 1] - x[i]);
    for (i = n; i >= 1; i--) b[i] = max(b[i], b[i + 1]);
    
    for (i = 1; i <= n; i++) {
        ans = max(ans, a[i]);
        ans = max(ans, a[i] - x[i] + b[i + 1]);
        ans = max(ans, b[i]);
        ans = max(ans, b[i] - (c - x[i]) + a[i - 1]);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
