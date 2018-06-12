#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
int a[1001];
vi adj[1001];
int s[1001];

void dfs(int u, int p)
{
	vector<int> dp(5001,int(1e9));
	dp[0]=0;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		dfs(v,u);
		vector<int> dp2(5001,int(1e9));
		for(int j=0;j<=5000;j++)
		{
			if(j-a[v]>=0)
			{
				dp2[j] = min(dp2[j],dp[j-a[v]]+s[v]);
			}
			if(j-s[v]>=0)
			{
				dp2[j] = min(dp2[j],dp[j-s[v]]+a[v]);
			}
		}
		dp=dp2;
	}
	s[u]=int(1e9);
	for(int i=0;i<=a[u];i++)
	{
		//cerr<<u<<' '<<i<<' '<<dp[i]<<'\n';
		s[u]=min(s[u],dp[i]);
	}
	//cerr<<u<<' '<<s[u]<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int p; cin>>p;
		p--;
		adj[p].pb(i+1);
	}
	for(int i=0;i<n;i++) cin>>a[i];
	dfs(0,-1);
	if(s[0]>=int(1e9))
	{
		cout<<"IMPOSSIBLE\n";
	}
	else
	{
		cout<<"POSSIBLE\n";
	}
}
