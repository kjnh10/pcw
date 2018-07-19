#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 210000;

typedef long long ll;

int a[maxn], b[maxn],c[maxn];

int main(int argc, char * argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;++i) scanf("%d", &a[i]);
	for (int i = 1;i <= n;++i) scanf("%d", &b[i]);
	int ans = 0;
	for (int i = 1;i <= 29;++i)
	{
		for (int j = 1;j <= n;++j) c[j] = b[j] % (1 << i);
		sort(c + 1, c + n + 1);
		ll ones = 0;
		for (int j = 1;j <= n;++j)
		{
			if ((a[j] & (1 << (i - 1))) == 0)
			{
				ones += lower_bound(c+1,c+n+1,(1<<i)-(a[j]%(1<<i))) - lower_bound(c + 1, c + n + 1, (1 << (i-1)) - (a[j] % (1 << i)));
			}
			else
			{
				ones += lower_bound(c + 1, c + n + 1, (1 << i) -(a[j] % (1 << i))) - c - 1;
				if (i != 1)
				{
					ones += n + 1 - (lower_bound(c + 1, c + n + 1, (1 << i) + (1 << (i-1)) - (a[j] % (1 << i))) - c);
				}
			}
		}
		if (ones & 1) ans ^= (1 << (i - 1));
	}
	printf("%d\n", ans);
	return 0;
}