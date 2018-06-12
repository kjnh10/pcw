#include<stdio.h>
#include<algorithm>
using namespace std;
int b[300];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	int ret=1000000007;
	for(int i=-200;i<=200;i++){
		int tmp=0;
		for(int j=0;j<a;j++){
			tmp+=(b[j]-i)*(b[j]-i);
		}
		ret=min(ret,tmp);
	}
	printf("%d\n",ret);
}