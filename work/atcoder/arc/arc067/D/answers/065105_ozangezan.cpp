#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int x[110000];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++){
		scanf("%d",x+i);
	}
	long long ret=0;
	for(int i=0;i<a-1;i++){
		int d=x[i+1]-x[i];
		ret+=min((long long)c,(long long)b*d);
	}
	printf("%lld\n",ret);
}