#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int p10[9];
int main()
{
	int num;
	scanf("%d", &num);
	int pt = 0;
	ll rem = 0;
	ll sum = 0;
	ll ans = 0;
	p10[0] = 1;
	for (int i = 1; i < 9; i++)p10[i] = p10[i - 1] * 10;
	for (int i = 1; i <= 8; i++)
	{
		int t = 9 * p10[i - 1];
		for (int j = 0; j < t; j++)
		{
			sum += i;
			for (;;)
			{
				if (sum <= num)break;
				if (rem == 0)
				{
					pt++;
					rem = 9 * p10[pt - 1];
				}
				rem--;
				sum -= pt;
			}
			if (sum == num)ans++;
		}
	}
	ll len = p10[8] * 9;
	for (int i = 9; i <= num; i++)
	{
		if (num%i == 0)ans += len + mod - num / i + 1;
		if (i + i - 1 <= num)
		{
			int t = num - i - i + 1;
			int mini = (i - t % i);
			if (mini == i)mini = 0;
			int ea = (t + mini) / i - mini;
			int ba = t % (i - 1);
			ans += max(0, (ea - ba) / (i - 1) + 1);
		}
		len = len * 10 % mod;
	}
	printf("%lld\n", ans % mod);
}