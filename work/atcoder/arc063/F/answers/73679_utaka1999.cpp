#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <cmath>
#define SIZE 500005
#define BT 1024*1024*2
#define INF 1000000000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

struct segtree
{
	int seg[BT],add[BT];
	int mum;
	
	inline void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=add[i]=0;
	}
	void pass(int k)
	{
		seg[k*2+1]+=add[k];
		seg[k*2+2]+=add[k];
		add[k*2+1]+=add[k];
		add[k*2+2]+=add[k];
		add[k]=0;
	}
	inline void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]+=v;
			add[k]+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=max(seg[k*2+1],seg[k*2+2])+add[k];
		}
	}
	inline void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	inline int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return -INF;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr)+add[k];
		}
	}
	inline int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
vector <int> vx,vy;
PP su[SIZE],sd[SIZE];
int ans;
int w,h,n;

void solve(vector <P> query,int L,int R)
{
	if(query.size()==0) return;
	if(query.size()==1)
	{
		P p=query[0];
		ans=max(ans,max(p.second-L,R-p.second)+w);
		ans=max(ans,max(vx[p.first],w-vx[p.first])+R-L);
		return;
	}
	vector <int> B;
	for(int i=0;i<query.size();i++)
	{
		P p=query[i];
		B.push_back(p.second);
	}
	sort(B.begin(),B.end());
	int m=B[B.size()/2];
	m=(L+R)/2;
	vector <P> up,down;
	seg.init(query.size()+5);
	seg.update(0,1,R-L);
	int u=0,d=0;
	su[u++]=PP(R,P(0,0));
	sd[d++]=PP(L,P(0,0));
	for(int i=0;i<query.size();i++)
	{
		P p=query[i];
		ans=max(ans,seg.get(0,i+1)+vx[p.first]);
		seg.update(i+1,i+2,-vx[p.first]);
		int low,high;
		if(p.second>=m)
		{
			low=L,high=p.second;
			up.push_back(p);
		}
		else
		{
			low=p.second,high=R;
			down.push_back(p);
		}
		int last=i+1;
		while(u>0&&su[u-1].first>=high)
		{
			PP q=su[u-1];u--;
			seg.update(q.second.first,q.second.second+1,-q.first);
			last=q.second.first;
		}
		if(last<i+1)
		{
			seg.update(last,i+1,high);
			su[u++]=PP(high,P(last,i));
		}
		seg.update(i+1,i+2,R);
		su[u++]=PP(R,P(i+1,i+1));
		
		last=i+1;
		while(d>0&&sd[d-1].first<=low)
		{
			PP q=sd[d-1];d--;
			seg.update(q.second.first,q.second.second+1,q.first);
			last=q.second.first;
		}
		if(last<i+1)
		{
			seg.update(last,i+1,-low);
			sd[d++]=PP(low,P(last,i));
		}
		seg.update(i+1,i+2,-L);
		sd[d++]=PP(L,P(i+1,i+1));
	}
	ans=max(ans,seg.get(0,query.size()+1)+w);
	return;
	solve(down,L,m);
	solve(up,m,R);
}
int main()
{
	scanf("%d %d %d",&w,&h,&n);
	vector <P> query;
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		query.push_back(P(a,b));
		vx.push_back(a);
	}
	sort(vx.begin(),vx.end());
	for(int i=0;i<n;i++)
	{
		P p=query[i];
		p.first=lower_bound(vx.begin(),vx.end(),p.first)-vx.begin();
		query[i]=p;
	}
	sort(query.begin(),query.end());
	solve(query,0,h);
	swap(w,h);
	for(int i=0;i<n;i++)
	{
		P p=query[i];p.first=vx[p.first];
		swap(p.first,p.second);
		query[i]=p;
	}
	vx.clear();
	for(int i=0;i<n;i++)
	{
		P p=query[i];
		vx.push_back(p.first);
	}
	sort(vx.begin(),vx.end());
	for(int i=0;i<n;i++)
	{
		P p=query[i];
		p.first=lower_bound(vx.begin(),vx.end(),p.first)-vx.begin();
		query[i]=p;
	}
	sort(query.begin(),query.end());
	solve(query,0,h);
	printf("%d\n",ans*2);
	return 0;
}
