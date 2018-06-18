#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll ans=0;
	if(n>m/2){
		printf("%lld\n",m/2);
	}else{
		printf("%lld\n",n+(m-n*2)/4);
	}
	return 0;
}