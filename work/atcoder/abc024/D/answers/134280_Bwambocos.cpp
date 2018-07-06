#include <stdio.h>

#define MOD 1000000007

long long int A, B, C;
long long int r, c;

long long int mod_pow(long long int x, long long int p)
{
	long long int temp = 1;
	while (p)
	{
		if (p & 1)
		{
			temp *= x;
			temp %= MOD;
		}
		x *= x;
		x %= MOD;
		p >>= 1;
	}
	return temp;
}

long long int mod_inv(long long int x)
{
	return mod_pow(x, MOD - 2);
}

int main()
{
	scanf("%lld%lld%lld", &A, &B, &C);

	long long int den = ((B*C) % MOD - (A*C) % MOD - (A*B) % MOD + 2 * MOD) % MOD;
	r = ((((A*C) % MOD - (B*C) % MOD + MOD) % MOD) * mod_inv(den)) % MOD;
	c = ((((A*B) % MOD - (B*C) % MOD + MOD) % MOD) * mod_inv(den)) % MOD;

	printf("%lld %lld\n", r, c);
	return 0;
}