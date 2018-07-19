#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 100005
#define M 2000005
#define seed 23333

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;
int i,j,m,n,p,x[N],y[N],tot,id[N],ID[N],id_x[N],id_y[N];
vector<pair<int,int> >bian;
inline int cmp(int a,int b)
{
		return x[a]<x[b];
}
inline int cmp2(int a,int b)
{
		return  y[a]<y[b];
}
int index1[N],index11[N],k1=0,k=0;
struct Node{
	int num,before;
}s[M],s1[M];
bool vis[N];
int numk[N];
int ssc[N],kk;
void add(int p1,int p2)
 { s[++k].num=p2; 
 s[k].before=index1[p1]; 
 index1[p1]=k;}
void add1(int p1,int p2)
  { s1[++k1].num=p2;
   s1[k1].before=index11[p1]; 
   index11[p1]=k1;}
void dfs(int num)
 { int i;
    vis[num]=true;
   for (i=index1[num];i;i=s[i].before)
      if (!vis[s[i].num]) dfs(s[i].num);
   ssc[++p]=num;
}
void ndfs(int num)
  { int i;
     numk[num]=kk;
      vis[num]=true;
       for (i=index11[num];i;i=s1[i].before)
         if (!vis[s1[i].num]) ndfs(s1[i].num);
} 
void doit()
{  
	int i,j,k;
    p=0;
    memset(vis,false,sizeof(vis));
     for (i=1;i<=tot;i++)
       if (!vis[i]) dfs(i);
         memset(vis,false,sizeof(vis));
    kk=0;
     for (i=tot;i>=1;i--)
       if (!vis[ssc[i]])
          { kk++;
            ndfs(ssc[i]);
            }
}
struct Tre{
		int ls[N],rs[N],idt,root;
		void build_tree(int l,int r,int t)
		{
				if (l==r) 
				{
					if (idt)
					bian.pb(mk(t,ID[l]));
				    else bian.pb(mk(t,id[l]+n));
				}
				else 
				{
					ls[t]=++tot;
					bian.pb(mk(t,tot));
					build_tree(l,mid,ls[t]);
					rs[t]=++tot;
					bian.pb(mk(t,tot));
					build_tree(mid+1,r,rs[t]);
				}
		}
		void link(int x,int ll,int rr,int l,int r,int t)
		{
					if (ll>rr) return;
					if (ll<=0||rr>n) return;
					if (ll<=l&&r<=rr) add(x,t),add1(t,x);
					else 
					{
							if (ll<=mid) link(x,ll,rr,l,mid,ls[t]);
							if (rr>mid)  link(x,ll,rr,mid+1,r,rs[t]);
					}
		}
}tree[2];
int upd_x(int xx)
{
		int l=1,r=n+1,Mid=0;
		while ((l+r)>>1!=Mid)
		{
				Mid=(l+r)>>1;
				if (x[id[Mid]]>=xx) r=Mid;
				else l=Mid;
		}
		return r;
}
int down_x(int xx)
{
		int l=0,r=n+1,Mid=0;
		while ((l+r)>>1!=Mid)
		{
				Mid=(l+r)>>1;
				if (x[id[Mid]]<=xx) l=Mid;
				else r=Mid;
		}
		return l;
}
int upd_y(int x)
{
		int l=1,r=n+1,Mid=0;
		while ((l+r)>>1!=Mid)
		{
				Mid=(l+r)>>1;
				if (y[ID[Mid]]>=x) r=Mid;
				else l=Mid;
		}
		return r;
}
int down_y(int x)
{
		int l=0,r=n+1,Mid=0;
		while ((l+r)>>1!=Mid)
		{
				Mid=(l+r)>>1;
				if (y[ID[Mid]]<=x) l=Mid;
				else r=Mid;
		}
		return l;
}
int check(int d)
{
		int i;
		memset(index1,0,sizeof(index1));
		memset(index11,0,sizeof(index11));
		k1=k=0;
		for (i=0;i<(int)bian.size();++i)
		{
					add(bian[i].fi,bian[i].se);
					add1(bian[i].se,bian[i].fi);
		}
		for (i=1;i<=n;++i)
		{
			{
				int l=upd_x(x[i]-d+1),r=down_x(x[i]+d-1);
				if (l<=id_x[i]&&id_x[i]<=r)
				tree[0].link(i,l,id_x[i]-1,1,n,tree[0].root),
				tree[0].link(i,id_x[i]+1,r,1,n,tree[0].root);
				else 
				tree[0].link(i,l,r,1,n,tree[0].root);
				l=upd_y(x[i]-d+1),r=down_y(x[i]+d-1);
				if (l<=id_y[i]&&id_y[i]<=r)
				tree[1].link(i,l,id_y[i]-1,1,n,tree[1].root),
				tree[1].link(i,id_y[i]+1,r,1,n,tree[1].root);
				else 
				tree[1].link(i,l,r,1,n,tree[1].root);
			}//work x_i
			{
				int l=upd_x(y[i]-d+1),r=down_x(y[i]+d-1);
				if (l<=id_x[i]&&id_x[i]<=r)
				tree[0].link(i+n,l,id_x[i]-1,1,n,tree[0].root),
				tree[0].link(i+n,id_x[i]+1,r,1,n,tree[0].root);
				else 
				tree[0].link(i+n,l,r,1,n,tree[0].root);
				l=upd_y(y[i]-d+1),r=down_y(y[i]+d-1);
				if (l<=id_y[i]&&id_y[i]<=r)
				tree[1].link(i+n,l,id_y[i]-1,1,n,tree[1].root),
				tree[1].link(i+n,id_y[i]+1,r,1,n,tree[1].root);
				else 
				tree[1].link(i+n,l,r,1,n,tree[1].root);		
			}//work y_i
		}
		doit();
		for (i=1;i<=n;++i) if (numk[i]==numk[i+n]) return 0;
		return 1;
}
int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]),id[i]=i,ID[i]=i; tot=n*2; 
		sort(id+1,id+n+1,cmp);
		sort(ID+1,ID+n+1,cmp2);
		for (i=1;i<=n;++i) id_x[id[i]]=i,id_y[ID[i]]=i;
		tree[1].idt=1;
		tree[0].build_tree(1,n,tree[0].root=++tot);
		tree[1].build_tree(1,n,tree[1].root=++tot); 
		int l=0,r=(int)1e9+5,Mid=0;
		while ((l+r)>>1!=Mid)
		{
				Mid=(l+r)>>1;
				if (check(Mid)) l=Mid;
				else r=Mid;
		}
		printf("%d\n",l); 
}