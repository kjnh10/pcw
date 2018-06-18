#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define outy printf("Yes\n")
#define outn printf("No\n")
#define outf printf("First\n")
#define outs printf("Second\n")
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)
#define FORL(a,b) for(int a=head[b];a;a=nxt[a])
#define in(a)  a=read()
#define in2(a,b)  a=read(),b=read()
#define in3(a,b,c)  a=read(),b=read(),c=read()
#define in4(a,b,c,d)  a=read(),b=read(),c=read(),d=read()
#define inl(a)  a=readl()
#define inl2(a,b)  a=readl(),b=readl()
#define inl3(a,b,c)  a=readl(),b=readl(),c=readl()
#define inl4(a,b,c,d)  a=readl(),b=readl(),c=readl(),d=readl()
#define out(a) printf("%d\n",a)
#define out2(a,b) printf("%d %d\n",a,b)
#define out3(a,b,c) printf("%d %d %d\n",a,b,c)
#define out4(a,b,c,d) printf("%d %d %d %d\n",a,b,c,d)
#define outl(a) printf("%lld\n",a)
#define outl2(a,b) printf("%lld %lld\n",a,b)
#define outl3(a,b,c) printf("%lld %lld %lld\n",a,b,c)
#define outl4(a,b,c,d) printf("%lld %lld %lld %lld\n",a,b,c,d)
#define clr(x,y) memset(x,y,sizeof(x))
inline int read(){
    char c;int s=0,t=1;
    while(!isdigit(c=getchar()))if(c=='-')t=-1;
    do{s=s*10+c-'0';}while(isdigit(c=getchar()));
    return s*t;
}
inline ll readl(){
    char c;ll s=0;int t=1;
    while(!isdigit(c=getchar()))if(c=='-')t=-1;
    do{s=s*10+c-'0';}while(isdigit(c=getchar()));
    return s*t;
}
/*------------------------------------------------------------*/
#define mod 1000000000
#define maxn 110
#define inf 0x7fffffff
/*------------------------------------------------------------*/
int n,m;
int a,b;
bool check(int x){
	int ans=0;
	while(x){
		ans+=x%10;
		x/=10;
	}
	return ans>=a&&ans<=b;
}
int main(){
	in(n);
	in2(a,b);
	int ans=0;
	FOR(i,1,n){
		if(check(i))ans+=i;
	}
	out(ans);
}