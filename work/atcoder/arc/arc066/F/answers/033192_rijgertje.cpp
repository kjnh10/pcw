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
const int MAXS=4*MAXN;
const int MAXSVAL=5175732;

int n,nq;
int cost[MAXN]; ll csum[MAXN+1];

ll dpl[MAXN],dpr[MAXN]; // dpl[i] == maximum obtainable with problems < i, dpr[i] == maximumum obtainable with problems > i

int lftoff[MAXS],rgtoff[MAXS];
ll sval[MAXSVAL]; int nsval;

// dpl[i]=max(dpl[i-1],max(j<i,dpl[j]+(i-j)*(i-j+1)/2-csum[i]+csum[j]))
// dpl[i]=max(dpl[i-1],i*(i+1)/2-csum[i]+max(j<i,j*(j-1)/2+dpl[j]+csum[j]-i*j))
// dpr[i]=max(dpr[i+1],max(j>i,dpr[j]+(j-i)*(j-i+1)/2-csum[j+1]+csum[i+1]))
// dpr[i]=max(dpr[i+1],i*(i-1)/2+csum[i+1]+max(j>i,j*(j+1)/2+dpr[j]-csum[j+1]-i*j))
typedef struct Hull {
	pair<int,ll> stck[MAXN]; int nstck;

	void reset() { nstck=0; }
	void addlline(int j) {
		pair<int,ll> cur=MP(-j,(ll)j*(j-1)/2+dpl[j]+csum[j]);
		while(nstck>=2) {
			pair<int,ll> p=stck[nstck-2],q=stck[nstck-1];
			if((q.first-cur.first)*(q.second-p.second)<=(p.first-q.first)*(cur.second-q.second)) --nstck; else break;
		}
		stck[nstck++]=cur;
	}
	ll getlval(int i) {
		while(nstck>=2) {
			pair<int,ll> p=stck[nstck-2],q=stck[nstck-1];
			if((ll)i*q.first+q.second<=(ll)i*p.first+p.second) --nstck; else break;
		}
		return (ll)i*(i+1)/2-csum[i]+(ll)i*stck[nstck-1].first+stck[nstck-1].second;
	}
	void addrline(int jj) {
		int j=n-1-jj; pair<int,ll> cur=MP(-j,(ll)j*(j-1)/2+dpr[jj]-csum[jj+1]);
		while(nstck>=2) {
			pair<int,ll> p=stck[nstck-2],q=stck[nstck-1];
			if((q.first-cur.first)*(q.second-p.second)<=(p.first-q.first)*(cur.second-q.second)) --nstck; else break;
		}
		stck[nstck++]=cur;
	}
	ll getrval(int ii) {
		int i=n-1-ii;
		while(nstck>=2) {
			pair<int,ll> p=stck[nstck-2],q=stck[nstck-1];
			if((ll)i*q.first+q.second<=(ll)i*p.first+p.second) --nstck; else break;
		}
		return (ll)i*(i+1)/2+csum[ii+1]+(ll)i*stck[nstck-1].first+stck[nstck-1].second;
	}
} Hull;
Hull h;
void sinit(int x,int l,int r) {
	assert(x<MAXS); int m=l+(r-l)/2; // r-l+1
	
	h.reset();
	rgtoff[x]=nsval; nsval+=r-(m+1)+1; assert(nsval<=MAXSVAL);
	FORE(i,l,m) h.addlline(i);
	FORE(i,m+1,r) sval[rgtoff[x]+i-(m+1)]=h.getlval(i+1)+dpr[i];
	//if(r-(m+1)+1!=0) { printf("\tx(%d..%d)..%d: ",l,m,r); FORE(i,m+1,r) printf(" %2lld",sval[rgtoff[x]+i-(m+1)]); puts(""); }
	for(int i=r-1;i>=m+1;--i) if(sval[rgtoff[x]+i-(m+1)+1]>sval[rgtoff[x]+i-(m+1)]) sval[rgtoff[x]+i-(m+1)]=sval[rgtoff[x]+i+1-(m+1)];
	//if(r-(m+1)+1!=0) { printf("\ty(%d..%d)..%d: ",l,m,r); FORE(i,m+1,r) printf(" %2lld",sval[rgtoff[x]+i-(m+1)]); puts(""); }
	
	h.reset();
	lftoff[x]=nsval; nsval+=m-l+1; assert(nsval<=MAXSVAL);
	for(int i=r;i>=m;--i) h.addrline(i);
	for(int i=m;i>=l;--i) sval[lftoff[x]+i-l]=h.getrval(i-1)+dpl[i];
	//if(m-l+1!=0) { printf("\tx%d..%d(..%d): ",l,m,r); FORE(i,l,m) printf(" %2lld",sval[lftoff[x]+i-l]); puts(""); }
	FORE(i,l+1,m) if(sval[lftoff[x]+i-1-l]>sval[lftoff[x]+i-l]) sval[lftoff[x]+i-l]=sval[lftoff[x]+i-1-l];
	//if(m-l+1!=0) { printf("\ty%d..%d(..%d): ",l,m,r); FORE(i,l,m) printf(" %2lld",sval[lftoff[x]+i-l]); puts(""); }

	if(l<=m-1) sinit(2*x+1,l,m-1);
	if(m+1<=r) sinit(2*x+2,m+1,r);
}

ll sget(int x,int l,int r,int IDX) { // get maximum when solving IDX in an interval contained in [l,r]
	int m=l+(r-l)/2;
	if(l==r) return 1-cost[IDX]+dpl[IDX]+dpr[IDX];
	ll ret=LLONG_MIN;
	if(IDX<=m) ret=max(ret,sval[lftoff[x]+IDX-l]);
	if(IDX>m) ret=max(ret,sval[rgtoff[x]+IDX-(m+1)]);
	if(IDX<m) ret=max(ret,sget(2*x+1,l,m-1,IDX));
	if(IDX>m) ret=max(ret,sget(2*x+2,m+1,r,IDX));
	//printf("\tsget(%d..%d,%d)=%lld\n",l,r,IDX,ret);
	return ret;
}

ll calcwithout(int idx) {
	return dpl[idx]+dpr[idx];
}

ll calcwith(int idx) {
	return sget(0,0,n-1,idx);
}

void precalc() {
	csum[0]=0; REP(i,n) csum[i+1]=csum[i]+cost[i];

	h.reset();
	dpl[0]=0;
	FOR(i,1,n) {
		h.addlline(i-1);
		dpl[i]=max(dpl[i-1],h.getlval(i));
	}

	h.reset();
	dpr[n-1]=0;
	for(int i=n-2;i>=0;--i) {
		h.addrline(i+1);
		dpr[i]=max(dpr[i+1],h.getrval(i));
	}

	//REP(i,n) printf("%2lld ",dpl[i]); puts("");
	//REP(i,n) printf("%2lld ",dpr[i]); puts("");

	nsval=0;
	sinit(0,0,n-1);
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&cost[i]);
	precalc();

	scanf("%d",&nq);
	REP(qi,nq) {
		int i,ci; scanf("%d%d",&i,&ci); --i;
		ll a=calcwithout(i),b=calcwith(i)+cost[i]-ci,res=max(a,b);
		printf("%lld\n",res);
	}
}

/*int dp[MAXN+1];
void test() {
	dp[1]=1;
	FORE(i,2,MAXN) {
		int l=(i+1)/2,r=i/2;
		dp[i]=l+r+dp[l-1]+dp[r];
	}
	int mx=0; FORE(i,1,MAXN) if(dp[i]>mx) mx=dp[i]; printf("%d\n",mx);
}*/

int main() {
	run();
	return 0;
}
