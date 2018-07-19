#include<bits/stdc++.h>
using namespace std;
#define i64 long long int
int n,k;
pair<i64,int> a[1111];int top;
void pus(i64 x){
	int r = 0;
	for(i64 y = x; y; y/=10)
		r += y%10;
	while(top > 0 && a[top-1].first * r > a[top-1].second * x)
		--top;
	a[top++] = make_pair(x,r);
}
int main(){
	for(int i=1; i<1000000; i++){
		pus(i);
	}
	i64 cur = 10;
	for(int k=7; k<=15; k++,cur*=10){
		for(int i=100000; i<1000000; i++)
			pus((i+1)*cur-1);
	}
//	k=top;
	scanf("%d",&k);
	for(int i=0; i<k; i++)
		printf("%lld\n",a[i].first);
	return 0;
}
