#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341919];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341919];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(a>b)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

const int inf=LLONG_MAX/3;

const int Nmax=364364;

struct SCC{
	vi belong;
	vector<vi> cmp,graph;
};
namespace StronglyConnectedComponents{
	int ord[Nmax],low[Nmax],ordI,cmpI,belong[Nmax],come[Nmax];
	stack<int> psh;
	bool inS[Nmax],used[Nmax];
	vi  cmp[Nmax];
	void dfs(int v,const vector<vi>& graph){
		ord[v]=low[v]=ordI++;
		inS[v]=true;
		psh.push(v);
		for(auto to:graph[v]){
			if(ord[to]==-1){
				dfs(to,graph);
				chmin(low[v],low[to]);
			}else if(inS[to])
				chmin(low[v],ord[to]);
		}
		if(low[v]==ord[v]){
			while(1){
				int t=psh.top();psh.pop();
				belong[t]=cmpI;
				cmp[cmpI].PB(t);
				inS[t]=false;
				if(t==v)
					break;
			}
			cmpI++;
		}
	}
	SCC BuildSCC(const vector<vi>& graph){
		int n=graph.size();
		memset(ord,-1,sizeof(ord));
		memset(low,-1,sizeof(low));
		memset(belong,0,sizeof(belong));
		memset(come,0,sizeof(come));
		memset(inS,0,sizeof(inS));
		memset(used,0,sizeof(used));
		ordI=0;
		cmpI=0;
		REP(i,Nmax)cmp[i].clear();
		psh=stack<int>();
		REP(i,n)if(ord[i]==-1)
			dfs(i,graph);
		vector<vi> retCmp,retGraph(cmpI);
		vi retBelong(n);
		REP(v,n)
			for(auto to:graph[v])
				if(belong[v]!=belong[to])
					come[belong[to]]++;
		queue<int> q;
		REP(i,cmpI)
			if(come[i]==0)
				q.push(i);
		while(!q.empty()){
			int i=q.front();q.pop();
			for(auto v:cmp[i])
				retBelong[v]=retCmp.size();
			retCmp.PB(cmp[i]);
			for(auto v:cmp[i])
				for(auto to:graph[v])
					if(i!=belong[to])
						if(--come[belong[to]]==0)
							q.push(belong[to]);
		}
		REP(i,cmpI){
			for(auto v:retCmp[i])
				for(auto to:graph[v])
					if(i!=retBelong[to]&&!used[retBelong[to]]){
							retGraph[i].PB(retBelong[to]);
							used[retBelong[to]]=true;
					}
			for(auto to:retGraph[i])
				used[to]=false;
		}
		return SCC{retBelong,retCmp,retGraph};
	}
}

struct Flag{
	int x,y;
};
struct Snuke{
	int v,i,t;
	bool operator<(const Snuke& rhs)const{
		if(v!=rhs.v)return v<rhs.v;
		else if(i!=rhs.i)return i<rhs.i;
		else return t<rhs.t;
	}
};

void SetEdge(vector<vi>& graph,int b,int e,int l,int r,int i,int from){
	if(e<=b)return;
	if(e<=l||r<=b)return;
	if(b<=l&&r<=e)return void(graph[from].PB(i));
	SetEdge(graph,b,e,l,(l+r)/2,i*2,from);
	SetEdge(graph,b,e,(l+r)/2,r,i*2+1,from);
}

bool Wafrelka(const int n,const vector<Flag>& fs,const vector<Snuke>& ss,const int d){
	int s=1;
	while(s<n*2)s*=2;
	vector<vi> graph(s*2);
	FOR(i,1,s){
		graph[i].PB(i*2);
		graph[i].PB(i*2+1);
	}
	REP(i,n){
		int xi=lower_bound(ALL(ss),Snuke{fs[i].x,i,1})-ss.begin();
		int yi=lower_bound(ALL(ss),Snuke{fs[i].y,i,2})-ss.begin();
		{
			int b=lower_bound(ALL(ss),Snuke{fs[i].x-d+1,-inf,0})-ss.begin();
			int e=lower_bound(ALL(ss),Snuke{fs[i].x+d-1,inf,0})-ss.begin();
			SetEdge(graph,b,xi,0,s,1,yi+s);
			SetEdge(graph,xi+1,e,0,s,1,yi+s);
		}
		{
			int b=lower_bound(ALL(ss),Snuke{fs[i].y-d+1,-inf,0})-ss.begin();
			int e=lower_bound(ALL(ss),Snuke{fs[i].y+d-1,inf,0})-ss.begin();
			SetEdge(graph,b,yi,0,s,1,xi+s);
			SetEdge(graph,yi+1,e,0,s,1,xi+s);
		}
	}
	SCC scc=StronglyConnectedComponents::BuildSCC(graph);
	REP(i,n){
		int xi=lower_bound(ALL(ss),Snuke{fs[i].x,i,1})-ss.begin();
		int yi=lower_bound(ALL(ss),Snuke{fs[i].y,i,2})-ss.begin();
		if(scc.belong[xi+s]==scc.belong[yi+s])
			return false;
	}
	return true;
}

signed main(){
	int n=read();
	vector<Flag> fs;
	vector<Snuke> ss;
	REP(i,n){
		int x=read(),y=read();
		fs.PB(Flag{x,y});
		ss.PB(Snuke{x,i,1});
		ss.PB(Snuke{y,i,2});
	}
	sort(ALL(ss));
	int l=0,r=1000000000;
	while(r-l>1){
		const int mid=(r+l)/2;
		if(Wafrelka(n,fs,ss,mid))
			l=mid;
		else
			r=mid;
	}
	print(l);
}
