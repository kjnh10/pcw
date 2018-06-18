#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define MAX 100005
#define MOD 1000000007
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mt make_tuple
#define eb emplace_back
#define INF 1e9
#define PI 3.141592653589793238
#define EPS 1e-9
ll modexp(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res = (res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
int ck(string str)
{
	if(str.size()&1) return 0;
	int n = str.size();
	int i;
	string str1,str2;
	str1 = str.substr(0,n/2);
	str2 = str.substr(n/2);
	return str1 == str2;
}
int main()
{
	string str;
	cin>>str;
	while(1)
	{
		str = str.substr(0,str.size()-1);
		if(ck(str))
		{
			cout<<str.size()<<endl;
			return 0;
		}
	}
	return 0;
}