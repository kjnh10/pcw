//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
ll bs[20];
ll D,calc0[20],calc[20];
ll a[20],an,ans;
void dfs(int x,ll v,ll c)
{
	if(x==an)
	{
		ans+=(v==D)*c;
		return;
	}
	if(abs(v-D)>a[x]*20)return;
	for(int i=0;i<20;i++)
	{
		int cnt;
		if(x==0)cnt=calc0[i];else cnt=calc[i];
		if(a[x]==0)cnt=i<10;
		if(cnt==0)continue;
		dfs(x+1,v+(i-10)*a[x],c*cnt);
	}
}
void solve(int n)
{
	an=0;
	for(int i=0;i<n;i++)
	{
		if(i>n-i-1)break;
		a[an++]=bs[n-i-1]-bs[i];
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
	dfs(0,0,1);
//	cout<<ans<<endl;
}
int main()
{
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			calc[i-j+10]++;
		}
	}
	for(int i=0;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			calc0[i-j+10]++;
		}
	}
	
	bs[0]=1;
	for(int i=1;i<19;i++)bs[i]=bs[i-1]*10;
	cin>>D;
	for(int i=1;i<=19;i++)
	{
		solve(i);
	}
	cout<<ans<<endl;
	return 0;
}