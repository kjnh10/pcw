#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	long long a,b;scanf("%lld%lld",&a,&b);
	long long c=2000000000000LL;
	if(b==0){
		printf("%lld\n",c-a);
		return 0;
	}
	int ret=0;
	while(a<c){
		ret++;
		a=a+1+b*a;
	}
	printf("%d\n",ret);
}