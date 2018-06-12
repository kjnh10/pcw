#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
ll dist[5000];
ll ans[5011][5011];
typedef pair<ll, ll>pii;
vector<pii>dat[200];
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	for (int i = 1; i < num; i++)scanf("%lld", &dist[i]);
	for (int i = 1; i < num; i++)dist[i] += dist[i - 1];
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < kai; j++)
		{
			ll z;
			scanf("%lld", &z);
			dat[j].push_back(make_pair(z, i));
		}
	}
	for (int i = 0; i < kai; i++)sort(dat[i].begin(), dat[i].end()), reverse(dat[i].begin(), dat[i].end());
	for (int i = 0; i < kai; i++)
	{
		set<int>se;
		se.insert(-1);
		se.insert(num);
		for (int j = 0; j < num; j++)
		{
			set<int>::iterator it = se.lower_bound(dat[i][j].second);
			int a = *it;
			it--;
			int b = *it;
			int c = dat[i][j].second;
			ll x = dat[i][j].first;
			ans[c + 1][c + 1] += x;
			ans[c + 1][a + 1] -= x;
			ans[b + 1][c + 1] -= x;
			ans[b + 1][a + 1] += x;
			se.insert(c);
		}
	}
	for (int i = num - 1; i >= 0; i--)
	{
		for (int j = 1; j <= num; j++)
		{
			ans[i + 1][j + 1] += ans[i + 2][j + 1] + ans[i + 1][j] - ans[i + 2][j];
		}
	}
	ll maxi = 0;
	for (int i = 0; i < num; i++)
	{
		//printf("%lld\n", dist[i]);
		for (int j = i; j < num; j++)
		{
			maxi = max(maxi, ans[i + 1][j + 1] - dist[j] + dist[i]);
		}
		//for (int j = 0; j < num; j++)printf("%lld ", ans[i][j]); printf("\n");
	}
	printf("%lld\n", maxi);
}