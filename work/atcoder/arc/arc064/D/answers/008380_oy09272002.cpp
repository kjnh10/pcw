#include<bits/stdc++.h>
using namespace std;
int main(){
	char c[100005];
	scanf("%s",c);
	int length=strlen(c);
	if(length%2==0){
		if(c[0]!=c[length-1])
		printf("Second\n");
		else
		printf("First\n");
	}
	else if(length%2==1){
		if(c[0]!=c[length-1])
		printf("First\n");
		else
		printf("Second\n") ;
	}
} 