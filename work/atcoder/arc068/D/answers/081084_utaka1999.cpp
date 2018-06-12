#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int A[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	int nm=0;
	for(int i=0;i<n;)
	{
		int f=i,cnt=0;
		for(;i<n&&A[i]==A[f];i++) cnt++;
		cnt--;
		nm+=cnt;
	}
	if(nm%2==1) nm++;
	printf("%d\n",n-nm);
	return 0;
}
