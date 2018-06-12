#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <stack>
#include <cmath>
#include <string>
#define SIZE 300005
#define LINF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct L
{
	ll a,b;//ax+b
	L(ll a=0,ll b=0):a(a),b(b){}
	ll get(ll x)
	{
		return a*x+b;
	}
};
bool down(L p,L q,L r)//0>p.a>q.a>r.a
{
	return (p.b-q.b)*(r.a-p.a)<(p.b-r.b)*(q.a-p.a);
}
struct getmx
{
	L que[SIZE];
	int sz;
	
	void init()
	{
		sz=0;
	}
	void push(L l)//l.a : 減少
	{
		while(sz>=2&&down(que[sz-2],que[sz-1],l)) sz--;
		que[sz++]=l;
	}
	ll get(ll x)//x : 増加
	{
		while(sz>=2&&que[sz-1].get(x)<=que[sz-2].get(x)) sz--;
		//printf("%d : %lld %lld\n",sz,que[sz-1].a,que[sz-1].b);
		return que[sz-1].get(x);
	}
};
getmx que;
int n;
ll T[SIZE],S[SIZE];
ll left[SIZE],right[SIZE];
ll dp[SIZE];
ll memo[SIZE];

void solve(int l,int r)
{
	if(l+1==r) return;
	int m=(l+r)/2;
	que.init();
	if(l==0) que.push(L(1,1));
	else que.push(L(-(l-1),left[l-1]+(ll) (l-1)*(ll) (l-2)/2+S[l-1]));
	for(int i=l;i<m;i++) que.push(L(-i,left[i]+(ll) i*(ll) (i-1)/2+S[i]));
	for(int i=m;i<r;i++) memo[i]=que.get(i)+(ll) i*(ll) (i+1)/2-S[i]+right[i];
	que.init();
	for(int i=r-1;i>=m;i--) que.push(L(i,right[i]+(ll) i*(ll) (i+1)/2-S[i]));
	for(int i=m-1;i>=l;i--) memo[i]=que.get(-(i-1))+(ll) (i-1)*(ll) (i-2)/2+(i==0?0:S[i-1]+left[i-1]);
	ll mx=-LINF;
	for(int i=r-1;i>=m;i--)
	{
		mx=max(mx,memo[i]);
		dp[i]=max(dp[i],mx);
	}
	mx=-LINF;
	for(int i=l;i<m;i++)
	{
		mx=max(mx,memo[i]);
		dp[i]=max(dp[i],mx);
	}
	solve(l,m);
	solve(m,r);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&T[i]);
		S[i]=T[i];
		if(i>0) S[i]+=S[i-1];
	}
	que.init();
	que.push(L(1,1));
	for(int i=0;i<n;i++)
	{
		left[i]=que.get(i)+(ll) i*(ll) (i+1)/2-S[i];
		left[i]=max(left[i],0LL);
		if(i>0) left[i]=max(left[i],left[i-1]);
		que.push(L(-i,left[i]+(ll) i*(ll) (i-1)/2+S[i]));
	}
	que.init();
	for(int i=n-1;i>=0;i--)
	{
		if(i==n-1) right[i]=0;
		else
		{
			right[i]=que.get(-i)+(ll) i*(ll) (i-1)/2+S[i];
			right[i]=max(right[i],right[i+1]);
		}
		que.push(L(i,right[i]+(ll) i*(ll) (i+1)/2-S[i]));
	}
	//for(int i=0;i<n;i++) dp[i]=max(0LL,(ll) n*(ll) (n+1)/2LL-S[n-1]);
	for(int i=0;i<n;i++) dp[i]=1LL-T[i];
	solve(0,n);
	//for(int i=0;i<n;i++) printf("%lld %lld : %lld\n",left[i],right[i],dp[i]);
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int p,x;
		scanf("%d %d",&p,&x);p--;
		printf("%lld\n",max(dp[p]-x+T[p],right[p]+(p==0?0:left[p-1])));
	}
	return 0;
}
