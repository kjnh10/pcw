#include<bits/stdc++.h>
using namespace std;


const long long MOD = 1000000007;

long long arr[100005];

long long fast(long long a,long long b)
{
	long long ans = 1;
	while(b!=0)
	{
		if(b%2==1) ans = (ans*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}

int main()
{
	long long n,m;
	cin>>n>>m;
	long long xx = 0;
	long long yy = 0;
	for(int a=1;a<=n;a++)
	{
		cin>>arr[a];
		if(a!=1)
		{
			xx = (xx + (arr[a] - arr[a-1])*(a-1)*(n-a+1) )%MOD;
		}
	}
	for(int a=1;a<=m;a++)
	{
		cin>>arr[a];
		if(a!=1)
		{
			yy = (yy + (arr[a] - arr[a-1])*(a-1)*(m-a + 1) )%MOD;
		}
	}
	cout<<(xx*yy)%MOD<<endl;

}