#include <stdio.h>

int N, a[112];
bool same_flag = true;
int sum, ans;

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) { scanf("%d", &a[i]); }

	sum += a[0];
	for (int i = 1; i < N; ++i)
	{
		if (a[i - 1] != a[i])
		{
			same_flag = false;
		}
		sum += a[i];
		a[i] += a[i - 1];
	}
	if (sum % N != 0)
	{
		ans = -1;
	}
	if (same_flag == false && ans != -1)
	{
		sum /= N;
		for (int i = 0; i < N - 1; ++i)
		{
			int l = a[i], r = a[N - 1] - a[i];
			if (l != sum*(i + 1) || r != sum*(N - (i + 1)))
			{
				++ans;
			}
		}
	}

	if (same_flag == true)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}