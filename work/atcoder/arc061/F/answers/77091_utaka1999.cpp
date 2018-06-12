#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll inv[SIZE],fac[SIZE],finv[SIZE];
ll rt[SIZE];
void make()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
	rt[0]=1;
	for(int i=1;i<SIZE;i++) rt[i]=rt[i-1]*3LL%MOD;
}
ll C(int a,int b)
{
	if(b==0) return 1;
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
int main()
{
	make();
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	n++,m++,k++;
	ll ret=0;
	ll l=0,r=0;
	for(int L=0;L<=m+k-2;L++)
	{
		ll now=C(L+n-2,n-2)*rt[m+k-L-2]%MOD;
		if(L-k>0)
		{
			l*=2LL;
			l%=MOD;
			l+=C(L-1,k-1);
			if(l>=MOD) l-=MOD;
		}
		else if(L-k==0) l=1;
		if(L==0) r=1;
		else
		{
			r*=2LL;
			r%=MOD;
			if(L>m-1)
			{
				r-=C(L-1,m-1);
				if(r<0) r+=MOD;
			}
		}
		//printf("%d [%d %d] : %lld %lld\n",L,max(0,L-k+1),min(L,m-1),l,r);
		ret+=now*(r-l+MOD)%MOD;
		ret%=MOD;
	}
	printf("%lld\n",ret);
	return 0;
}
