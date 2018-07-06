
#pragma region GNUC
//以下を参考にした
//https://yukicoder.me/wiki/auto_vectorization
#ifdef __GNUC__
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#endif
#pragma endregion

#define _USE_MATH_DEFINES

#pragma region
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <cmath>

#include <string>
#include <cstring>
#include <vector>

#include <queue>
#include <complex>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <fstream>
#include <random>
#pragma endregion //#include
/////////
#define REP(i, x, n) for(int i = x; i < n; ++i)
#define rep(i,n) REP(i,0,n)
/////////
#pragma region
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
/////////
const int INF = (int)1e9;
const int MOD = (int)1e9+7;
const LL LINF = (LL)1e18;
/////////
using namespace::std;
/////////
#pragma region Math
// 最大公約数
template<class T>
inline T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
//inline T gcd(T a, T b){return b == 0 ? a : gcd(b, a % b);}

// 最小公倍数
template<class T>
inline T lcm(T a, T b){return a / gcd(a, b) * b;}
//inline T lcm(T a, T b){return a * b / gcd(a, b);}
#pragma endregion //math
#pragma region
template<class T>
void UNIQUE(vector<T>& vec){
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end() );
}
#pragma endregion //
////////////////////////////////
struct edge{int to;LL cost;};
edge make_edge(int to,LL cost){
	edge ret = {to,cost};
	return ret;
}
#pragma region
void dijkstra(int root,int V,vector<LL>& dist,
	vector< vector<edge> > G	){
	priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > > que;
	dist.assign(V,LINF);
	dist[root] = 0;
	que.push(pair<LL,int>(0,root));//距離、頂点番号

	while( !que.empty() ){
		pair<LL,int> p = que.top();que.pop();
		int v = p.second;
		if( dist[v] < p.first ) continue;
		for(int i=0;i < (int)G[v].size();++i){
			edge e = G[v][i];
			if( dist[e.to] > dist[v] + e.cost ){
				dist[e.to] = dist[v] + e.cost;
				que.push(pair<LL,int>(dist[e.to],e.to));
			}
		}
	}
}
#pragma endregion //ダイクストラ法:O(|E|log|V|)

#pragma region 
//http://sugarknri.hatenablog.com/entry/2016/07/16/165715
LL inv[1000010];
void makeinv(const LL P){
	int i;
	inv[1]=1;
	for(i=2;i<=1000000;i++){
		inv[i] = inv[P%i] * (P-P/i)%P;//OVF
	}
}

ULL nCk(ULL N,ULL k){
	makeinv(MOD);
	k = min(k,N-k);
	if( k == 0 ){return 1;}
	if( k == 1 ){return N%MOD;}
	ULL ret = 1;
	for(int i=1;i<=k;++i){
		ret *= ((N+1-i)*inv[i])%MOD;//OVF
		ret %= MOD;
	}
	return ret;
}
#pragma endregion //組み合わせnCk(,10^5)
#pragma region 
template<class T,class U>
istream& operator>>(istream& in,pair<T,U> P){
	in >> P.first >> P.second;
	return in;
}
#pragma endregion //cin
#pragma region 
#pragma endregion //
const double PI = acos(-1.0);
const double EPS = 1e-9;

void solve(){
	int N;
	cin >> N;
	vector<int> X(2000),Y(2000);
	for(int i=0;i<N;++i){
		cin >> X[i] >> Y[i];
	}
	vector< double > th(4000);
	int ri = 0;//直角三角形
	int ob = 0;//鈍角三角形
	for(int A=0;A<N;++A){//基準点index A
		int count = 0;
		for(int B=0;B<N;++B){
			if( A==B ) continue;
			th[count] = PI+atan2(1.0*(Y[B]-Y[A]),1.0*(X[B]-X[A]));
			++count;
		}
		sort(th.begin(), th.begin()+count);
		for(int B=0;B<count;++B){
			th[B+count] = th[B] + 2*PI;
		}

		int L=0,R=0;
		for(int i=0;i<count;++i){
			double Lim0 = th[i] + PI/2;
			double Lim1 = Lim0 + PI/2;
			while( L < 2*count && th[L]-Lim0 < -EPS)++L;//直角以上を探す
			while( R < 2*count && th[R]-Lim1 < -EPS)++R;//180以上を探す
			if( L < 2*count && abs(th[L]-Lim0) < EPS){
				++ri;//直角三角形
				++L;
			}
			ob += max(0,R-L);//鈍角三角形[L,R)
		}
	}
	LL all = 1LL*N*(N-1)*(N-2)/6;
	LL ac = all - ri - ob;//鋭角
	cout << ac << " " << ri << " " << ob << endl;
}

#pragma region main
signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定
	
	solve();
}
#pragma endregion //main()