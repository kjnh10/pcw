#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
long long p10[10];
int main(){
	int a;scanf("%d",&a);
//	mod=b;
	p10[0]=1;
	for(int i=1;i<10;i++)p10[i]=p10[i-1]*10;
	long long ret=0;
	// 小さいの
	for(int i=1;i<=9;i++){
		for(int j=i;j<=9;j++){
			long long cur=0;
			for(int k=i+1;k<j;k++){
				cur+=k*(p10[k]-p10[k-1]);
			}
			if(cur>a)continue;
			if(i==j){
				if(a%i||(a/i)>p10[i]-p10[i-1])continue;
				ret=(ret+p10[i]-p10[i-1]-(a/i)+1)%mod;
	//			printf("%d %d: %lld\n",i,j,ret);
				continue;
			}
			for(int k=1;k<=p10[i]-p10[i-1];k++){
				long long t=a-cur-k*i;
				if(t<=0)break;
				if(t%j)continue;
				if(t/j<=p10[j]-p10[j-1])ret++;
			}
			ret%=mod;
	//		printf("%d %d: %lld\n",i,j,ret);
		}
	}
	// 8888888みたいなやつ
	int rem=(a-1)/9;
	for(int i=1;i*i<=a;i++){
		if(a%i==0){
			int S=i;
			int T=a/i;
			if(S>9){
				rem--;
		//		printf("%d\n",S);
				ret=(ret+pw(10,S)+mod-pw(10,S-1)+1+mod-T)%mod;
			}
			if(S==T)continue;
			if(T>9){
				rem--;
		//		printf("%d\n",T);
				ret=(ret+pw(10,T)+mod-pw(10,T-1)+1+mod-S)%mod;
			}
		}
	}
	//printf("%lld\n",ret);
	// 8888999みたいなやつ
	ret=(ret+rem)%mod;
	printf("%lld\n",ret);
}