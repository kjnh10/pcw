#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <stack>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <P> vec;
vector <P> at;
ll cnt[15];

bool ex(int x,int y)
{
	int pos=lower_bound(vec.begin(),vec.end(),P(x,y))-vec.begin();
	return pos<vec.size()&&vec[pos]==P(x,y);
}
int main()
{
	ll H,W;
	int n;
	scanf("%lld %lld %d",&H,&W,&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		for(int j=a-2;j<=a;j++)
		{
			for(int k=b-2;k<=b;k++)
			{
				if(j>=0&&k>=0&&j+2<H&&k+2<W)
				{
					at.push_back(P(j,k));
				}
			}
		}
		vec.push_back(P(a,b));
	}
	sort(at.begin(),at.end());
	at.erase(unique(at.begin(),at.end()),at.end());
	sort(vec.begin(),vec.end());
	cnt[0]=(H-2)*(W-2)-at.size();
	for(int i=0;i<at.size();i++)
	{
		int x=at[i].first,y=at[i].second;
		int nm=0;
		for(int j=x;j<=x+2;j++)
		{
			for(int k=y;k<=y+2;k++)
			{
				nm+=ex(j,k);
			}
		}
		cnt[nm]++;
	}
	for(int i=0;i<10;i++) printf("%lld\n",cnt[i]);
	return 0;
}
