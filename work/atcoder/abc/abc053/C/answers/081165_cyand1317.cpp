#include <cstdio>
typedef long long int64;

int main()
{
    int64 x;
    scanf("%lld", &x);

    int64 base = x / 11, rem = x % 11;
    printf("%lld\n", base * 2 + (rem > 6 ? 2 : (rem == 0 ? 0 : 1)));

    return 0;
}
