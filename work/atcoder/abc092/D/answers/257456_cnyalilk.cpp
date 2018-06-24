/*
Author: CNYALI_LK
LANG: C++
PROG: abc.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int> pii;
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
int read(){
	int s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
char WriteIntBuffer[1024];
template<class T>void write(T a,char end){
	int cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WriteIntBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WriteIntBuffer[cnt]);--cnt;}
	putchar(end);
}
int gra[128][128];
int main(){
#ifdef cnyali_lk
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
#endif
	int a,b;
	a=read();b=read();
	if(!a){
		printf("1 1\n#\n");
		return 0;
	}	
	if(!b){
		printf("1 1\n.\n");
		return 0;
	}
	printf("100 100\n");
	for(int i=1;i<=100;++i){
		for(int j=1;j<=100;++j)if(i<=50)gra[i][j]=0;else gra[i][j]=1;
	}

	--a;--b;
	for(int i=1;i<=50&&b;i+=2)for(int j=1;j<=100&&b;j+=2)gra[i][j]=1,--b;
	for(int i=1;i<=50&&a;i+=2)for(int j=1;j<=100&&a;j+=2)gra[101-i][j]=0,--a;
	for(int i=1;i<=100;++i,putchar('\n'))for(int j=1;j<=100;++j)printf("%c",gra[i][j]?'#':'.');

	return 0;
}

