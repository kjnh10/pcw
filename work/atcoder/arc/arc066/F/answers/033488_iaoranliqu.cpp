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

#define ls (t<<1)
#define rs ((t<<1)+1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 300005
#define M 200005
#define seed 23333

using namespace std;
struct Ques{
	 int pos,sum;
}A[N];
int i,j,m,n,p,k,Q[N],r=0,r1=0,a[N],id[N],l,ID[N];
long long f[N],g[N],Ans[N],sum[N],S[N],Max[N];
void ins(int x)
{
	 while (r>1&&(S[x]-S[Q[r]])*(Q[r]-Q[r-1])>=(S[Q[r]]-S[Q[r-1]])*(x-Q[r])) --r;
	 r1=min(r1,r);
	 if (r1==0) r1=1;
	 Q[++r]=x;
	 if (r1==r-1&&(S[Q[r]]-S[Q[r-1]])>=i*(Q[r]-Q[r-1])) ++r1;
	 while (r1>1&&(S[Q[r1]]-S[Q[r1-1]])<i*(Q[r1]-Q[r1-1])) --r1;
}
void Ins(int x)
{
	 S[x]=1ll*x*(x-1)/2+f[x]+sum[x];
	 while (r>1&&(S[x]-S[Q[r]])*(Q[r]-Q[r-1])>=(S[Q[r]]-S[Q[r-1]])*(x-Q[r])) --r;
	 Q[++r]=x;
}
void insert(int x)
{
	 S[x]=g[x]+1ll*x*(x+1)/2-sum[x-1];
	 while (r>1&&(S[x]-S[Q[r]])*(Q[r]-Q[r-1])>=(S[Q[r]]-S[Q[r-1]])*(x-Q[r])) --r;
	 Q[++r]=x;
}
void work(long long *f)
{
	  for (i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	  r=0,r1=1;
	  for (i=1;i<=n;++i)
	  {
	  		S[i-1]=f[i-1]+1ll*(i-1-1)*(i-1)/2+sum[i-1];
	  		ins(i-1);
	  		int id=Q[r1];
	  		f[i]=f[id]+1ll*(i-id)*(i-id+1)/2-sum[i]+sum[id];
	  		f[i]=max(f[i],f[i-1]);
	  }
}
void Fen(int sl,int sr,int ql,int qr)
{
		if (ql>qr||sl==sr) return;
		int mid=(sl+sr)>>1,i;
		r=0;
		for (i=sl-1;i<=mid;++i) Ins(i);
		r1=r;
		for (i=mid+1;i<=sr;++i) 
		{
				while (r1>1&&(S[Q[r1]]-S[Q[r1-1]])<i*(Q[r1]-Q[r1-1])) --r1;
				int id=Q[r1];
				Max[i]=f[id]+1ll*(i-id)*(i-id+1)/2-sum[i]+sum[id]+g[i+1];
		}
		for (i=sr-1;i>mid;--i) Max[i]=max(Max[i],Max[i+1]);
		l=1,r=0;
		for (i=mid+1;i<=sr+1;++i) insert(i);
		for (i=sl;i<=mid;++i)
		{
				while (l<r&&(S[Q[l+1]]-S[Q[l]])>=i*(Q[l+1]-Q[l])) ++l;
				int id=Q[l];
				Max[i]=g[id]+1ll*(id-i)*(id-i+1)/2-sum[id-1]+sum[i-1]+f[i-1];
		}
		for (i=sl+1;i<=mid;++i) Max[i]=max(Max[i],Max[i-1]);
		for (i=ql;i<=qr;++i) 
		Ans[id[i]]=max(Ans[id[i]],Max[A[id[i]].pos]+a[A[id[i]].pos]-A[id[i]].sum);
		int nowr=ql-1,nowl=qr+1;
		for (i=ql;i<=qr;++i)
			if (A[id[i]].pos<=mid) ID[++nowr]=id[i];
			else ID[--nowl]=id[i];
		for (i=ql;i<=qr;++i)
			id[i]=ID[i];
		Fen(sl,mid,ql,nowr);
		Fen(mid+1,sr,nowl,qr);
}
int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i)	scanf("%d",&a[i]);
		work(f);
		for (i=1;i<=n;++i) if (i<n-i+1) swap(a[i],a[n-i+1]);
		work(g);
		for (i=1;i<=n;++i) if (i<n-i+1) swap(g[i],g[n-i+1]),
										swap(a[i],a[n-i+1]);
		for (i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
		scanf("%d",&m);
		for (i=1;i<=m;++i) 
			scanf("%d%d",&A[i].pos,&A[i].sum),id[i]=i,
			Ans[i]=f[A[i].pos-1]+g[A[i].pos+1]; 
		Fen(1,n,1,m);
		for (i=1;i<=m;++i) cout<<Ans[i]<<endl;
}