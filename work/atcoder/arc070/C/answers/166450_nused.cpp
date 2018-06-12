#include <bits/stdc++.h>
using namespace std;

int main()
{
	int X;
	scanf("%d", &X);
	for (int t = 1;; t++)
	{
		if (t * (t + 1ll) / 2 >= X)
		{
			printf("%d\n", t);
			return 0;
		}
	}
}