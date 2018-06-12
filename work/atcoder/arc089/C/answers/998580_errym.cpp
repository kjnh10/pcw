#include <bits/stdc++.h>
using namespace std;

int t[100005], x[100005], y[100005];
int n;

int main()
{
	scanf("%d", &n); n++;
	for (int i = 1;i < n;i++) scanf("%d%d%d", t+i, x+i, y+i);
	for (int i = 1;i < n;i++)
	{
		int d = abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
		if (d > t[i]-t[i-1] || (d^(t[i]-t[i-1]))%2)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}
