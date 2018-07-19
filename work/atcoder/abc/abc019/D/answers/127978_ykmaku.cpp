#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	int long1 = 0,i1;
	int dist;

	for(int i = 2; i <= n; i++)
	{
		printf("? %d %d\n", 1, i);
		fflush(stdout);
		scanf("%d", &dist);

		if (long1 < dist)
		{
			long1 = dist;
			i1 = i;
		}
	}

	int long2 = 0;

	for(int i = 1; i <= n; i++)
	{
		if (i != i1)
		{
			printf("? %d %d\n", i1, i);
			fflush(stdout);
			scanf("%d", &dist);

			if (long2 < dist)
			{
				long2 = dist;
			}
		}
	}

	printf("! %d\n", long2);

	return 0;
}
	