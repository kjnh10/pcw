// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=998244353;

int n,x[222],y[222],pw[222],all[222];
int main()
{
	pw[0]=1;for(int i=1;i<222;i++)pw[i]=pw[i-1]*2%mod;
	get1(n);
	for(int i=1;i<=n;i++)get2(x[i],y[i]);
	int ans=(pw[n]+mod-1)%mod;
	ans=(ans+mod-n)%mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int cnt=0;
			for(int k=1;k<=n;k++)if((x[i]-x[j])*(y[i]-y[k])==(x[i]-x[k])*(y[i]-y[j]))cnt++;
			all[cnt]++;
		}
	}
	for(int i=2;i<=n;i++)
	{
		all[i]=all[i]*2/i/(i-1);
//		printf("i = %d %d\n",i,all[i]);
		ans=(ans+mod-1ll*all[i]*(pw[i]+mod-i-1))%mod;
	}
	printendl(ans);
	return 0;
}