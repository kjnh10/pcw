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

const int Nmax=100010;
int k[Nmax];
bool inc[Nmax];
vi tr[Nmax];
int dfs1(int v,int p){
	int res=k[v];
	for(auto ch:tr[v])if(ch!=p)
		res+=dfs1(ch,v);
	inc[v]=res;
	return res;
}

int ans;
pi dfs2(int v,int p){
	vi ups{0},dws{0};
	for(auto ch:tr[v])if(ch!=p){
		pi g=dfs2(ch,v);
		ups.PB(g.first+(k[v]?2:0));
		dws.PB(g.second+(k[ch]?2:0));
	}
	int um=0,dm=0,s=ups.size();
	REP(i,s){
		chmax(ans,um+dws[i]);
		chmax(ans,dm+ups[i]);
		chmax(um,ups[i]);
		chmax(dm,dws[i]);
	}
	return pi(*max_element(ALL(ups)),*max_element(ALL(dws)));
}

signed main(){
	int n=read();
	REP(_,n-1){
		int x=read()-1,y=read()-1;
		tr[x].PB(y);
		tr[y].PB(x);
	}
	{
		string c=readString();
		if(c==string(n,'B')){
			print(0);
			return 0;
		}
		REP(i,n)
			k[i]=c[i]=='W';
	}
	int root=-1;
	REP(i,n)if(k[i])
		root=i;
	dfs1(root,-1);
	
	int base=0;
	int cnt=0;
	REP(i,n)if(inc[i]){
		cnt++;
		vi tmp;
		for(auto to:tr[i])if(inc[to]){
			k[i]^=1;
			tmp.PB(to);
		}
		tr[i]=tmp;
		base+=k[i];
	}
	cerr<<cnt<<endl;
	
	base+=(cnt-1)*2;
	cerr<<base<<endl;
	
	dfs2(root,-1);
	
	print(base-ans);
}
