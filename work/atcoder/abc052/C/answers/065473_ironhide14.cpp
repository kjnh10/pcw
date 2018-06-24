#include <bits/stdc++.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(0);cin.tie(0)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define slld(t) scanf("%lld",&t)
#define plld(t) printf("%lld\n",t)
#define sc(t) scanf("%c",&t)
#define pb(x) push_back(x)
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi >
#define vii vector<ii >
#define vvii vector<vii >
#define clr(x) memset(x,0,sizeof(x))
#define rep(i,begin,end) for(__typeof(end) i=begin-(begin>end);i!=end-(begin>end);i+=1-2*(begin>end))
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define MAX 100005
#define EPS 1e-12
using namespace std;

int main()
{
	int n; sd(n);
	map<ll,ll> m;

	for(ll i=1; i<=n; i++)
	{
		ll x = i;
		for(ll j=2; j<=n; j++)
		{
			while(x%j==0)
			{
				m[j]++;
				x /= j;
			}
		}
		if(x > 1) m[x]++;
	}

	ll ans = 1;
	for(auto it:m) ans = (ans * (it.second+1))%MOD;
	plld(ans);
	return 0;
}
