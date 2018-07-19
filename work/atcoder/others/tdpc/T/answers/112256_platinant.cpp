#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MOD (ll)(1e9+7)

ll N,K;
const int MAX_K = 1010;
ll cur[MAX_K],pre[MAX_K],tem[MAX_K],C[MAX_K];

int st[100],sz;

void f(int n){
	if(n==K+1)return;
	if(n<(K+1)*2){
		st[sz++]=1;
		f(n-1);
		return;
	}
	if(n&1){
		st[sz++]=1;
		f(n-1);
	}else{
		st[sz++]=0;
		f(n/2);
	}
}

int main(){

	scanf("%lld%lld",&K,&N);
	
	if(N<=K){
		puts("1");
		return 0;
	}
	
	for(int i=0;i<K;i++)cur[i]=1;

	f(N);

	while(sz--){
		if(st[sz]){
			swap(cur,pre);
			for(int i=0;i<K;i++){
				cur[i]=(pre[0]+(i+1<K?pre[i+1]:0))%MOD;
			}
		}else{
			for(int j=0;j<K;j++)C[j]=cur[j];
			for(int j=0;j<K;j++)tem[j]=0;
			for(int j=K-1;j>=0;j--){
				swap(cur,pre);
				ll sum=0;
				for(int i=0;i<K;i++){
					cur[i]=(pre[0]+(i+1<K?pre[i+1]:0))%MOD;
					tem[i]+=C[j]*cur[i]%MOD;
					tem[i]%=MOD;
				}
			}
			swap(cur,tem);
		}
	}

	ll ans=0;
	for(int i=0;i<K;i++){
		ans+=cur[i];
		ans%=MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
