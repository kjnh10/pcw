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
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dp[41][401][401];

int a[41];
int b[41];
int c[41];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp,-1,sizeof(dp));
	int ma, mb;
	int n;
	cin>>n>>ma>>mb;
	for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
	dp[0][0][0] = 0;
	dp[0][a[0]][b[0]] = c[0];
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= 400; j++)
		{
			for(int k = 0; k <= 400; k++)
			{
				dp[i][j][k] = 100000000;
				if(dp[i-1][j][k]!=-1)
				{
					dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);
				}
				if(j>=a[i]&&k>=b[i]&&dp[i-1][j-a[i]][k-b[i]]!=-1)
				{
					dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-a[i]][k-b[i]]+c[i]);
				}
				
				if(dp[i][j][k]>=100000000) dp[i][j][k]=-1;
			}
		}
	}
	int ans = 100000000;
	for(int i = 1; i*max(ma,mb)<=400; i++)
	{
		if(dp[n-1][i*ma][i*mb]!=-1) ans=min(ans,dp[n-1][i*ma][i*mb]);
	}
	if(ans==100000000) cout<<-1<<'\n';
	else cout<<ans<<'\n';
}
