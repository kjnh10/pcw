#include <stdio.h>
#include <algorithm>

int l[3];

int main(void)
{
	scanf("%d%d%d", &l[0], &l[1], &l[2]);

	std::sort(l, l + 3);

	if (l[0] == l[1])
	{
		printf("%d\n", l[2]);
	}
	else if (l[1] == l[2])
	{
		printf("%d\n", l[0]);
	}
	return 0;
}