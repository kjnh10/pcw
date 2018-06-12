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
const int BufMax=364364;
struct Kyuri{
	Kyuri *l,*r;
	int x,lz,rng,s;
	void Propagate(){
		if(l)l->lz+=lz;
		if(r)r->lz+=lz;
		x+=lz;
		lz=0;
	}
	Kyuri* Update(){
		s=1;
		if(l)s+=l->s;
		if(r)s+=r->s;
		return this;
	}
} ks[BufMax];
Kyuri* Merge(Kyuri* a,Kyuri* b){
	if(!a)return b;
	if(!b)return a;
	if(a->rng>b->rng){
		a->Propagate();
		a->r=Merge(a->r,b);
		return a->Update();
	}else{
		b->Propagate();
		b->l=Merge(a,b->l);
		return b->Update();
	}
}
pair<Kyuri*,Kyuri*> SplitByX(Kyuri* a,int x){
	if(!a)return MP((Kyuri*)0,(Kyuri*)0);
	a->Propagate();
	if(x<=a->x){
		auto s=SplitByX(a->l,x);
		a->l=s.second;
		return MP(s.first,a->Update());
	}else{
		auto s=SplitByX(a->r,x);
		a->r=s.first;
		return MP(a->Update(),s.second);
	}
}
pair<Kyuri*,Kyuri*> SplitByS(Kyuri* a,int s){
	if(!a)return MP((Kyuri*)0,(Kyuri*)0);
	if(s==0)return MP((Kyuri*)0,a);
	if(s==a->s)return MP(a,(Kyuri*)0);
	a->Propagate();
	int c=a->l?a->l->s:0;
	if(s<=c){
		auto g=SplitByS(a->l,s);
		a->l=g.second;
		return MP(g.first,a->Update());
	}else{
		auto g=SplitByS(a->r,s-1-c);
		a->r=g.first;
		return MP(a->Update(),g.second);
	}
}
Kyuri* GetL(Kyuri* a){
	if(!a->l)return a;
	a->Propagate();
	return GetL(a->l);
}
void GetX(Kyuri* a,vi& dst){
	if(!a)return;
	a->Propagate();
	GetX(a->l,dst);
	dst.PB(a->x);
	GetX(a->r,dst);
}
Kyuri* newNode(int x){
	static int c=0;
	ks[c].x=x;
	ks[c].s=1;
	return ks+(c++);
}

signed main(){
	REP(i,BufMax)ks[i].rng=(int(rand())<<32)|rand();
	int n=read();
	vector<pi> w;
	REP(i,n){
		int l=read(),r=read();
		w.PB(pi(l,r));
	}
	Kyuri* root=Merge(newNode(w[0].first),newNode(w[0].first));
	__int128 cost=0;
	FOR(i,1,n){
		auto s=SplitByS(root,i);
		s.first->lz-=w[i].second-w[i].first;
		s.second->lz+=w[i-1].second-w[i-1].first;
		root=Merge(s.first,s.second);
		auto g=GetL(root);
		int gx=g->x+g->lz;
		s=SplitByX(root,w[i].first);
		root=Merge(Merge(s.first,newNode(w[i].first)),Merge(newNode(w[i].first),s.second));
		int hx=min(gx,w[i].first);
		cost+=(gx-hx)*i;
		cost+=w[i].first-hx;
	}
	vi x;
	GetX(root,x);
	FOR(i,1,n)cost+=(x[i]-x[i-1])*(i-n);
	cout<<int(cost)<<endl;
}
