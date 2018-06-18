#include <cstdio>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long x[100000], y[100000];

    long long xl = 0, yl = 0;

    for(int i=0;i<n;i++) {
        scanf("%lld", x+i);
        if (i!=0) {
            xl += (x[i] - x[i-1]) * (n-i) * (i);
            xl %= MOD;
        }
    }

    for(int i=0;i<m;i++) {
        scanf("%lld", y+i);
        if (i!=0) {
            yl += (y[i] - y[i-1]) * (m-i) * (i);
            yl %= MOD;
        }
    }

    long long res = (xl * yl) % MOD;

    printf("%lld\n", res);

    return 0;
}