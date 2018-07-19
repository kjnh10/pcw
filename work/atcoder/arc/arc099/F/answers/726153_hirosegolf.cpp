#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <assert.h>
#include <sys/time.h>
#include <fstream>
#include <iomanip>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define REP(i,n)  FOR(i,0,n)
#define each(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define EACH(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define deb(x) cerr << #x << " = " << (x) << " , ";
#define debl cerr << " (L" << __LINE__ << ")"<< endl;
#define sz(s) (int)((s).size())


#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizeof(a))
#define pb push_back
#define INRANGE(x,s,e) ((s)<=(x) && (x)<(e))
#define MP(x,y) make_pair((x),(y))

double pi=3.14159265358979323846;

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

template<typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& z){
	os << "[ ";
	REP(i,z.size())os << z[i] << ", " ;
	return ( os << "]" << endl);
}

template<typename T> std::ostream& operator<<(std::ostream& os, const set<T>& z){
	os << "set( ";
	EACH(p,z)os << (*p) << ", " ;
	return ( os << ")" << endl);
}

template<typename T,typename U> std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
	os << "{ ";
	EACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
	return ( os << "}" << endl);
}

template<typename T,typename U> std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
	return ( os << "(" << z.first << ", " << z.second << ",)" );
}

double get_time(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec*1e-6;
}

typedef unsigned int uint32_t;
struct RND{
	uint32_t x;
	uint32_t y;
	uint32_t z;
	uint32_t w;
	RND(){
		x=123456789;
		y=362436069;
		z=521288629;
		w=88675123;
	}
	void init(int seed){
		x=123456789;
		y=362436069;
		z=521288629;
		w=seed+100;
		REP(i,10)get();
	}
	uint32_t get(){
		uint32_t t;
		t=x^(x<<11);
		x=y;y=z;z=w;
		w=(w^(w>>19))^(t^(t>>8));
		return w;
	}
};
RND rnd;

ll mod=1LL<<58;
struct mint{
	ll value;
	mint():value(0){}
	mint(ll v):value((v%mod+mod)%mod){}
};
mint& operator+=(mint&a, mint b){return a=a.value+b.value;}
mint& operator-=(mint&a, mint b){return a=a.value-b.value;}
mint& operator*=(mint&a, mint b){return a=a.value*b.value;}
mint operator+(mint a, mint b){return a+=b;}
mint operator-(mint a, mint b){return a-=b;}
mint operator*(mint a, mint b){return a*=b;}
mint operator-(mint a){return 0-a;}
bool operator==(mint a, mint b){return a.value==b.value;}
bool operator!=(mint a, mint b){return a.value!=b.value;}


std::ostream& operator<<(std::ostream& os, const mint& m){
return ( os << m.value );}
ll extgcd(ll a, ll b, ll &x, ll &y){
	ll d=a;
	if(b!=0){
		d=extgcd(b, a%b, y, x);
		y-=(a/b)*x;
	}
	else{
		x=1,y=0;
	}
	return d;
}
ll modinverse(ll a, ll b){
	ll x,y;
	ll d=extgcd(a,b, x, y);
	assert(d==1);
	return (x%b+b)%b;
}
mint& operator/=(mint&a, mint b){return a=a.value*modinverse(b.value,mod);}
mint operator/(mint a, mint b){return a/=b;}

vector<mint> f;
vector<mint> pf;
mint X = 123456789;

void _main(istream &inp){
	int N;
	string S;
	inp >> N >> S;
	f = vector<mint>(N+1);
	pf = vector<mint>(N+1);
	mint val = 0;
	mint u=1;
	f[0]=val;
	pf[0] = u;
	rep(i,N){
		if(S[i]=='+')val += u;
		if(S[i]=='-')val -= u;
		if(S[i]=='>') u*=X;
		if(S[i]=='<')u/=X;
		f[i+1] = val;
		pf[i+1] = u;
	}
//	debug(f);
//	debug(pf);
	map<ll,ll> cnt;
	ll ret = 0;
	for(int i=N;i>=0; i-- ){
		ll tv = ( f[i] + pf[i]*f[N] ).value;
		if(exist(cnt, tv)){
			ret += cnt[tv];
		}
		cnt[f[i].value]+=1;
	}
	cout << ret << endl;
}

int main(){
	if(0){
		ifstream ifs("test.txt");
		_main(ifs);
	}
	else{
		_main(cin);
	}
	return 0;
}
