#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

using uint=unsigned int;
using ll=long long;
using pii=pair<int,int>;
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
	scanf("%d",&i);
	return i;
}

ll readLL(){
	ll i;
	scanf("%lld",&i);
	return i;
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

const int Nmax=114514;
int w[Nmax];
vi tree[Nmax];

struct Res{
	bool imp,any;
	int s,t;
} z[Nmax];
Res dfs(int v,int p){
	Res r=Res{false,true,-1,-1};
	if(w[v]!=-1){
		r.any=false;
		r.s=r.t=w[v];
	}
	for(auto c:tree[v])if(c!=p){
		Res g=dfs(c,v);
		if(g.imp)
			return Res{true};
		if(!g.any){
			g.s--;
			g.t++;
			if(r.any){
				r.any=false;
				r.s=g.s;
				r.t=g.t;
			}else{
				if((r.s&1)!=(g.s&1))
					return Res{true};
				if((r.t&1)!=(g.t&1))
					return Res{true};
				chmax(r.s,g.s);
				chmin(r.t,g.t);
				if(r.t<r.s)
					return Res{true};
			}
		}
	}
	return z[v]=r;
}

int ans[Nmax];
void dfs1(int v,int p,Res r){
	if(!z[v].any){
		chmax(r.s,z[v].s);
		chmin(r.t,z[v].t);
	}
	ans[v]=r.s;
	r.s--;
	r.t=r.s+2;
	for(auto c:tree[v])if(c!=p)
		dfs1(c,v,r);
}

int main(){
	int n=read();
	REP(_,n-1){
		int a=read()-1,b=read()-1;
		tree[a].PB(b);
		tree[b].PB(a);
	}
	int k=read();
	fill(w,w+n,-1);
	REP(i,k){
		int v=read()-1,p=read();
		w[v]=p;
	}
	Res r=dfs(0,-1);
	if(r.imp)
		cout<<"No"<<endl;
	else{
		cout<<"Yes"<<endl;
		dfs1(0,-1,z[0]);
		REP(i,n)
			printf("%d\n",ans[i]);
	}
}
