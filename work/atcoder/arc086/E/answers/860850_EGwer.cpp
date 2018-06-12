#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
typedef pair<ll, ll>pii;
vector<int>ko[200000];
vector<vector<int> >gr[200000];
int dep[200000];
int las[200000];
int sec[200000];
int md[200000];
int cnt[200000];
ll p2[200001];
void dfs1(int node, int d)
{
	dep[node] = d;
	for (int i = 0; i < ko[node].size(); i++)dfs1(ko[node][i], d + 1);
}
int dfs2(int node)
{
	vector<int>v;
	for (int i = 0; i < ko[node].size(); i++)
	{
		int t = dfs2(ko[node][i]);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	if (v.size() <= 1)sec[node] = -1;
	else sec[node] = v[1];
	if (v.size() == 0)return md[node] = dep[node];
	else return md[node] = v[0];
}
void dfs3(int node)
{
	gr[dep[node]][las[dep[node]]].push_back(gr[dep[node]].size());
	vector<int>z;
	gr[dep[node]].push_back(z);
	cnt[dep[node]]++;
	vector<int>keep;
	for (int j = dep[node] + 1; j <= sec[node]; j++)
	{
		//printf("   %d %d %d\n", j, las[j], gr[j].size());
		keep.push_back(las[j]);
		gr[j][las[j]].push_back(gr[j].size());
		las[j] = gr[j].size();
		gr[j].push_back(z);
	}
	for (int i = 0; i < ko[node].size(); i++)
	{
		dfs3(ko[node][i]);
	}
	for (int j = dep[node] + 1; j <= sec[node]; j++)
	{
		las[j] = keep[j - dep[node] - 1];
	}
}
pii calc(int n, int node)
{
	if (gr[n][node].size() == 0)return make_pair(1, 1);
	ll a = 1, b = 0, c = 0;
	for (int i = 0; i < gr[n][node].size(); i++)
	{
		pii z = calc(n, gr[n][node][i]);
		c = (c*(z.first + z.second) + b*z.second) % mod;
		b = (b*z.first + a*z.second) % mod;
		a = a*z.first%mod;
	}
	return make_pair((a + c) % mod, b);
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		ko[z].push_back(i + 1);
	}
	num++;
	dfs1(0, 0);
	dfs2(0);
	for (int i = 0; i <= md[0]; i++)
	{
		vector<int>z;
		gr[i].push_back(z);
	}
	dfs3(0);
	p2[0] = 1;
	for (int i = 1; i <= num; i++)p2[i] = p2[i - 1] * 2 % mod;
	ll ans = 0;
	for (int i = 0; i <= md[0]; i++)ans = (ans + calc(i, 0).second*p2[num - cnt[i]]) % mod;
	printf("%lld\n", ans);
}