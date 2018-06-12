#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP priority_queue
#define heap(T) priority_queue<T,vector<T>,greater<T> > 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=200005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
const int BufferSize=1<<25;
char buffer[BufferSize],*Bufferhead,*Buffertail;
int Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T> inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){c=Getchar();rev|=c=='-';if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	x=rev?-x:x;
	return 1;
}
template<class T>inline void print(T x,const char c){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[10];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,dep[N],fa[N],a[N],p[N];
vi g[N];
bool vis[N],on[N];

inline void add(int x,int y){g[x].pb(y);g[y].pb(x);}
inline void pre_dfs(int x){
	vis[x]=1;
	for(int y:g[x]){
		if(!vis[y]){
			fa[y]=x;dep[y]=dep[x]+1;
			pre_dfs(y);
			continue;
		}
		if(dep[y]>dep[x]){
			while(y!=x) on[y]=1,y=fa[y];
			on[x]=1;
		}
	}
}
inline int dfs(int x){
	vi tmp;tmp.clear();
	for(int y:g[x])
		if(!on[y]) tmp.pb(dfs(y));
	for(int i:tmp) vis[i]=1;
	int k=0;
	while(vis[k]) k++;
	for(int i:tmp) vis[i]=0;
	return k;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		add(p[i],i);
	}
	pre_dfs(1);clr(vis,0);
	for(int i=1;i<=n;i++)
		g[i].clear();
	for(int i=1;i<=n;i++) g[p[i]].pb(i);
	int cnt=0,tag=0;
	for(int i=1;i<=n;i++)
		if(on[i]) cnt++;
	if(cnt%2==0){puts("POSSIBLE");return 0;}
	for(int i=1;i<=n;i++)
		if(on[i]) a[i]=dfs(i),tag=a[i];
	for(int i=1;i<=n;i++)
		if(on[i]&&a[i]!=tag){puts("POSSIBLE");return 0;}
	puts("IMPOSSIBLE");
	return 0;
}