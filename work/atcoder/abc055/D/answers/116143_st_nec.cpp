#include<cstdio>
#define N 100010
using namespace std;

int n;
char s[N];
int a[N];

void print(){
	for(int i=1;i<=n;i++) printf("%c",a[i]?'W':'S');
}

bool judge(int d,char c,int x,int y){
	if(d==0&&c=='o'&&x==y){return 1;}
	if(d==0&&c=='x'&&x!=y){return 1;}
	if(d==1&&c=='x'&&x==y){return 1;}
	if(d==1&&c=='o'&&x!=y){return 1;}
	return 0;
}

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int d0=0;d0<=1;d0++){
		for(int d1=0;d1<=1;d1++){
			a[1]=d0;a[2]=d1;
			for(int i=3;i<=n;i++){
				if(a[i-1]==0&&s[i-1]=='o') 
				a[i]=a[i-2];
				if(a[i-1]==0&&s[i-1]=='x') 
				a[i]=a[i-2]^1;
				if(a[i-1]==1&&s[i-1]=='x')
				 a[i]=a[i-2];
				if(a[i-1]==1&&s[i-1]=='o')
				 a[i]=a[i-2]^1;
			}
			if(judge(a[1],s[1],a[n],a[2])&&judge(a[n],s[n],a[n-1],a[1])){
				print();
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}