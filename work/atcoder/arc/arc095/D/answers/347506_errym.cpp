#include <bits/stdc++.h>
using namespace std;

int a[100005], n, b;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", a+i);
	sort(a, a+n); b = a[0];
	for (int i = 1;i < n-1;i++) if (abs(a[i]*2-a[n-1]) < abs(b*2-a[n-1])) b = a[i];
	printf("%d %d\n", a[n-1], b);
	return 0;
}
