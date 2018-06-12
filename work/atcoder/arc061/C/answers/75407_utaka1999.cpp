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
#define SIZE 12

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	ll ret=0;
	for(int S=0;S<1<<(n-1);S++)
	{
		ll now=0;
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			now*=10LL;
			now+=str[i]-'0';
			if(i<n-1&&(S>>i&1))
			{
				sum+=now;
				now=0;
			}
		}
		sum+=now;
		ret+=sum;
	}
	printf("%lld\n",ret);
	return 0;
}
