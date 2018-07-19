#include <stdio.h>
#include <algorithm>

int N, A, B, d[112];
char s[112][5];
int ans;

int main(void)
{
	scanf("%d%d%d", &N, &A, &B);
	for (int i = 0; i < N; ++i) { scanf("%s%d", s[i], &d[i]); }

	for (int i = 0; i < N; ++i)
	{
		if (s[i][0] == 'E')
		{
			if (d[i] < A)
			{
				ans += A;
			}
			if (A <= d[i] && d[i] <= B)
			{
				ans += d[i];
			}
			if (d[i] > B)
			{
				ans += B;
			}
		}
		if (s[i][0] == 'W')
		{
			if (d[i] < A)
			{
				ans -= A;
			}
			if (A <= d[i] && d[i] <= B)
			{
				ans -= d[i];
			}
			if (d[i] > B)
			{
				ans -= B;
			}
		}
	}

	if (ans < 0)
	{
		printf("West %d\n", abs(ans));
	}
	else if (ans > 0)
	{
		printf("East %d\n", ans);
	}
	else
	{
		printf("0\n");
	}
	return 0;
}