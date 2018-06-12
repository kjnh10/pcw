#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char str[210000];
int main(){
	scanf("%s",str);
	int n=strlen(str);
	for(int i=0;i<n-1;i++)if(str[i]==str[i+1]){
		printf("%d %d\n",i+1,i+2);return 0;
	}
	for(int i=0;i<n-2;i++)if(str[i]==str[i+2]){
		printf("%d %d\n",i+1,i+3);return 0;
	}
	printf("-1 -1\n");
}