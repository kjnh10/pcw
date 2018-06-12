#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<queue>
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
ll dp[100][100][100];
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	string s;
	cin >> s;
	invinit();
	ll ans = 0;
	for (int p = 0; p <= kai / 2; p++)
	{
		for (int q = 0; q <= kai - p * 2; q++)
		{
			if (p + q + (p + q - 1)>num)continue;
			int d[100];
			fill(d, d + 100, 0);
			queue<int>que;
			int np = 0;
			for (int i = 0; i < s.size(); i++)
			{
				if (np == p)break;
				if (s[i] == 'r')que.push(i);
				else
				{
					if (que.empty())continue;
					int z = que.front();
					que.pop();
					d[z] = 1, d[i] = 2;
					np++;
				}
			}
			if (np != p)continue;
			int nq = 0;
			for (int i = 0; i < s.size(); i++)
			{
				if (nq == q)break;
				if (d[i] == 0 && s[i] == 'r')d[i] = 3, nq++;
			}
			if (nq != q)continue;
			//printf("%d %d ", p, q);
			//for (int i = 0; i < kai; i++)printf("%d", d[i]); printf("\n");
			vector<int>v;
			int cnt = 0;
			for (int i = s.size() - 1; i >= 0; i--)
			{
				if (d[i] == 0)cnt++;
				if (d[i] == 2)v.push_back(cnt);
			}
			for (int i = 0; i <= v.size(); i++)for (int j = 0; j <= cnt + 1; j++)for (int k = 0; k <= cnt + 1; k++)dp[i][j][k] = 0;
			dp[0][0][0] = 1;
			for (int i = 0; i <= v.size(); i++)
			{
				for (int j = 0; j <= cnt; j++)
				{
					for (int k = 0; k <= cnt; k++)
					{
						if (dp[i][j][k] == 0)continue;
						dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i][j][k]) % mod;
						for (int l = 1; i + l <= v.size(); l++)
						{
							if (v[i + l - 1] < j + k*l)break;
							dp[i + l][j + k*l][k + 1] = (dp[i + l][j + k*l][k + 1] + dp[i][j][k] * com(i + l, l)) % mod;
						}
					}
				}
			}
			ll t[100];
			for (int i = 0; i <= cnt; i++)t[i] = dp[v.size()][i][cnt + 1];
			//for (int i = 0; i <= cnt; i++)printf(" %lld", t[i]); printf("\n");
			ll sum = 0;
			for (int i = 0; i <= cnt; i++)
			{
				int ned = q + p + 2 * i + (p + q - 1);
				int add = q + 3 * p + 2 * i + (p + q + 1);
				if (ned > num)continue;
				sum += t[i] * com(num - ned + add - 1, add - 1);
				sum %= mod;
			}
			//printf(" %lld\n", sum);
			ans = (ans + sum*com(p + q, p)) % mod;
		}
	}
	printf("%lld\n", ans);
}