#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",(long long)x)
#define pp(x,y)     printf("~~%lld %lld~~\n",(long long)x,(long long)y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",(long long)x,(long long)y,(long long)z)
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",(long long)a,(long long)b,(long long)c,(long long)d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define GuYue		puts("\nGuYueNa________________________________________________________________________________")
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
#if NEG
    inline ll read(){    ll x=0,fa=1; char ch=getchar();   for (;!isdigit(ch);ch=getchar()) if (ch=='-') fa=-1;  for (;isdigit(ch);ch=getchar())  x=x*10-48+ch;   return x*fa; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=getchar();   for (;!isdigit(ch);ch=getchar());    for (;isdigit(ch);ch=getchar())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
	void writeln(ll x){write(x);puts("");}
	void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);}
}using namespace SHENZHEBEI;
const ll N=300100;
ll x,y;
ll findth(ll x,ll y){return y>=x?y+1:y;}
bool check(ll sum){
	ll cogito=sum/2;
	For(i,cogito-100,cogito+100)if ((i>0&&i<=sum))
	if ((findth(x,i)*findth(y,sum-i+1)>=x*y))
	return 0;
	return 1;
}
int main(){
	ll Q=read();
	for(;Q--;){
		x=read(),y=read();
		ll l=0,r=2e9,ans=0;
		for(;l<=r;){
			ll mid=(l+r)>>1;
			if (check(mid))ans=mid,l=mid+1;
			else	r=mid-1;
		}writeln(ans);
	}
}
/*
x-y

*/