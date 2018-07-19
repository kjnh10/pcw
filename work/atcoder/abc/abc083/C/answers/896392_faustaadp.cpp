#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,hs;
int main()
{
	cin>>a>>b;
	while(a<=b)
	{
		hs++;
		a*=2;
	}
	cout<<hs<<"\n";
}