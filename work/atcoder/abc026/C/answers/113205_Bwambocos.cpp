#include <stdio.h>
#include <algorithm>
#define INF 123456789

int N, B[21];

int f(int num)
{
	int max = -INF, min = INF;
	for (int i = 0; i < N; ++i)
	{
		if (B[i] == num)
		{
			max = std::max(max, f(i + 2));
			min = std::min(min, f(i + 2));
		}
	}
	max = (max == -INF ? 0 : max);
	min = (min == INF ? 0 : min);
	return (max + min + 1);
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) { scanf("%d", &B[i]); }

	printf("%d\n", f(1));
	return 0;
}