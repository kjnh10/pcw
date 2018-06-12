#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <string>
#define SIZE 5005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

bool dp[SIZE];
int A[SIZE];
P pos[SIZE];

int main()
{
	int n,K;
	scanf("%d %d",&n,&K);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	//iを含む中で、K以上K+A[i]未満のものがあればok
	//i以外でぎりぎりK未満のものがあればよさそう
	sort(A,A+n);
	ll sum=0;
	for(int i=0;i<n;i++) sum+=A[i];
	memset(dp,false,sizeof(dp));
	dp[0]=true;
	int ret=0;
	for(int i=n-1;i>=0;i--)
	{
		bool up=false;
		for(int j=0;j<K;j++)
		{
			if(dp[j]&&j+sum>=K) up=true;
		}
		if(!up) ret++;
		sum-=A[i];
		for(int j=K-1;j>=A[i];j--) dp[j]|=dp[j-A[i]];
	}
	printf("%d\n",ret);
	return 0;
}
