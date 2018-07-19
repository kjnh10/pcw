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

const int Vmax=500;
int binom[Vmax][Vmax];
void Init(){
	binom[0][0]=1;
	REP(i,Vmax)REP(j,Vmax){
		if(i-1>=0)add(binom[i][j],binom[i-1][j]);
		if(j-1>=0)add(binom[i][j],binom[i][j-1]);
	}
}
int Choose(int n,int k){
	return binom[n-k][k];
}

const int Nmax=75;
int n,k;
string s;
vi t;
int SetT(){
	t.resize(k,inf);
	int j=0,cnt=0;
	REP(i,k)
		if(s[i]=='r'){
			while(j<k&&(j<i||s[j]=='r'))
				j++;
			if(j==k)
				break;
			t[i]=cnt*2;
			t[j]=cnt*2+1;
			j++;
			cnt++;
		}
	return cnt;
}

int dp[Nmax][Nmax][Nmax];
vi Sigma(vi num){
	int p=num.size(),m=num.back();
	ZERO(dp);
	dp[0][0][0]=1;
	REP(y,m+1){
		for(int x=p;x>=0;x--){
			REP(sm,m+1){
				int cur=sm;
				FOR(z,x+1,p+1){
					cur+=y;
					if(cur>num[z-1])break;
					add(dp[z][y][cur],dp[x][y][sm]*Choose(p-x,z-x));
				}
			}
		}
		if(y<m)
		REP(x,p+1)
			REP(sm,m+1)
				add(dp[x][y+1][sm],dp[x][y][sm]);
	}
	return vi(dp[p][m],dp[p][m]+m+1);
}

int hog[Nmax];

int semiBuf[Nmax][Nmax];
void Semiexp(int u,int p,int w){
	if(u==0){
		add(hog[1],w);
	}else{
		add(hog[u+p-1],w);
		add(hog[u+p],w*2);
		add(hog[u+p+1],w);
	}
}

void Wafrelka(int p,int q){
	vi z(k,0);
	{
		int cnt=0;
		REP(i,k)
			if(t[i]>=p*2&&s[i]=='r'&&cnt<q){
				z[i]=1;
				cnt++;
			}
		if(cnt<q)return;
	}
	vi num(p,0);
	{
		int j=0;
		for(int i=k-1;i>=0;i--)if(j<p){
			if(t[i]>=p*2){
				if(z[i]==0)
					num[j]++;
			}else if(t[i]%2){
				j++;
			}
		}
	}
	FOR(i,1,p)
		num[i]+=num[i-1];
	if(p==0)num.PB(0);
	vi x=Sigma(num);
	REP(i,x.size()){
		REP(j,p*2+1){
			int w=Choose(p+q,p);
			mult(w,x[i]);
			mult(w,Choose(p*2,j));
			int used=p+i*2+j+q;
			if(used+(p+q-1)<=n)
				add(semiBuf[used][p+q],w);
		}
	}
}

int Wo(){
	int res=0;
	FOR(i,1,n+1)
		add(res,hog[i]*Choose(n-1,i-1));
	return res;
}

signed main(){
	Init();
	n=read(),k=read();
	s=readString();
	int cnt=SetT();
	REP(p,cnt+1)REP(q,k-p*2+1)
		Wafrelka(p,q);
	REP(i,n+1)REP(j,n+1)
		Semiexp(i,j,semiBuf[i][j]);
	cout<<Wo()<<endl;
}