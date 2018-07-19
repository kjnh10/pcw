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
int pr[2000];
int main(){
	int a;scanf("%d",&a);
	long long ret=1;
	pr[0]=pr[1]=-1;
	for(int i=2;i<2000;i++){
		if(pr[i]!=-1){
			pr[i]=1;
			for(int j=i*2;j<2000;j+=i)pr[j]=-1;
		}
	}
	for(int i=0;i<2000;i++){
		if(pr[i]==1){
			int c=a;
			int now=0;
			while(c){
				now+=c/i;
				c/=i;
			}
			ret=ret*(1+now)%mod;
		}
	}
	printf("%lld\n",ret);
}