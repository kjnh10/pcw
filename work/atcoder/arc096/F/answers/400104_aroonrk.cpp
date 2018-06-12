#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#ifdef MAROON_LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#endif
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))

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
	os<<"{";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

ll read(){
	ll i;
	scanf("%" SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
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
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

const int Vmax=2510;
const int Nmax=55;
int dp[Nmax][Vmax],dq[Nmax][Vmax],m[Nmax];
vi tr[Nmax];
struct Waf{
	int val,cost;
	bool operator<(const Waf&rhs)const{
		return val*rhs.cost<rhs.val*cost;
	}
};
Waf dfs(int v,vector<Waf>&dst){
	Waf w{1,m[v]};
	for(auto ch:tr[v]){
		Waf z=dfs(ch,dst);
		w.val+=z.val;
		w.cost+=z.cost;
	}
	dst.PB(w);
	return w;
}
//doughnut 0 はいくつでも使ってよい
signed main(){
	int n=read(),x=read(),d=read();
	REP(i,n){
		m[i]=read();
		if(i)
			tr[read()-1].PB(i);
	}
	vector<Waf> ws;
	dfs(0,ws);
	sort(ALL(ws));
	
	FOR(i,1,Vmax)dp[0][i]=inf;
	REP(i,n)
		REP(j,Vmax){
			dp[i+1][j]=inf;
			for(int k=j,c=0;k>=0;k-=ws[i].val,c++)
				if(c<=d)
					chmin(dp[i+1][j],dp[i][k]+c*ws[i].cost);
		}
	
	FOR(i,1,Vmax)dq[n][i]=-inf;
	for(int i=n-1;i>=0;i--)
		REP(j,Vmax){
			dq[i][j]=-inf;
			for(int k=j,c=0;k>=0;k-=ws[i].val,c++)
				if(c<=d)
					chmax(dq[i][j],dq[i+1][k]+c*ws[i].cost);
		}
	
	int ans=0,val=0,cost=0;
	for(int i=n-1;i>=0;i--){
		if(cost>=inf)break;
		REP(j,Vmax)if(dp[i][j]<inf)REP(k,min(val+1,Vmax))if(-dq[i+1][k]<inf){
			int v=val+j-k;
			int c=cost+dp[i][j]-dq[i+1][k];
			if(c<=x){
				int ad=(x-c)/ws[i].cost;
				if(ws[i].val<n)chmin(ad,d);
				chmax(ans,v+ad*ws[i].val);
			}
		}
		val+=ws[i].val*d;
		cost+=ws[i].cost*d;
		if(ws[i].val==n)break;
	}
	
	print(ans);
}
