#include<cstdio>
#include<cstring>
using namespace std;

int ss; char chr;
inline int read(){
	ss=0; chr=getchar();
	while(chr<'0'||chr>'9') chr=getchar();
	while('0'<=chr&&chr<='9') ss=ss*10+chr-'0',chr=getchar();
	return ss;
}

const int N=1e5+7;
int n,m,pren[N],num,hhh;
int tot=-1,last[N],pre[2*N],to[2*N];
int idx,dfn[N],low[N],vis_p[N];
bool vis_e[N],bridge[N];

inline void add(int xx,int yy){
	++tot;
	pre[tot]=last[xx];
	to[tot]=yy;
	last[xx]=tot;
}

void tarjan(int u){


	vis_p[u]=1;
	dfn[u]=low[u]=++idx;
	for(int c=last[u],v;c!=-1;c=pre[c])
		if(!vis_e[c])
		{
			vis_e[c]=vis_e[c^1]=true;
			v=to[c];
			if(!vis_p[v])
			{
				pren[v]=u;
				tarjan(v);
				if(low[v]<low[u]) low[u]=low[v];
				if(dfn[u]<low[v])
				{
					++num;
					bridge[v]=true;
				}
			}
			else
				if(vis_p[v]==1&&dfn[v]<low[u])
					low[u]=dfn[v];
		}
	vis_p[u]=2;
}

int main(){
	n=read(); m=read();
	memset(last,-1,sizeof(last));
	int i,u,v;
	for(i=1;i<=m;++i)
	{
		u=read(); v=read();
		add(u,v); add(v,u);
	}
	pren[1]=1;
	tarjan(1);
	for(i=1;i<=n;++i)
		if(bridge[i])
			hhh++;
			printf("%d",hhh);
}
