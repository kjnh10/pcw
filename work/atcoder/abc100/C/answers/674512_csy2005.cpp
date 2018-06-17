#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,num[500005],x,ans;
string st;
int main()
{
	cin>>n;
	while (n--)
	{
		cin>>x;
		while (x%2==0)
		{
			ans++;
			x/=2;
		}
	}
	cout<<ans;
	return 0;
}