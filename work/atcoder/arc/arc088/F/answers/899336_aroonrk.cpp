#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DMP(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))

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
	scanf("%" SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%" PRId64,x);
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

const int Nmax=114514;
vi tr[Nmax];
pi dfs(int v,int p,int b){
	multiset<int> lens;
	int cnt=0;
	for(auto ch:tr[v])if(ch!=p){
		pi w=dfs(ch,v,b);
		cnt+=w.first;
		lens.insert(w.second);
	}
	int rems=0,mn=inf;
	while(!lens.empty()){
		auto itr=lens.end();itr--;
		int x=*itr;lens.erase(itr);
		itr=lens.upper_bound(b-x);
		if(itr==lens.begin()){
			rems++;
			chmin(mn,x);
		}else{
			itr--;
			lens.erase(itr);
			cnt++;
		}
	}
	if(mn==b){
		rems++;
		mn=0;
	}
	if(rems)
		cnt+=rems-1;
	else
		mn=0;
	return pi(cnt,mn+1);
}

signed main(){
	int n=read();
	REP(i,n-1){
		int a=read()-1,b=read()-1;
		tr[a].PB(b);
		tr[b].PB(a);
	}
	int par;
	REP(i,n)if(tr[i].size()==1)par=i;
	int root=tr[par][0];
	int a=dfs(root,par,inf).first+1;
	int bot=0,up=n;
	while(up-bot>1){
		int mid=(up+bot)/2;
		pi w=dfs(root,par,mid);
		if(w.first==a-1)
			up=mid;
		else
			bot=mid;
	}
	cout<<a<<" "<<up<<endl;
}