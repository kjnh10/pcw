#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=300000;

typedef struct L { ll a,b; L(ll a,ll b):a(a),b(b) {} L() {} } L;
// query(i) = max(j<=i,(i-j+1)*(i-j+2)/2+cnst[j]+cnst[i])
// query(i) = max(j<=i,-j*i+(j-1)*(j-2)/2+cnst[j])+(i+1)*(i+2)/2+cnst[i]-1
bool dbg=false;
typedef struct Hull {
	L l[MAXN]; int nl;
	void clear() { nl=0; }
	bool ok(const L &p,const L &q,const L &r) { /*p.a>q.a>r.a*/	return (q.b-p.b)*(p.a-r.a)>(r.b-p.b)*(p.a-q.a);	}
	ll get(const L &p,int x) { return p.a*x+p.b; }
	void add(int idx,ll cnst) {
		L cur(-idx,(ll)(idx-1)*(idx-2)/2+cnst);
		while(nl>=2&&!ok(l[nl-2],l[nl-1],cur)) --nl; l[nl++]=cur;
		//if(dbg) { printf("add(%d):",idx); REP(i,nl) printf(" %lld*x+%lld",l[i].a,l[i].b); puts(""); }
	}
	ll query(int idx,ll cnst) {
		while(nl>=2&&get(l[nl-2],idx)>=get(l[nl-1],idx)) --nl;
		//if(dbg) { printf("get(%d):",idx); REP(i,nl) printf(" %lld*x+%lld",l[i].a,l[i].b); puts(""); }
		ll ret=get(l[nl-1],idx)+(ll)(idx+1)*(idx+2)/2+cnst-1;
		//if(dbg) printf("-> %lld\n",ret);
		return ret;
	}
} Hull;
Hull h;

int n,nq;
int cost[MAXN];
ll csum[MAXN+1];
ll mxlft[MAXN]; // mxlft[i] = maximum score when only using drinks < i
ll mxrgt[MAXN]; // mxrgt[i] = maximum score when only using drinks > i
ll mxwth[MAXN]; // mxwth[i] = maximum score when using drink i

ll tmp[MAXN];
void divideandconquer(int l,int r) {
	int m=l+(r-l)/2;
	h.clear(); FORE(i,l,m) h.add(i,csum[i]+mxlft[i]); FORE(i,m,r) tmp[i]=h.query(i,-csum[i+1]+mxrgt[i]);
	//if(m<=r) { printf("%d..[%d..%d]:",l,m,r); FORE(i,m,r) printf(" %2lld",tmp[i]); puts(""); }
	for(int i=r-1;i>=m;--i) tmp[i]=max(tmp[i+1],tmp[i]); FORE(i,m,r) mxwth[i]=max(mxwth[i],tmp[i]);
	h.clear(); for(int i=r;i>=m;--i) h.add(n-i-1,-csum[i+1]+mxrgt[i]); for(int i=m-1;i>=l;--i) tmp[i]=h.query(n-i-1,csum[i]+mxlft[i]);
	//if(l<=m-1) { printf("[%d..%d)..%d:",l,m,r); FOR(i,l,m) printf(" %2lld",tmp[i]); puts(""); }
	FOR(i,l+1,m) tmp[i]=max(tmp[i-1],tmp[i]); FOR(i,l,m) mxwth[i]=max(mxwth[i],tmp[i]);
	if(l<=m-1) divideandconquer(l,m-1);
	if(m+1<=r) divideandconquer(m+1,r);
}

void precalc() {
	csum[0]=0; REP(i,n) csum[i+1]=csum[i]+cost[i];
	h.clear(); mxlft[0]=0;
	REP(i,n-1) { h.add(i,csum[i]+mxlft[i]); mxlft[i+1]=max(mxlft[i],h.query(i,-csum[i+1])); }
	h.clear(); mxrgt[n-1]=0; dbg=true;
	for(int i=n-1;i>=1;--i) { h.add(n-i-1,-csum[i+1]+mxrgt[i]); mxrgt[i-1]=max(mxrgt[i],h.query(n-i-1,csum[i])); }
	dbg=false;
	//printf("lft:"); REP(i,n) printf(" %2lld",mxlft[i]); puts("");
	//printf("rgt:"); REP(i,n) printf(" %2lld",mxrgt[i]); puts("");
	REP(i,n) mxwth[i]=LLONG_MIN;
	divideandconquer(0,n-1);
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&cost[i]);
	precalc();
	scanf("%d",&nq);
	REP(i,nq) {
		int idx,ncost; scanf("%d%d",&idx,&ncost); --idx;
		ll res=max(mxlft[idx]+mxrgt[idx],mxwth[idx]+cost[idx]-ncost);
		printf("%lld\n",res);
	}
}

int main() {
	run();
	return 0;
}
