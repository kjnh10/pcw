#include <cstdio>
#include <algorithm>
#include <cmath>
#define Rint register int
#define LL long long
#define F(x,y,z) for(Rint x=y;x<=z;++x)
using namespace std;
inline LL R(){
    char c='!';LL x=0,z=1;
    for( ; c>'9'||c<'0';c=getchar()) if(c=='-')z=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    return x*z;
}
int n,m;
LL anss;
int a[1000010];

int main(){
	n=R();
	F(i,1,n) a[i]=R();
	int la=0,too=0,lanow=0;
	F(i,1,n){
		int now=lanow-a[i-1];
		anss+=la-i+1;
		F(j,la+1,n){
			
			if ((now^a[j])==(now+a[j])) ++anss,now^=a[j];
			else break;
			too=j;
		}
		la=too;lanow=now;
	}
	printf("%lld\n",anss);
	return 0;
}

