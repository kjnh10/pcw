#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int m[100];

int main()
{
	int n,x;
	int ans=0;
	int s=0;
	
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>m[i];
		s+=m[i];
	}
	sort(m,m+n);
	x-=s;
	ans+=n;
	ans+=x/m[0];
	cout<<ans<<endl;
	return 0;
}