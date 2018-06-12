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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

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
using mint = ModInt<1000000007>;

const int MX = 10010;

mint f[MX],g[MX],inv[MX];
void precalc(){
	f[0]=1;
	rep1(i,MX-1) f[i] = f[i-1] * i;

	const int mod = 1e9+7;
	inv[1]=1;
	for(int i=2;i<=MX-1;i++) inv[i] = -inv[mod%i] * (mod/i);

	g[0]=1;
	rep1(i,MX-1) g[i] = g[i-1] *inv[i];
}
mint C(int x,int y){
	if(y<0 || x<y) return 0;
	return f[x]*g[y]*g[x-y];
}

int N;
vector<vector<int>> G;
int sz[5010];
vector<int> center;
void dfs(int v,int p=-1){
	for(int u:G[v]) if(u!=p) dfs(u,v);
	sz[v] = 1;
	bool isc = 1;
	for(int u:G[v]) if(u!=p){
		sz[v] += sz[u];
		if(sz[u]>N/2) isc = 0;
	}
	if(N-sz[v]>N/2) isc = 0;
	if(isc) center.pb(v);
}
mint dp[5010][5010];
int main(){
	precalc();
	cin>>N;
	G.resize(N);
	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	dfs(0);
	if(center.size()==2){
		mint ans = f[N/2]*f[N/2];
		cout<<ans<<endl;
		return 0;
	}
	assert(center.size()==1);
	int c = center[0];
	dfs(c);
	vector<int> ns;
	for(int u:G[c]) ns.pb(sz[u]);
	int K = ns.size();
//	show(ns);
	dp[0][1] = 1;
	rep(i,K){
		int n = ns[i];
		rep(x,N+1) if(dp[i][x]){
			rep(j,n+1){
				if(j%2==0) dp[i+1][x+n-j] += dp[i][x] * C(n,j)*f[n]*g[n-j];
				if(j%2==1) dp[i+1][x+n-j] -= dp[i][x] * C(n,j)*f[n]*g[n-j];
			}
		}
	}
	mint ans = 0;
	rep(x,N+1) ans += dp[K][x] * f[x];
	cout<<ans<<endl;
}
