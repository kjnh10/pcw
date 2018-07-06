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

int h,w;
inline void GetState(int bit,int (&dst)[6]){
	REP(i,h){
		dst[i]=bit&3;
		bit>>=2;
	}
}
inline int GetHash(int (&src)[6]){
	int res=0;
	for(int i=h-1;i>=0;i--){
		res<<=2;
		res|=src[i];
	}
	return res;
}

int st[6];
int cmp[6];
bool g[6][6];
void dfs(int v,int c){
	cmp[v]=c;
	REP(to,h)
		if(g[v][to]&&cmp[to]==-1)dfs(to,c);
}

int Wafrelka(int bit,int mask){
	GetState(bit,st);
	memset(cmp,-1,sizeof(cmp));
	REP(i,h)if(!((mask>>i)&1))
		cmp[i]=0;
	int c=1;
	REP(i,h)REP(j,h)
		g[i][j]=(i!=j&&st[i]==st[j]&&st[i]);
	REP(i,h-1)if((mask>>i)&(mask>>(i+1))&1)
		g[i][i+1]=g[i+1][i]=true;
	REP(i,h)if(cmp[i]==-1&&st[i]==1){
		dfs(i,c++);
		break;
	}
	if(c==1)return -1;
	REP(i,h)if(cmp[i]==-1)
		dfs(i,c++);
	return GetHash(cmp);
}

signed main(){
	h=read(),w=read();
	vi cur(1<<(2*h),0),nx(1<<(2*h),0);
	cur[1]=1;
	REP(_,w){
		fill(ALL(nx),0);
		REP(bit,1<<(2*h))if(cur[bit])
			REP(mask,1<<h){
				int idx=Wafrelka(bit,mask);
				if(idx!=-1)
					add(nx[idx],cur[bit]);
			}
		swap(cur,nx);
	}
	int ans=0;
	REP(bit,1<<(2*h)){
		GetState(bit,st);
		if(st[h-1]==1)
			add(ans,cur[bit]);
	}
	cout<<ans<<endl;
}
