#include <stdio.h>
#include <algorithm>

long long int N;
long long int depth = -1, x = 1;

int main(void)
{
	scanf("%lld", &N);

	for (long long int i = N; i > 0; i /= 2)
	{
		++depth;
	}
	while (true)
	{
		x = (2 * x) + ((depth + 1) % 2);
		if (x > N)
		{
			printf("Aoki\n");
			break;
		}
		x = (2 * x) + (depth % 2);
		if (x > N)
		{
			printf("Takahashi\n");
			break;
		}
	}
	return 0;
}