#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;

template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll v):v(normS(v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll u[]={a,1,0},v[]={b,0,1};
		while(*v){
			ll t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	ModInt inv() const{
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<998244353>;

typedef long long ll;
int N;
ll x[2000],y[2000];
ll gcd(ll x,ll y){
	if(y==0) return abs(x);
	return gcd(y,x%y);
}
using T = tuple<ll,ll,ll>;
map<T,int> cnt;
map<int,int> c2i;

mint p2[2001];

int main(){
	cin>>N;
	p2[0] = 1;
	rep1(i,N) p2[i] = p2[i-1]*2;
	for(int i=2;i<=N;i++){
		int x = i*(i-1)/2;
		c2i[x] = i;
	}
	rep(i,N) cin>>x[i]>>y[i];
	rep(i,N) rep(j,i){
		ll a = y[i]-y[j];
		ll b = x[j]-x[i];
		ll c = y[i]*x[j]-y[j]*x[i];
		ll g = gcd(a,gcd(b,c));
		if(a<0 || (a==0&&b<0)) g*=-1;
		a/=g,b/=g,c/=g;
		cnt[T(a,b,c)]++;
	}
	mint ans = p2[N];
	for(auto it:cnt){
		int n = c2i[it.sc];
		ans -= p2[n]-n-1;
	}
	ans -= N+1;
	cout<<ans<<endl;
}
