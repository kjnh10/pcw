#pragma region GNUC
//https://yukicoder.me/wiki/auto_vectorization
#ifdef __GNUC__
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#endif
#pragma endregion
#define _USE_MATH_DEFINES
#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <cmath>

#include <string>
#include <cstring>
#include <vector>
#include <tuple>

#include <queue>
#include <complex>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <fstream>
#include <random>
//#include <time.h>
#include <ctime>
#pragma endregion //#include
/////////
#define REP(i, x, n) for(int i = x; i < n; ++i)
#define rep(i,n) REP(i,0,n)
/////////
#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const int MOD = (int)1e9+7;
const LL LINF = (LL)1e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;
/////////
#pragma region Math
#pragma region
template<class T>
inline T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
//inline T gcd(T a, T b){return b == 0 ? a : gcd(b, a % b);}
#pragma endregion // 最大公約数 gcd
#pragma region
template<class T>
inline T lcm(T a, T b){return a / gcd(a, b) * b;}
//inline T lcm(T a, T b){return a * b / gcd(a, b);}
#pragma endregion // 最小公倍数 lcm
#pragma region
LL powMod(LL num,int n,LL mod=(LL)MOD){
	if( n == 0 ){
		return (LL)1;
	}
	LL mul = num;
	LL ans = (LL)1;
	while(n){
		if( n&1){
			ans = (ans*mul)%mod;
		}
		mul = (mul*mul)%mod;
		n >>= 1;
	}
	return ans;
}
#pragma endregion //繰り返し二乗法 powMod
#pragma region
template<class T>
vector<T> getDivisor(T n){
	vector<T> v;
	for(int i=1;i*i<=n;++i){
		if( n%i == 0 ){
			v.push_back(i);
			if( i != n/i ){//平方数で重複して数えないように
				v.push_back(n/i);
			}
		}
	}
	sort(v.begin(), v.end());
	return v;
}
#pragma endregion //約数列挙 getDivisor(n):O(√n)
#pragma endregion //math
#pragma region
template<class T>
void UNIQUE(vector<T>& vec){
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end() );
}
#pragma endregion // sort erase unique
////////////////////////////////
#pragma region 
long long  bitcount64(long long bits)
{
    bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
    bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
    bits = (bits & 0x0000ffff0000ffff) + (bits >>16 & 0x0000ffff0000ffff);
    return (bits & 0x00000000ffffffff) + (bits >>32 & 0x00000000ffffffff);
}
#pragma endregion //その他
////////////////////////////////
struct edge_base{int to;LL cost;};
edge_base make_edge_base(int to,LL cost){
	edge_base ret = {to,cost};
	return ret;
}
#pragma region GRL
#pragma region //グラフ
template<class T,class EDGE>
void dijkstra(int root,int V,vector<T>& dist,
	vector< vector<EDGE> > G	){
	priority_queue<pair<T,int>,vector<pair<T,int> >,greater<pair<T,int> > > que;
	dist.assign(V,LINF);
	dist[root] = 0;
	que.push(pair<T,int>(0,root));//距離、頂点番号

	while( !que.empty() ){
		pair<T,int> p = que.top();que.pop();
		int v = p.second;
		if( dist[v] < p.first ) continue;
		for(int i=0;i < (int)G[v].size();++i){
			EDGE e = G[v][i];
			if( dist[e.to] > dist[v] + e.cost ){
				dist[e.to] = dist[v] + e.cost;
				que.push(pair<T,int>(dist[e.to],e.to));
			}
		}
	}
}
#pragma endregion //ダイクストラ法:O(|E|log|V|)
#pragma region //グラフ
void warshall_floyd(vector<vector<LL> >& dist,int V,const LL INF=LINF){
	for(int k=0;k<V;++k){
		for(int i=0;i<V;++i){
			if( dist[i][k] >= INF ) continue;
			for(int j=0;j<V;++j){
				if( dist[k][j] >= INF )continue;
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
#pragma endregion //ワーシャルフロイド:O(|V|**3)
#pragma region
namespace FLOW{
//vector< vector<FLOW:edge> > G;

struct edge_flow : public edge_base{
	int cap;
	int rev;
};
edge_flow make_edge_flow(int to,int cap,int rev,LL cost=1){
	edge_flow ret;
	
	ret.to = to;
	ret.cost = cost;
	ret.cap = cap;
	ret.rev = rev;
	return ret;
}
class Graph{
public:
	int V;
	vector< vector<FLOW::edge_flow> > G;
	vector< LL > dist;
	vector< int > iter;
	void init(int v){
		V = v;
		G.resize(V);
	}
	//directed graph
	void add_edge(int from,int to,int cap){
		G[from].push_back( FLOW::make_edge_flow(to,cap,G[to].size()) );
		G[to].push_back( FLOW::make_edge_flow(from,0,G[from].size()-1) );
	}
	
private:
	//sから最短距離をBFSで計算する
	void bfs(int s){//許容量もチェックしている
		queue<int> que;
		dist = vector<LL>(V,-1);
		dist[s] = 0;
		que.push(s);
		while(!que.empty()){
			int v = que.front();que.pop();
			for(int i=0;i<(int)G[v].size();++i){
				edge_flow &e = G[v][i];
				if( e.cap > 0 && dist[e.to] < 0 ){
					dist[e.to] = dist[v] + 1;
					que.push(e.to);
				}
			}
		}
	}
private:
	//増加パスをDFSで探す
	int dfs(int v,int t,int f){
		if( v==t ) return f;
		for(int &i = iter[v];i<(int)G[v].size();++i){//?
			FLOW::edge_flow &e = G[v][i];
			if( e.cap>0 && dist[v] < dist[e.to]){
				int d = this->dfs(e.to, t, min(f,e.cap) );
				if( d > 0){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
public:
	//sからtへの最大流量を求める
	int max_flow(int s,int t){
		int flow = 0;
		for(;;){
			this->bfs(s);
			if( dist[t] < 0 ) return flow;
			iter = vector<int>(V,0);
			int f;
			while( (f = this->dfs(s,t,INF) ) > 0 ){
				flow += f;
			}
		}
	}
};

}
#pragma endregion //dinic :O(|E||V|^2)
#pragma region //グラフ
bool is_bipartite(int v,int c,vector< vector<int> >& G,vector<int>& Color){
	Color[v] = c;
	for(int i=0;i < (int)G[v].size();++i){//隣接グラフ
		if(Color[ G[v][i] ] == c ) return false;
		if(Color[ G[v][i] ] == 0 && 
			!is_bipartite(G[v][i],-c,G,Color)
			){
				return false;
		}
	}
	return true;
}
bool is_bipartite(int Root,vector< vector<int> >& Graph){
	int GraphSize = Graph.size();
	vector<int> Color(GraphSize,0);
	const int ColorNo = 1;
	return is_bipartite(Root,ColorNo,Graph,Color);
}
#pragma endregion //二部グラフチェック is_bipartite(root,GraphList)
#pragma endregion //
#pragma region 
//http://sugarknri.hatenablog.com/entry/2016/07/16/165715
//LL inv[1000010];
void makeinv(vector<LL>& inv,const LL P){
	int i;
	const int varMAX = 100000;
	inv = vector<LL>( varMAX+1,0);
	inv[1]=1;
	for(i=2;i<=varMAX;i++){
		inv[i] = inv[P%i] * (P-P/i)%P;//OVF
	}
}

ULL nCk(ULL N,ULL k){
	static vector<LL> inv;
	if( inv.size() == 0 ){
		makeinv(inv,MOD);
	}
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
vector< vector<LL> > NCK;
LL nCk_base(int N,int K){
	K = min(K,N-K);
	if( K==0 ){return 1;}
	if( K==1 ){return N%MOD;}
	if( NCK[N][K] ){
		return NCK[N][K];
	}
	NCK[N][K] = (nCk_base(N-1,K)+nCk_base(N-1,K-1) )%MOD;
	return NCK[N][K];
}
#pragma region CGL
class Point{
public:
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}

	Point	operator +	(Point p){return Point(add(x,p.x),add(y,p.y));}
	void	operator +=	(Point p){x=add(x,p.x);y=add(y,p.y);}
	Point	operator -	(Point p){return Point(add(x,-p.x),add(y,-p.y));}
	void	operator -=	(Point p){x=add(x,-p.x);y=add(y,-p.y);}
	Point	operator *	(double a){return Point(x*a,y*a);}
	double	operator *	(Point p){return dot(p);}
	Point	operator /	(double a){return Point(x/a,y/a);}

	double norm(){return sqrt(x*x+y*y);}
	double dot(Point p){return add(x*p.x,y*p.y);}
	double rot(Point p){return add(x*p.y,-y*p.x);}
	double add(double a,double b){
		double EPS = 1e-10;
		if( abs(a+b) < EPS*(abs(a)+abs(b)) ){
			return 0;
		}
		return a+b;
	}
};
istream& operator>>(istream& in,Point& P){
	in >> P.x >> P.y;
	return in;
}

//線分で表した直線の交差判定
bool is_cross(Point p1,Point p2,Point q1,Point q2){
	double res = (p2-p1).rot(q2-q1);
	return  res != 0;//平行なら0
}

//線分p1-p2上に点qがあるか判定
bool on_seg(Point p1,Point p2,Point q){
	return (p1-q).rot(p2-q) == 0 && (p1-q).dot(p2-q) <= 0;
}
//直線p1-p2と直線q1-q2の交点
Point intersection(Point p1,Point p2,Point q1,Point q2){
	return p1+(p2-p1)*((q2-q1).rot(q1-p1)/(q2-q1).rot(p2-p1));
}

//線分p1-p2,と線分q1-q2の交差判定
//端点はfalse
//line segment:線分
bool LSI(Point p1,Point p2,Point q1,Point q2){
	if( (p2-p1).rot(q1-p1) * (p2-p1).rot(q2-p1) < 0 ){
		if( (q2-q1).rot(p1-q1) * (q2-q1).rot(p2-q1) < 0 ){
			return true;
		}
	}
	return false;
}

//線分ABに対する点C
enum PointPotion{ON_SEGMENT,COUNTER_CLOCKWISE,ONLINE_BACK,CLOCKWISE,ONLINE_FRONT};
PointPotion ccw(Point A,Point B,Point C){
	B -= A;C -=A;
	if( B.rot(C) > 0 ) return COUNTER_CLOCKWISE;
	if( B.rot(C) < 0 ) return CLOCKWISE;
	if( B.dot(C) < 0 ) return ONLINE_BACK;
	if( B.norm() < C.norm() ) return ONLINE_FRONT;
	return ON_SEGMENT;
}
#pragma endregion //class Point
#pragma region DSL
#pragma region DSL
class UnionFind{
public:
	int cNum;//要素数
	vector<int> parent;
	vector<int> count;
	vector< vector<int> > GList;
	UnionFind(int n){
		cNum = n;
		parent = vector<int>(n);
		count = vector<int>(n,1);
		GList.resize(n);
		for(int i=0;i<n;++i){
			parent[i] = i;
			GList[i].push_back(i);
		}
	}
	int find(int x){
		if( parent[x] == x ){return x;}
		return parent[x] = find( parent[x] );
	}
	bool same(int x,int y){return find(x) == find(y);}
	int Count(int x){return count[find(x)];}
	void add(int x,int y){//union
		x = find(x);
		y = find(y);
		if( x==y )return;
		parent[x] = y;
		count[y] += count[x];
		if( GList[y].size() < GList[x].size() ){
			swap(GList[x],GList[y]);
		}
		GList[y].insert( GList[y].end(),
			GList[x].begin(),GList[x].end() );
	}
};
#pragma endregion //UnionFind
#pragma region DSL
class segment{
	int n;
	int OTHER_VAL;
	int NUM_NULL;
	vector< int > dat;
public:
	int getN(){return n;}
	void init(int size,int num=INF,int num_null=-1){//N:要素数,最大値
		OTHER_VAL = num;
		NUM_NULL = num_null;
		n = 2;
		while(n < size ){
			n <<= 1;
		}
		dat.assign(n<<1, OTHER_VAL );
	}
	void init(vector<int> vec,int size,int num=INF){
		OTHER_VAL = num;
		n = 2;
		while(n < size ){
			n <<= 1;
		}
		dat.assign(n<<1,OTHER_VAL );
		for(int i=0;i<size;++i){
			update(i,vec[i]);
		}
	}
	int SELECT(int L,int R){
		return min(L,R);
	}
	void update(int i,int x){
		i += n;
		while(i){
			dat[i] = SELECT(dat[i],x);
			i >>= 1;
		}
	}
	void update(int X,int Y,int VAL){
		//全体の範囲は閉区間、
		update(1,0,n-1,X,Y,VAL);
	}
private:
	void update(int t,int L,int R,int X,int Y,int VAL){
		//親から子へ進んでいく
		if( L == X && R == Y){
			dat[t] = VAL;
		}else{
			int mid = (L+R)/2;
			if( dat[t] != NUM_NULL ){//値の伝播
				dat[t*2+0] = dat[t];
				dat[t*2+1] = dat[t];
				dat[t] = NUM_NULL;
			}
			if( Y <= mid ){
				update(t*2+0,L,mid,X,Y,VAL);
			}else if( X > mid ){
				update(t*2+1,mid+1,R,X,Y,VAL);
			}else{
				update(t*2+0,L,mid,X,mid,VAL);
				update(t*2+1,mid+1,R,mid+1,Y,VAL);
			}
		}
	}
public:
	//query(a,b,0,0,n)//[a,b)半開区間
	int query(int a,int b){
		return query(a,b,1,0,n);//n==getNを使う
	}
private:
	int query(int a,int b,int k,int l,int r){
		if(r<=a || b<=l)return OTHER_VAL;//交差しない
		if(a<=l && r<=b && dat[k]!=NUM_NULL)return dat[k];

		int res = OTHER_VAL;
		int mid = (l+r)>>1;
		if( a < mid ) res = SELECT(res,query(a,b,k*2+0,l,mid) );
		if( mid < b ) res = SELECT(res,query(a,b,k*2+1,mid,r) );
		return res;
	}
};
#pragma endregion //segment tree
#pragma region DSL
class BITree{//1-index
	int N;
	vector<LL> bit;
public:
	BITree(int n){
		N = n;
		bit = vector<LL>(N+1,0);//1-index
	}
	void add(int a,int w){
		for(int i=a;i<=N;i += i & -i){
			bit[i] += w;
		}
	}
	LL sum(int a){//[1,a)の和
		LL ret = 0;
		for(int i=a; i > 0; i -= i & -i){
			ret += bit[i];
		}
		return ret;
	}
};
#pragma endregion //BIndexTree
#pragma endregion //

#pragma region
//辞書順で比較
bool cmp_x(const Point& p,const Point& q){
	if( p.x != q.x ) return p.x < q.x;
	return p.y < q.y;
}

//凸包を求める
vector<Point> convex_hull(vector<Point> ps,int n){
	sort(ps.begin(),ps.end(), cmp_x);
	int k = 0;//凸包の頂点数
	vector<Point> qs(n*2);//構築中の凸包
	//下側の凸包の作成
	for(int i=0;i<n;++i){
		while(k>1 && (qs[k-1]-qs[k-2]).rot(ps[i]-qs[k-1]) <=0){
			k--;
		}
		qs[k++] = ps[i];
	}
	//上側凸包の作成
	for(int i=n-2,t=k;i>=0;i--){
		while(k>t && (qs[k-1]-qs[k-2]).rot(ps[i]-qs[k-1]) <=0){
			k--;
		}
		qs[k++] = ps[i];
	}
	qs.resize(k-1);
	return qs;
}
#pragma endregion //凸包
#pragma region 
template<class T,class U>
istream& operator>>(istream& in,pair<T,U>& P){
	in >> P.first >> P.second;
	return in;
}
#pragma endregion //cin pair<T,U>

#pragma region 
//行列の積
template<class T>
vector< vector<T> > operator*( vector<vector<T> >& A,vector< vector<T> >& B){
	LL mod = MOD;
	int R = A.size();
	int cen = A[0].size();
	int C = B[0].size();
	vector< vector<T> > ans(R,vector<T>(C,0) );
	for(int row=0;row<R;++row){
		for(int col=0;col<C;++col){
			for(int inner=0;inner< cen;++inner){
				ans[row][col] = (ans[row][col] + A[row][inner]*B[inner][col])%mod;
				//ans[row][col] = (ans[row][col] + A[row][inner]*B[inner][col]);
			}
		}
	}
	return ans;
}

template<class T>
vector< vector<T> > powMod(vector< vector<T> > mat,LL N){
	int R = mat.size();
	int C = mat[0].size();
	//R==C
	vector< vector<T> > I(R,vector<T>(C,0));//単位元
	for(int i=0;i<R && i<C;++i){
		I[i][i] = 1;
	}
	if( N == 0 ){
		return I;
	}
	vector< vector<T> > mul(R,vector<T>(C)),ans(R,vector<T>(C));
	ans = I;
	mul = mat;
	while(N){
		if( N & 1 ){
			ans = ans*mul;
		}
		N >>= 1;
		mul = mul*mul;
	}
	return ans;
}
#pragma endregion //行列

#pragma region
namespace TIME{
time_t start,limit;
void time_start(){start = time(NULL);}
void time_set(int num){limit = num;}//秒
bool check(){return (time(NULL)-start < limit);}
}
#pragma endregion //時間計測
#pragma region
namespace RAND{
mt19937 mt;
void rand_init(){
	random_device rnd;
	mt = mt19937(rnd());
}
int rand(){
	return mt();
}
}
#pragma endregion //乱数
#pragma region
#pragma endregion //
////////////////////

vector< pair<int,int> > factorize(int n){
	vector< pair<int,int> > v;
	if( n%2 == 0 ){
		int num = 0;
		while(n%2 == 0 ){
			++num;
			n/=2;
		}
		v.push_back( pair<int,int>(2,num) );
	}
	for(int i=3;i*i<=n;i+=2){
		int num = 0;
		while( n%i == 0 ){
			++num;
			n /= i;
		}
		if( num ){
			v.push_back( pair<int,int>(i,num) );
		}
	}
	if( n != 1 ){
		v.push_back( pair<int,int>(n,1) );
	}
	return v;
}
void solve(){
	int N,M;
	cin >> N >> M;
	bool neg = false;
	if( N < 0 ){
		neg = true;
		N = -N;
	}
	
	int n = N;
	LL res = 1;
	for(int i=2;i*i<=n;++i){
		int num = 0;
		if( n%i == 0 ){
			while(n%i==0){
				n/=i;
				++num;
			}
			LL temp = nCk(M+num-1,num);
			res = (res*temp)%MOD;
		}
	}
	if( n != 1){
		res = (res*M)%MOD;
	}

	LL res2=powMod(2,M-1);
	/*
	if( neg ){
		for(int i=1;i<=M;i+=2){
			res2 = (res2 + nCk(M,i) ) % MOD;
		}
	}else{
		for(int i=0;i<=M;i+=2){
			res2 = (res2 + nCk(M,i) ) % MOD;
		}
	}*/
	cout << (res*res2)%MOD << endl;
}

#pragma region main
signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	
	
	solve();
}
#pragma endregion //main()