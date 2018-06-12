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

ll powers[11];
const int MOD=1e9+7;

int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}

int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

int digits(int x)
{
	int cnt=0;
	while(x)
	{
		cnt++; x/=10;
	}
	return cnt;
}

int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}

ll power10(int x)
{
	if(x<=9) return powers[x];
	else return ll(1e9)+10;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	powers[0] = 1;
	for(int i=1;i<=10;i++)
	{
		powers[i]=powers[i-1]*10;
	}
	ll S; cin>>S;
	int ans = 0;
	ll r = 0; ll sum = 0; int ptr = 1;
	for(ll l = 1; l < powers[7]; l++) //search for those with starting spot <= 7 digits
	{
		while(sum<S)
		{
			r++;
			if(r==powers[ptr]) ptr++;
			sum+=ptr;
		}
		if(sum==S) ans=add(ans,1);
		sum-=digits(l);
	}
	//d >= 8
	vector<ll> divisors;
	for(ll i = 1; i*i<=S; i++)
	{
		if(S%i==0)
		{
			divisors.pb(i);
			if(i*i!=S) divisors.pb(S/i);
		}
	}
	for(ll d:divisors)
	{
		if(d<=7) continue;
		int tot = modpow(10, d) - modpow(10, d - 1); //total number
		ll len = S/d;
		if(d>=9||tot>=len)
		{
			ans = add(ans, add(tot + 1, MOD - len));
		}
	}
	//2 cover
	for(ll d = 8; d <= (S+1)/2; d++)
	{
		ll r = S%d;
		if(r==0) r=d;
		ll num = (S - 1)/(d+1);
		num-=r;
		if(num<0) continue;
		ans = add(ans, num/d + 1);
	}
	cout<<ans<<'\n';
}
