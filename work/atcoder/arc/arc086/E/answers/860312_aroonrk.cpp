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

const int Nmax=201712;
vi wafBuffer[Nmax];
int wafBufferUsed;

struct Waf{
	vi*ptr;
	Waf(){
		ptr=wafBuffer+wafBufferUsed++;
	}
	void push_front(int v){
		ptr->PB(v);
	}
	int size(){
		return ptr->size();
	}
	int& operator[](int i){
		return ptr->at(size()-1-i);
	}
};

vi tr[Nmax];
Waf dfs(int v){
	if(tr[v].empty()){
		Waf res;
		res.push_front(modInv(2));
		return res;
	}
	vector<Waf> ws;
	for(auto ch:tr[v])
		ws.PB(dfs(ch));
	sort(ALL(ws),[&](Waf a,Waf b){
		return a.size()>b.size();
	});
	if(int(ws.size())>=2){
		REP(i,ws[1].size()){
			int dp[3]{1,0,0};
			REP(j,ws.size()){
				if(ws[j].size()<=i)break;
				for(int k=1;k>=0;k--){
					add(dp[k+1],dp[k]*ws[j][i]);
					int x=1;sub(x,ws[j][i]);
					mult(dp[k],x);
				}
			}
			ws[0][i]=dp[1];
		}
	}
	ws[0].push_front(modInv(2));
	return ws[0];
}

signed main(){
	int n=read();
	REP(i,n)
		tr[read()].PB(i+1);
	Waf w=dfs(0);
	int ans=0;
	REP(i,w.size())
		add(ans,w[i]);
	mult(ans,modPow(2,n+1));
	cout<<ans<<endl;
}