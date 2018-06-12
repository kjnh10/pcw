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

const int Nmax=8100;
bool dp[2][Nmax];
bool Check(vi w,int t){
	int cur=0,nx=1;
	ZERO(dp[cur]);
	dp[cur][0]=true;
	for(auto a:w){
		ZERO(dp[nx]);
		REP(i,Nmax)if(dp[cur][i]){
			dp[nx][i+a]|=true;
			dp[nx][abs(i-a)]|=true;
		}
		swap(cur,nx);
	}
	return dp[cur][t];
}

signed main(){
	string s=readString();
	int x=read(),y=read();
	vi xs,ys;
	bool hori=true,first=true;
	int n=s.size(),cnt=0;
	REP(i,n)
		if(s[i]=='F'){
			cnt++;
			if(i==n-1||s[i+1]=='T'){
				if(first){
					x-=cnt;
					first=false;
				}else{
					(hori?xs:ys).PB(cnt);
				}
				cnt=0;
			}
		}else{
			first=false;
			hori^=1;
		}
	if(Check(xs,abs(x))&&Check(ys,abs(y)))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}