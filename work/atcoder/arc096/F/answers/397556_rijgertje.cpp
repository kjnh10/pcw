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

const int MAXN=50;
struct Z { ll cost; int val; int lim; };
bool operator<(const Z &a,const Z &b) { return a.cost*b.val<b.cost*a.val; }

int n,cap,lim;
int w[MAXN],par[MAXN];

ll wsum[MAXN]; int sz[MAXN];


Z z[MAXN];
vector<pair<ll,int> > singles;

vector<int> cost;

void run() {
	scanf("%d%d%d",&n,&cap,&lim); REP(i,n) { scanf("%d",&w[i]); if(i==0) par[i]=-1; else scanf("%d",&par[i]),--par[i]; }

	REP(i,n) wsum[i]=w[i],sz[i]=1; for(int i=n-1;i>=0;--i) if(par[i]!=-1) wsum[par[i]]+=wsum[i],sz[par[i]]+=sz[i];

	REP(i,n) z[i].cost=wsum[i],z[i].val=sz[i],z[i].lim=min(par[i]==-1?INT_MAX:lim,wsum[i]==0?INT_MAX:(int)(cap/wsum[i]));
	sort(z,z+n);
	singles.clear();
	REP(i,n) { int cur=min(z[i].lim,n); REP(j,cur) singles.PB(MP(z[i].cost,z[i].val)); z[i].lim-=cur; }
	//printf("z:"); REP(i,n) printf(" [%lld->%d (%d)]",z[i].cost,z[i].val,z[i].lim); puts("");
	//printf("singles:"); REPSZ(i,singles) printf(" %lld->%d",singles[i].first,singles[i].second); puts("");


	int totvalsum=0; REPSZ(i,singles) totvalsum+=singles[i].second;
	cost=vector<int>(totvalsum+1,INT_MAX); cost[0]=0; int mxvalsum=0;
	REPSZ(i,singles) {
		for(int j=mxvalsum;j>=0;--j) if(cost[j]!=INT_MAX) {
			int nj=j+singles[i].second,ncost=(int)min((ll)INT_MAX,cost[j]+singles[i].first);
			if(ncost<cost[nj]) cost[nj]=ncost,mxvalsum=max(mxvalsum,nj);
		}
	}
	//printf("cost:" ); REPE(i,mxvalsum) if(cost[i]!=INT_MAX) printf(" %d=%d",i,cost[i]); puts("");
	ll ret=0;
	REPE(i,mxvalsum) if(cost[i]<=cap) {
		int rem=cap-cost[i]; ll cur=i;
		REP(j,n) {
			int now=z[j].lim; if(z[j].cost!=0) now=min(now,(int)(rem/z[j].cost));
			cur+=(ll)now*z[j].val;
			rem-=now*z[j].cost;
		}
		ret=max(ret,cur);
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
