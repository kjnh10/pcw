#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, x, y, i;
    long long ans = 1e18;
    
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    
    for (i = 0; i <= max(x, y) * 2; i += 2) {
        long long sum = c * i;
        
        if (i / 2 < x) sum += a * (x - i / 2);
        if (i / 2 < y) sum += b * (y - i / 2);
        
        ans = min(ans, sum);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
