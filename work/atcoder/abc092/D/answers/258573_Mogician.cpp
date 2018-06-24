//# pragma GCC optimize ("O2")
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<climits>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>
#define out(i,a,now) for(int i=a.be[now],to=a.v[i];i;i=a.ne[i],to=a.v[i])
#define fo(i,a,b) for(i=a;i<=b;i++)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define mp(a,b) make_pair(a,b)
#define qk(x) memset(x,0,sizeof(x))
#define RG register
#define gs(x) (tr[tr[x].f].son[1]==x)
#define lb(x) (x&(-x))
#define mid ((l+r)>>1)
#ifdef Mogician
#endif
using namespace std;
typedef long long LL;
typedef double DB;
template <class T> void cmax(T &a,T b)
{
    a=max(a,b);
}
template <class T> void cmin(T &a,T b)
{
    a=min(a,b);
}
template <class T> void swp(T &a,T &b)
{
	T temp=a; a=b; b=temp;
}
LL a,b;
int main()
{
#ifdef Mogician
	freopen("D.out","w",stdout);
#endif
	scanf("%lld%lld",&a,&b);
	a--;b--;
	LL i,j;
	printf("99 99\n");
	fo(i,1,48)
	{
		if (i%3==0 || i%3==1)
		{
			fo(j,1,99) printf("#");
		}
		else
		{
			fo(j,1,99)
			if (j%2==0 && a)
			{
				printf(".");
				a--;
			}
			else printf("#");
		}
		printf("\n");
	}
	fo(i,1,51)
	{
		if (i%3==0 || i%3==1)
		{
			fo(j,1,99) printf(".");
		}
		else
		{
			fo(j,1,99)
			if (j%2==0 && b)
			{
				printf("#");
				b--;
			}
			else printf(".");
		}
		printf("\n");
	}
}