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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int dp[200001][27];
int idx[200001][27];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)
		{
			dp[i][j]=n+10;
		}
	}
	memset(idx,-1,sizeof(idx));
	for(int i = 0; i < 26; i++)
	{
		dp[n-1][i] = 1;
	}
	dp[n-1][s[n-1]-'a'] = 2;
	idx[n-1][s[n-1]-'a'] = 0;
	string ans;
	for(int i = n - 2; i >= 0; i--)
	{
		for(int j = 0; j < 26; j++)
		{
			if(s[i]==j+'a')
			{
				for(int k = 0; k < 26; k++)
				{
					if(dp[i+1][k] + 1 < dp[i][j])
					{
						dp[i][j] = dp[i+1][k] + 1;
						idx[i][j] = k;
					}
				}
			}
			else
			{
				if(dp[i+1][j] < dp[i][j])
				{
					idx[i][j] = j;
					dp[i][j] = dp[i+1][j];
				}
			}
		}
	}
	int cur = 0;
	int best = -1; int mini = 100000000;
	for(int i = 0; i < 26; i++)
	{
		if(dp[0][i] < mini)
		{
			mini=dp[0][i];
			best=i;
		}
	}
	ans+=char('a'+best);
	cur = best;
	for(int i = 0; i < n; i++)
	{
		if(i+1<n)
		{
			if(dp[i][cur]>dp[i+1][idx[i][cur]])
			{
				ans+=char('a'+idx[i][cur]);
			}
		}
		else
		{
			if(idx[i][cur]!=-1)
			{
				ans+=char('a'+idx[i][cur]);
			}
		}
		//cerr<<i<<' '<<cur<<'\n';
		cur=idx[i][cur];
	}
	cout<<ans<<'\n';
}
