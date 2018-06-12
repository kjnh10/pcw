#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    long long r, b;
    int x, y;
    
    scanf("%lld %lld", &r, &b);
    scanf("%d %d", &x, &y);
    
    if (r < x && b < y) {
        puts("0");
    } else {
        long long left, right, m1, m2, ans = 0, i;
        
        left = 0;
        right = min(r / x, b);
        
        while (1) {
            long long p1, p2;
            
            m1 = left + (right - left) / 3;
            m2 = right - (right - left) / 3;
            
            if (m1 == left || m2 == right || m1 >= m2) break;
            
            p1 = m1 + min(r - m1 * x, (b - m1) / y);
            p2 = m2 + min(r - m2 * x, (b - m2) / y);
            
            if (p1 >= p2) {
                right = m2;
            } else {
                left = m1;
            }
        }
        
        for (i = left; i <= right; i++) ans = max(ans, i + min(r - i * x, (b - i) / y));
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
