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

struct Pos{
	ld x,y;
	Pos operator+(const Pos&rhs)const{
		return Pos{x+rhs.x,y+rhs.y};
	}
	Pos operator-(const Pos&rhs)const{
		return Pos{x-rhs.x,y-rhs.y};
	}
	Pos operator*(const ld v)const{
		return Pos{x*v,y*v};
	}
};
ld Cross(const Pos&l,const Pos&r){
	return l.x*r.y-l.y*r.x;
}
signed main(){
	int n=read(),l=read();
	vector<Pos> ps(n+2);
	ps[0]=Pos{-1,0};
	ps[1]=Pos{0,0};
	int i=0,j=2;
	REP(_,n){
		ld ti=read(),v=read();
		ld x=ps[j-1].x+v,y=ps[j-1].y-v*ti;
		Pos w{x,y};
		while(ps[i].x<x-l)i++;
		{
			ld s=x-l-ps[i-1].x,t=ps[i].x-(x-l),d=ld(1)/(ps[i].x-ps[i-1].x);
			ps[i-1]=(ps[i]*s+ps[i-1]*t)*d;
			printf("%.10lf\n",double((ps[i-1].y-y)/l));
			i--;
		}
		while(j-i>=2)
			if(Cross(w-ps[j-1],ps[j-2]-ps[j-1])>0)j--;
			else break;
		ps[j++]=w;
	}
}
