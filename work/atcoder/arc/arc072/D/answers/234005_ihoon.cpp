#include<cstdio>
int main(){
	long long a,b;
	scanf("%lld %lld",&a,&b);
	if(a<b){
		long long c = a;
		a = b;
		b = c;
	}
	if(a-b>=2){
		printf("Alice\n");
	}else{
		printf("Brown\n");
	}
}