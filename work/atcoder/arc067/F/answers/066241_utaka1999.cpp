#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <cassert>
#define SIZE 5005
#define BT 64*128*2
#define MX 205

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree
{
	ll seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=0;
	}
	void add(int k,ll x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0LL;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg[MX];
ll S[SIZE];
ll ans[SIZE];
ll B[SIZE][MX];
ll mx[MX];
int n,m;

void solve(int l,int r,int L,int R)//[l,r]のoptは[L,R]
{
	if(l>r) return;
	int t=(l+r)/2;
	int start=max(L,t);
	for(int i=0;i<m;i++) mx[i]=seg[i].get(t,start+1);
	ll sum=0;
	for(int i=0;i<m;i++) sum+=mx[i];
	int pos=start;
	ll now=sum-S[start];
	for(int i=start;i<=R;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mx[j]<B[i][j])
			{
				sum+=B[i][j]-mx[j];
				mx[j]=B[i][j];
			}
		}
		if(now<=sum-S[i])
		{
			now=sum-S[i];
			pos=i;
		}
	}
	//printf("%d %d : %lld\n",t,pos,now);
	ans[t]=now+S[t];
	solve(l,t-1,L,pos);
	solve(t+1,r,pos,R);
}
int main()
{
	scanf("%d %d",&n,&m);
	S[0]=0;
	for(int i=1;i<n;i++)
	{
		scanf("%lld",&S[i]);
		S[i]+=S[i-1];
	}
	for(int i=0;i<m;i++) seg[i].init(n+2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%lld",&B[i][j]);
			seg[j].add(i,B[i][j]);
		}
	}
	solve(0,n-1,0,n-1);
	ll ret=0;
	for(int i=0;i<n;i++) ret=max(ret,ans[i]);
	printf("%lld\n",ret);
	return 0;
}
