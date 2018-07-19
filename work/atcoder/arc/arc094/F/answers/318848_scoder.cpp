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

const int MOD = 998244353;

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

set<string> S;

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

int calc(string &s)
{
	int n=s.length();
	int diff=0;
	for(int i=0;i<n-1;i++)
	{
		diff+=(s[i]!=s[i+1]);
	}
	if(diff==0) return 1;
	int ans=add(modpow(3,n-1),MOD-modpow(2,n-1));
	if(n%3==0)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=s[i]-'a';
		}
		sum%=3;
		if(sum==0) 
		{
			ans=add(ans,MOD-modpow(2,n/3));
			if(n==3) ans=add(ans,MOD-1);
		}
		else ans=add(ans,modpow(2,n/3-1));
	}
	if(diff==n-1) ans=add(ans,1);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s; cout<<calc(s)<<'\n'; return 0;
	/*
	string s; cin>>s;
	int n=s.length();
	S.insert(s);
	queue<string> q;
	q.push(s);
	while(!q.empty())
	{
		string u=q.front(); q.pop();
		//cerr<<u<<'\n';
		for(int i=0;i<n-1;i++)
		{
			if(u[i]!=u[i+1])
			{
				string t=u;
				if((u[i]=='a'&&u[i+1]=='b')||(u[i]=='b'&&u[i+1]=='a')) t[i]=t[i+1]='c';
				else if((u[i]=='c'&&u[i+1]=='b')||(u[i]=='b'&&u[i+1]=='c')) t[i]=t[i+1]='a';
				else if((u[i]=='a'&&u[i+1]=='c')||(u[i]=='c'&&u[i+1]=='a')) t[i]=t[i+1]='b';
				if(S.find(t)==S.end()) q.push(t);
				S.insert(t);
			}
		}
	}	
	cerr<<S.size()<<' '<<calc(s)<<'\n';
	*/
}
