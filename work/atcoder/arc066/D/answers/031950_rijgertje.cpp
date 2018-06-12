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

const int MOD=1000000007;
const int MAXBIT=70;

ll xx;
int x[MAXBIT],nx;

int ways[MAXBIT+1][2][2]; // ways[i][eq][c] = #ways to choose uj and vj for j<i such that for u+v<a if eq=0 and u+v=x if eq=1 (up to here), assuming it gets c carry


void run() {
	scanf("%lld",&xx);
	nx=0; for(ll i=xx;i!=0;i/=2) x[nx++]=i%2; reverse(x,x+nx);
	//REP(i,na) printf("%d",a[i]);

	memset(ways,0,sizeof(ways));
	ways[0][1][0]=1;
	REP(i,nx) REP(eq,2) REP(c,2) if(ways[i][eq][c]!=0) REP(ui,2) REP(vi,2) REP(nc,2) {
		bool can=false;
		REP(ai,2) REP(bi,2) {
			if((ai+bi+nc)%2!=vi) continue;
			if((ai^bi)!=ui) continue;
			if((ai+bi+nc)/2!=c) continue;
			can=true;
		}
		if(!can) continue;
		if(eq&&vi>x[i]) continue;
		int neq=eq&&vi==x[i]?1:0;
		//printf("ways[%d][%d][%d]=%d -> ways[%d][%d][%d]\n",i,eq,c,ways[i][eq][c],i+1,neq,nc);
		ways[i+1][neq][nc]+=ways[i][eq][c]; if(ways[i+1][neq][nc]>=MOD) ways[i+1][neq][nc]-=MOD;
	}
	int ret=ways[nx][0][0]+ways[nx][1][0]; if(ret>=MOD) ret-=MOD;
	printf("%d\n",ret);

	//set<pair<int,int> > chk; FORE(v,0,xx) FORE(a,0,v) chk.insert(MP(v,a^(v-a))); printf("want=%d\n",SZ(chk));
}

int main() {
	run();
	return 0;
}
