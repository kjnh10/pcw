#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005], n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", a+i), b[i] = a[i];
	sort(b, b+n);
	int m1 = b[n/2-1], m2 = b[n/2];
	for (int i = 0;i < n;i++)
		if (a[i] <= m1) printf("%d\n", m2);
		else printf("%d\n", m1);
	return 0;
}
