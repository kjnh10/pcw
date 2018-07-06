#include <stdio.h>

char S[6];
int N;
int cou;
char ans[3];

int main(void)
{
	scanf("%s%d", S, &N);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			++cou;
			if (cou == N)
			{
				printf("%c%c\n", S[i], S[j]);
				return 0;
			}
		}
	}
	return 0;
}