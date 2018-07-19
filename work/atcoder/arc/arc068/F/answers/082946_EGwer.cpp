#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define SIZE 100000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
ll dp[2100][2100];
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	invinit();
	for (int i = 1; i <= num; i++)
	{
		ll now = 0;
		for (int j = 1; j <= i - 1; j++)
		{
			dp[i][j] = (dp[i][j] + now) % mod;
			now += dp[i - 1][j];
			now %= mod;
		}
		for (int j = 1; j <= i - 1; j++)dp[i][j] = (dp[i][j] + com(num - kai + i - 1, num - kai)) % mod;
		for (int j = 0; j <= i; j++)dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
		//for (int j = 0; j <= i; j++)printf("%lld ", dp[i][j]); printf("\n");
	}
	ll s = com(num - 1, kai - 1);
	for (int i = 0; i <= num; i++)s += dp[kai - 1][i], s %= mod;
	for (int i = 0; i < num - kai - 1; i++)s = s * 2 % mod;
	printf("%lld\n", s);
}