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

const int mod=1000000007;
template<class T,class U>
void add(T& a,U b){
	a=((ll)a+b)%mod;
}

template<class T,class U>
void sub(T& a,U b){
	a=((ll)a-b%mod+mod)%mod;
}

template<class T,class U>
void mult(T& a,U b){
	a=((ll)a*b)%mod;
}

ll modPow(ll a,ll p){
	ll s=1;
	REP(i,30){
		if((p>>i)&1)
			mult(s,a);
		mult(a,a);
	}
	return s;
}

ll modInv(ll a){
	return modPow(a,mod-2);
}

const int Nmax=334;
int buf[2][Nmax][Nmax];
vector<pi> qs[Nmax];

signed main(){
	int n=read(),m=read();
	REP(i,m){
		int l=read(),r=read(),x=read();
		qs[r].PB(pi(l,x));
	}
	int cur=0;
	buf[cur][0][0]=1;
	FOR(i,1,n+1){
		int nx=cur^1;
		memset(buf[nx],0,sizeof(buf[nx]));
		REP(j,i)REP(k,i)add(buf[nx][j][k],buf[cur][j][k]);
		REP(j,i)REP(k,i)add(buf[nx][i-1][k],buf[cur][j][k]);
		REP(j,i)REP(k,i)add(buf[nx][i-1][j],buf[cur][j][k]);
		for(auto q:qs[i])
			REP(j,i)REP(k,i){
				int cnt=1;
				if(q.first<=k)cnt++;
				if(q.first<=j)cnt++;
				if(cnt!=q.second)buf[nx][j][k]=0;
			}
		swap(cur,nx);
	}
	int ans=0;
	REP(i,n+1)REP(j,n+1)add(ans,buf[cur][i][j]);
	cout<<ans<<endl;
}