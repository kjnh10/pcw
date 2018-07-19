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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll query(ll x, ll y)
{
	ll lo = 0; ll hi = ll(3e9);
	ll ans = 0;
	while(lo<=hi)
	{
		ll mid=(lo+hi)>>1; ll tmp=0;
		for(ll i=max(mid/2-50,1LL); i<=min(mid/2+50,mid); i++)
		{
			//pair i-th smallest with i-th greatest
			ll L = i;
			if(i>=x) L++;
			ll R = mid + 1 - i;
			if(i<=mid-y+1) R++;
			tmp=max(tmp,L*R);
		}
		if(tmp<x*y)
		{
			ans=mid; lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	while(q--)
	{
		ll x,y; cin>>x>>y;
		cout<<query(x,y)<<'\n';
	}
}
