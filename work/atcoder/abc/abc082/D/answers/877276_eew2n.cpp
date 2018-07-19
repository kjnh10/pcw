#include <bits/stdc++.h>
#define YES "YES"
#define NO "NO"
#define YESNO OUT(three(solve(),YES,NO))
#define ECHO OUT(solve())
#define three(A,B,C) ((A)?(B):(C))
#define FOR(i,a,b)  for(LL i=(a);i< (LL)(b);i++)
#define EFOR(i,a,b) for(LL i=(a);i<=(LL)(b);i++)
#define RFOR(i,a,b) for(LL i=(a);i>=(LL)(b);i--)
#define REP(i,b) FOR(i,zero,b)
#define EREP(i,b) EFOR(i,zero,b)
#define RREP(i,b) RFOR(i,zero,b)
#define ALL(c) c.begin(),c.end()
#define MP make_pair
#define FI first
#define SE second
#define SI(x) (LL(x.size()))
#define PB push_back
#define DEBUG(a) OUT(a)
#define DEBUG2(a,b) OUT2(a,b)
#define cat cout << __LINE__ << endl
#define OUT(a) cout << (a) << endl
#define OUT2(a,b) cout << (a) <<" "<<(b) << endl
#define int LL
#define zero 0LL
using namespace std;
template<typename T> inline void maximize(T &a,T b){a=max(a,b);}
template<typename T> inline void minimize(T &a,T b){a=min(a,b);}
template<typename T> inline bool middle(T a,T b,T c){return b<=a && a<=c;}
typedef long long LL;
typedef double ld;
typedef LL ut;
typedef vector<ut> VI;
typedef vector<VI> VII;
typedef pair<ut,ut> pr;
typedef pair<ut,pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr,Vpr,greater<pr> > PQ;
inline void outputVI(VI x){REP(i,SI(x)){cout << three(i," ","") << x[i];}OUT("");}
const int SIZE=10000;
const int SIZE2=5010;
const int SIZE3=400;
const LL p=7+1e9;
const LL INF=1LL<<60;
const long double EPS=1e-7;
string S;
ut N,M,K,X,L,W,H;
// ut A,B,C,D,E,F,G,I,J,O,P,Q,R,T,U;
VI edges[SIZE];
LL x[2],vals[SIZE],nums[SIZE],maps[SIZE2][SIZE2],answer=zero;
VI v[2];
bool DP[SIZE*3][4];
bool able(int now){
	REP(j,2) REP(i,SIZE) DP[i][j]=0;
	DP[0][0]=1;
	REP(k,v[now].size()){
		int j=k&1;
		int next=v[now][k];
		REP(i,SIZE){
		//	if(DP[i][j]) cout << i <<" " << (j^1LL) << endl;
			DP[i][j^1LL]=false;
		}
		REP(i,SIZE){
			if(i+next<SIZE) DP[i+next][j^1LL]|=DP[i][j];
			if(i-next>=0) DP[i-next][j^1LL]|=DP[i][j];
		}
	}
	return DP[abs(x[now])][SI(v[now])&1LL];
}
signed main(){
	string s;
	cin >> s;
	cin >> x[0] >> x[1];
	s+=" ";
	int now=0,t=0;
	REP(i,s.size()){
		if(s[i]=='F'){

			t++;
		}
		else{
			if(now==0 && v[now].size()==0){
				v[now].PB(0);
				x[0]-=t;
			}
			else if(t)
				v[now].PB(t);
			now++;
			now%=2;
			t=0;
		}
	}
	REP(i,2) sort(ALL(v[i]),greater<int>());
	if(able(0) and able(1)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}