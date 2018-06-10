#include<stdio.h>
#include<algorithm>
using namespace std;
long long mod=1000000007;
long long fact[510000];
long long inv[510000];
long long factinv[510000];
int M=505000;
long long C(int a,int b){
	return fact[a]*factinv[b]%mod*factinv[a-b]%mod;
}
int main(){
	inv[1]=fact[0]=factinv[0]=1;
	for(int i=2;i<M;i++)inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	for(int i=1;i<M;i++)fact[i]=fact[i-1]*i%mod;
	for(int i=1;i<M;i++)factinv[i]=factinv[i-1]*inv[i]%mod;
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	long long ret=0;
	for(int i=0;i<a-c;i++){
		ret=(ret+C(i+d-1,i)*C(a-i-1+b-d-1,a-i-1))%mod;
	}
	printf("%lld\n",ret);
}