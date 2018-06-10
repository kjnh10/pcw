#include<stdio.h>
#include<algorithm>
using namespace std;
int c[20];
int d[20];
char str[20];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++)scanf("%d",c+i);
	for(int i=0;i<b;i++)d[c[i]]=1;
	for(int i=a;;i++){
		sprintf(str,"%d",i);
		bool ok=true;
		for(int j=0;str[j];j++)if(d[str[j]-'0'])ok=false;
		if(ok){
			printf("%d\n",i);return 0;
		}
	}
}