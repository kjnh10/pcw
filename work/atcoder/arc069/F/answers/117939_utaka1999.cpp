#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 20005
#define BT 1024*32*2
#define MX 1000005
#define INF 1000000005

using namespace std;

int sz;
vector <int> vec[MX];
vector <int> rvec[MX];
struct segtree
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			vec[sz].clear();
			seg[i]=sz++;
		}
		for(int i=0;i<mum-1;i++)
		{
			vec[seg[i]].push_back(seg[i*2+1]);
			vec[seg[i]].push_back(seg[i*2+2]);
		}
	}
	void add(int k,int x)
	{
		k+=mum-1;
		nw(k);
		vec[seg[k]].push_back(x);
	}
	void nw(int k)
	{
		vec[sz].clear();
		vec[sz].push_back(seg[k]);
		seg[k]=sz++;
		if(k>0)
		{
			nw((k-1)/2);
			vec[seg[(k-1)/2]].push_back(seg[k]);
		}
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) vec[v].push_back(seg[k]);
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
};
segtree seg;
int X[SIZE],Y[SIZE];
vector <int> vx;
vector <int> vs;
bool use[MX];
int cmb[MX];
int n;

void dfs(int v)
{
	use[v]=true;
	for(int i=0;i<vec[v].size();i++) if(!use[vec[v][i]]) dfs(vec[v][i]);
	vs.push_back(v);
}
void rdfs(int v,int k)
{
	cmb[v]=k;
	use[v]=true;
	for(int i=0;i<rvec[v].size();i++) if(!use[rvec[v][i]]) rdfs(rvec[v][i],k);
}
void scc()
{
	vs.clear();
	memset(use,false,sizeof(use));
	for(int i=0;i<sz;i++) if(!use[i]) dfs(i);
	memset(use,false,sizeof(use));
	int k=0;
	for(int i=sz-1;i>=0;i--) if(!use[vs[i]]) rdfs(vs[i],k++);
}
bool solve(int d)
{
	for(int i=0;i<2*n;i++) vec[i].clear();
	sz=2*n;
	seg.init(vx.size()+2);
	for(int i=0;i<n;i++)
	{
		//i*2 : Xを使うとき
		//i*2+1 : Yを使うとき
		int L=lower_bound(vx.begin(),vx.end(),vx[X[i]]-d+1)-vx.begin(),R=upper_bound(vx.begin(),vx.end(),vx[X[i]]+d-1)-vx.begin()-1;
		if(L<=R) seg.update(L,R+1,i*2);
		L=lower_bound(vx.begin(),vx.end(),vx[Y[i]]-d+1)-vx.begin(),R=upper_bound(vx.begin(),vx.end(),vx[Y[i]]+d-1)-vx.begin()-1;
		if(L<=R) seg.update(L,R+1,i*2+1);
		seg.add(X[i],i*2+1);
		seg.add(Y[i],i*2);
	}
	seg.init(vx.size()+2);
	for(int i=n-1;i>=0;i--)
	{
		int L=lower_bound(vx.begin(),vx.end(),vx[X[i]]-d+1)-vx.begin(),R=upper_bound(vx.begin(),vx.end(),vx[X[i]]+d-1)-vx.begin()-1;
		if(L<=R) seg.update(L,R+1,i*2);
		L=lower_bound(vx.begin(),vx.end(),vx[Y[i]]-d+1)-vx.begin(),R=upper_bound(vx.begin(),vx.end(),vx[Y[i]]+d-1)-vx.begin()-1;
		if(L<=R) seg.update(L,R+1,i*2+1);
		seg.add(X[i],i*2+1);
		seg.add(Y[i],i*2);
	}
	for(int i=0;i<sz;i++) rvec[i].clear();
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			int to=vec[i][j];
			rvec[to].push_back(i);
		}
	}
	scc();
	//for(int i=0;i<n;i++) printf("%d %d\n",cmb[i*2],cmb[i*2+1]);
	for(int i=0;i<n;i++)
	{
		if(cmb[i*2]==cmb[i*2+1]) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&X[i],&Y[i]);
		vx.push_back(X[i]);
		vx.push_back(Y[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++)
	{
		X[i]=lower_bound(vx.begin(),vx.end(),X[i])-vx.begin();
		Y[i]=lower_bound(vx.begin(),vx.end(),Y[i])-vx.begin();
	}
	//if(solve(2)) puts("YES");
	//return 0;
	int l=-1,r=INF/(n-1)+1;
	while(r-l>1)
	{
		int m=(l+r)/2;
		if(solve(m)) l=m;
		else r=m;
		//printf("%d %d\n",l,r);
	}
	printf("%d\n",l);
	return 0;
}
