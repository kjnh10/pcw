#include<cstdio>

using namespace std;

long long isqrt(long long x) {
    long long min = 0;
    long long max = 1LL << 31;
    long long mid = (max+min)/2;
    long long sqr = mid * mid;
    long long sqr2 = (mid+1) * (mid+1);
    while(x < sqr || sqr2 <= x) {
        if(x < sqr) max = mid;
        if(sqr2 <= x) min = mid;
        mid = (max+min)/2;
        sqr = mid * mid;
        sqr2 = (mid+1) * (mid+1);
    }
    return mid;
}

int main() {
    int Q;
    scanf("%d", &Q);
    for(int x = 0; x < Q; ++x) {
        long long A, B;
        scanf("%lld%lld", &A, &B);
        if(A == B) {
            printf("%lld\n", (A-1)*2);
        }
        else {
            long long sqr = isqrt(A * B);
            if(sqr * sqr == A * B) {
                printf("%lld\n", sqr*2-3);
            }
            else if(sqr * (sqr+1) >= A * B) {
                printf("%lld\n", sqr*2-2);
            }
            else {
                printf("%lld\n", sqr*2-1);
            }
        }
    }
    return 0;
}
