#include<bits/stdc++.h>
#define ll long long
using namespace std;

char ch[10];
int main(){
	ll i,len=0;
	for (i=1; i<=10000000000ll; i*=10,len++){
		printf("? %lld\n",i); fflush(stdout);
		scanf("%s",ch);
		if (ch[0]=='N') break;
	}
	if (i>10000000000ll){
		for (i=9; i<=999999999ll; i=i*10+9){
			printf("? %lld\n",i); fflush(stdout);
			scanf("%s",ch);
			if (ch[0]=='Y') break;
		}
		printf("! %lld\n",i/10+1); fflush(stdout);
		return 0;
	}
	i/=10; len--;
	ll l=i,r=i*10-1;
	while (l<r){
		ll mid=l+r>>1;
		printf("? %lld\n",mid*10+9); fflush(stdout);
		scanf("%s",ch);
		if (ch[0]=='N') l=mid+1; else r=mid;
	}
	printf("! %lld\n",l);
	return 0;
}
