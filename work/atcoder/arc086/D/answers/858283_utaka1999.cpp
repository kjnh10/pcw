#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <stack>
#include <string>
#include <cmath>
#define SIZE 55

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll A[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	vector <P> ans;
	P mx=P(A[0],0),mn=mx;
	for(int i=0;i<n;i++) mx=max(mx,P(A[i],i)),mn=min(mn,P(A[i],i));
	if(mx.first+mn.first>=0)
	{
		for(int i=0;i<n;i++)
		{
			if(i==mx.second) continue;
			ans.push_back(P(mx.second,i));
			A[i]+=mx.first;
		}
		for(int i=0;i+1<n;i++) ans.push_back(P(i,i+1));
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(i==mn.second) continue;
			ans.push_back(P(mn.second,i));
			A[i]+=mx.first;
		}
		for(int i=n-1;i>=1;i--) ans.push_back(P(i,i-1));
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		P p=ans[i];
		printf("%d %d\n",p.first+1,p.second+1);
	}
	return 0;
}
