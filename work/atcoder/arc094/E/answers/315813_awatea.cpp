#include <cstdio>

using namespace std;

int a[200000];
int b[200000];

int main() {
    int n, x = -1, i;
    long long ans = 0, m = 1e18;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
    
    for (i = 0; i < n; i++) {
        if (a[i] > b[i] && b[i] < m) {
            x = i;
            m = b[i];
        }
    }
    
    if (x >= 0) {
        for (i = 0; i < n; i++) {
            if (i != x) ans += b[i];
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
