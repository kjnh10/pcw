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

struct mint{
	using ll = long long;
	const static ll mod=1000000007;
	ll a;
	mint():a(0){}
	mint(ll a):a((a%mod+mod)%mod){}
	mint& operator+=(const mint& b){ if((a+=b.a)>=mod) a-=mod; return *this;}
	mint& operator-=(const mint& b){ if((a+=mod-b.a)>=mod) a-=mod; return *this;}
	mint& operator*=(const mint& b){ (a*=b.a)%=mod; return *this;}
	mint operator+(const mint& b) const { return mint(*this)+=b;}
	mint operator-(const mint& b) const { return mint(*this)-=b;}
	mint operator*(const mint& b) const { return mint(*this)*=b;}
	mint operator-() const { return mint(-a); }
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
	mint inv() const{
		ll x,y;
		extgcd(a,mod,x,y);
		if(x<0) x+=mod;
		return mint(x);
	}
	mint& operator/=(const mint& b){ (*this)*=b.inv(); return *this; }
	mint operator/(const mint& b) const { return mint(*this)/=b;}
	bool operator==(const mint& b) const { return a==b.a;}
	bool operator!=(const mint& b) const { return a!=b.a;}
	friend istream& operator>>(istream &o,mint& x){
		ll tmp;
		o>>tmp;
		x=mint(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const mint& x){ return o<<x.a;}
};

typedef long long ll;
typedef pair<ll,ll> P;		//val,mod;
ll inv(ll a,ll m){
	ll b=m,u=1,v=0;
	while(b){
		ll t=a/b;
		swap(a-=t*b,b);
		swap(u-=t*v,v);
	}
	u%=m;
	if(u<0) u+=m;
	return u;
}
ll garner(vector<P> rm,ll mod){		//remainder,mod
	rm.pb(P(0,mod));
	int N=rm.size();
	vector<ll> as(N,1);		//coefficients
	vector<ll> bs(N,0);		//constants
	rep(i,N-1){
		ll v=(rm[i].fs-bs[i])*inv(as[i],rm[i].sc)%rm[i].sc;
		if(v<0) v+=rm[i].sc;
		for(int j=i+1;j<N;j++){
			(bs[j]+=as[j]*v)%=rm[j].sc;
			(as[j]*=rm[i].sc)%=rm[j].sc;
		}
	}
	return bs[N-1];
}

struct NTT{
	const int mod,g;
	NTT(int mod,int g) :mod(mod),g(g){}
	ll ex(ll x,ll p){
		ll a=1;
		while(p){
			if(p%2) a=a*x%mod;
			x=x*x%mod;
			p/=2;
		}
		return a;
	}
	ll inv(ll a){
		ll b=mod,u=1,v=0;
		while(b){
			ll t=a/b;
			swap(a-=t*b,b);
			swap(u-=t*v,v);
		}
		u%=mod;
		if(u<0) u+=mod;
		return u;
	}
	void ntt(vector<ll>& a,ll h){
		int N=a.size();
		for(int m=N;m>=2;m/=2){
			int mh=m/2;
			ll w=1;
			rep(i,mh){
				for(int j=i;j<N;j+=m){
					int k=j+mh;
					ll x=(a[j]-a[k]);
					a[j]+=a[k];
					if(a[j]>=mod) a[j]-=mod;
					a[k]=w*x%mod;
					if(a[k]<0) a[k]+=mod;
				}
				w=w*h%mod;
			}
			h=h*h%mod;
		}
		int i=0;
		rep1(j,N-2){
			for(int k=N/2;k>(i^=k);k/=2);
			if(j<i) swap(a[i],a[j]);
		}
	}
	vector<ll> conv(vector<ll> a,vector<ll> b){		// (mod-1)%N==0でないとだめ!!
		for(auto& x:a) x%=mod;
		for(auto& x:b) x%=mod;
		int n=a.size()+b.size();
		int N=1;
		while(N<n) N*=2;
		a.resize(N),b.resize(N);
		assert((mod-1)%N==0);
		ll h=ex(g,(mod-1)/N);
		ntt(a,h),ntt(b,h);
		rep(i,N) (a[i]*=b[i])%=mod;
		h=inv(h);
		ntt(a,h);
		h=inv(N);
		rep(i,N) (a[i]*=h)%=mod;
		return a;
	}
};

vector<ll> ms={167772161,469762049,1224736769},gs={3,3,3}; 
vector<mint> multiply_ntt(const vector<mint> &a_,const vector<mint> &b_){
	int mod = mint::mod;
	vector<ll> a(a_.size()),b(b_.size());
	rep(i,a.size()) a[i]=a_[i].a;
	rep(i,b.size()) b[i]=b_[i].a;
	vector<ll> vs[3];
	rep(i,3) vs[i]=NTT(ms[i],gs[i]).conv(a,b);
	int N=vs[0].size();
	vector<mint> ret(N);
	rep(i,N){
		vector<P> rm;
		rep(j,3) rm.pb(P(vs[j][i],ms[j]));
		ret[i]=garner(rm,mod);
	}
	return ret;
}

int bsr(int x) { return 31 - __builtin_clz(x); }
using R = double;
const R PI = 4*atan(R(1));
using Pc = complex<R>;

void fft(bool type, vector<Pc> &c) {
    static vector<Pc> buf[30];
    int N = int(c.size());
    int s = bsr(N);
    assert(1<<s == N);
    if (!buf[s].size()) {
        buf[s] = vector<Pc>(N);
        for (int i = 0; i < N; i++) {
            buf[s][i] = polar<R>(1, i*2*PI/N);
        }
    }
    vector<Pc> a(N), b(N);
    copy(begin(c), end(c), begin(a));
    for (int i = 1; i <= s; i++) {
        int W = 1<<(s-i); //変更後の幅W
        for (int y = 0; y < N/2; y += W) {
            Pc now = buf[s][y]; if (type) now = conj(now);
            for (int x = 0; x < W; x++) {
                auto l =       a[y<<1 | x];
                auto r = now * a[y<<1 | x | W];
                b[y | x]        = l+r;
                b[y | x | N>>1] = l-r;
            }
        }
        swap(a, b);            
    }
    copy(begin(a), end(a), begin(c));
}

template<class Mint>
vector<Mint> multiply_fft(vector<Mint> x, vector<Mint> y) {
    int S = x.size()+y.size()-1;
    int N = 2<<bsr(S-1);
    vector<Pc> a[3], b[3];
    for (int fe = 0; fe < 3; fe++) {
        a[fe] = vector<Pc>(N);
        b[fe] = vector<Pc>(N);
        for (int i = 0; i < int(x.size()); i++) {
            a[fe][i] = Pc((x[i].v >> (fe*10)) & ((1<<10)-1), 0);
        }
        for (int i = 0; i < int(y.size()); i++) {
            b[fe][i] = Pc((y[i].v >> (fe*10)) & ((1<<10)-1), 0);
        }
        fft(false, a[fe]);
        fft(false, b[fe]);
    }
 
    vector<Mint> z(S);
    vector<Pc> c(N);
    Mint base = 1;
    for (int fe = 0; fe < 5; fe++) {
        fill_n(begin(c), N, Pc(0, 0));
        for (int xf = max(fe-2, 0); xf <= min(2, fe); xf++) {
            int yf = fe-xf;
            for (int i = 0; i < N; i++) {
                c[i] += a[xf][i]*b[yf][i];
            }
        }
        fft(true, c);
        for (int i = 0; i < S; i++) {
            c[i] *= 1.0/N;
            z[i] += Mint(ll(round(c[i].real()))) * base;
        }
        base *= 1<<10;
    }
    return z;
}


template<class D>
struct Poly{
	vector<D> v;
	int size() const{ return v.size();}	//deg+1
	Poly(int N=0) : v(vector<D>(N)){}
	Poly(vector<D> v) : v(v){shrink();}

	Poly& shrink(){
		while(!v.empty()&&v.back()==D(0)) v.pop_back();	//double? iszeroをglobalに用意したほうがいいかな
		return *this;
	}
	D at(int i) const{
		return (i<size())?v[i]:D(0);
	}
	void set(int i,const D& x){		//v[i] := x
		while(i>=size()) v.push_back(D(0));
		v[i]=x;
		shrink();
		return;
	}

	Poly operator+(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)+r.at(i);
		return Poly(ret);
	}
	Poly operator-(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)-r.at(i);
		return Poly(ret);
	}
	Poly operator-() const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i] = -at(i);
		return Poly(ret);
	}

	Poly mul_naive(const Poly &r) const{
		int N=size(),M=r.size();
		vector<D> ret(N+M-1);
		rep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);
		return Poly(ret);
	}
	Poly mul_ntt(const Poly &r) const{
		return Poly(multiply_ntt(this->v,r.v));
	}
	Poly mul_fft(const Poly &r) const{
		vector<D> ret = multiply_fft(v,r.v);
		return Poly(ret);
	}
	Poly operator*(const Poly &r) const{
		if(size()==0||r.size()==0) return Poly();
		return mul_ntt(r);
	}
	Poly operator*(const D &r) const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i]=v[i]*r;
		return Poly(ret);
	}

	Poly div_fast_with_inv(const Poly &inv, int ysize) const {
		int B = inv.size()-1 + ysize-1;		//deg (g * g') = B
		return (*this * inv)>>B;
	}
	Poly div_fast(const Poly &y) const{
		if(size()<y.size()) return *this;
		int n = size();
		return div_fast_with_inv(y.inv(n),y.size());
	}
	Poly operator/(const Poly &y) const{
		return div_fast(y);
	}
	Poly rem_naive(const Poly &y) const{
		Poly x = *this;
		while(y.size()<=x.size()){
			int N=x.size(),M=y.size();
			D coef = x.v[N-1]/y.v[M-1];
			x -= (y<<(N-M))*coef;
		}
		return x;
	}
	Poly rem_fast(const Poly &y) const{
		return *this - y * div_fast(y);
	}
	Poly operator%(const Poly &y) const{
//		return rem_fast(y);
		return rem_naive(y);
	}

	Poly operator<<(const int &n) const{	// *=x^n
		assert(n>=0);
		int N=size();
		vector<D> ret(N+n);
		rep(i,N) ret[i+n]=v[i];
		return Poly(ret);
	}
	Poly operator>>(const int &n) const{	// /=x^n
		assert(n>=0);
		int N=size();
		if(N<=n) return Poly();
		vector<D> ret(N-n);
		rep(i,N-n) ret[i]=v[i+n];
		return Poly(ret);
	}
	bool operator==(const Poly &y) const{
		return v==y.v;
	}
	bool operator!=(const Poly &y) const{
		return v!=y.v;
	}

	Poly& operator+=(const Poly &r) {return *this = *this+r;}
	Poly& operator-=(const Poly &r) {return *this = *this-r;}
	Poly& operator*=(const Poly &r) {return *this = *this*r;}
	Poly& operator*=(const D &r) {return *this = *this*r;}
	Poly& operator%=(const Poly &y) {return *this = *this%y;}
	Poly& operator<<=(const int &n) {return *this = *this<<n;}
	Poly& operator>>=(const int &n) {return *this = *this>>n;}

	friend ostream& operator<<(ostream &o,const Poly& x){
		if(x.size()==0) return o<<0;
		rep(i,x.size()) if(x.v[i]!=D(0)){
			o<<x.v[i]<<"x^"<<i;
			if(i!=x.size()-1) o<<" + ";
		}
		return o;
	}
	Poly inv(int n) const{		// f * f.inv() = x^B + r(x) (B>=n)
//		show(*this);
//		show(n);
		int N = size();
		assert(N>=1);		//f : non0
		assert(n>=N-1);		//f = .. + c_{N-1}x^{N-1}
		D coef = D(1)/at(N-1);
		Poly g(vector<D>(1,coef));
		if(N==1){	//f = D(v)
			return g<<=n;
		}
		for(int d=N-1;d<n;d*=2){		//fg = x^d + ...
//			show(d);
//			show(g);
//			show(*this * g);
			Poly tmp = - (*this) * g;
			D c = D(2) + tmp.at(d);
			tmp.set(d,c);
//			show(tmp);
			g *= tmp;
//			puts("");
		}
//		show(g);
//		show(*this*g);
		return g;
	}
};

void test(){
	srand((unsigned)time(NULL));
	// Poly<mint> f({1,2,3});
	// Poly<mint> g(vector<mint>{1});
	// show(f);
	// show(g);
	// show(f/g);
	// show(f%g);
	// show((f%g)+f/g*g);
	rep(cnt,100){
		show(cnt);
		int N = rand()%5;
		int M = rand()%4+1;
		vector<mint> fv(N),gv(M);
		rep(i,N) fv[i]=rand()%(mint::mod);
		rep(i,M) gv[i]=rand()%(mint::mod);
		Poly<mint> f(fv),g(gv);
//		show(f);
//		show(g);
		Poly<mint> q=f/g,r=f%g;
		if(q*g+r!=f){
			show(f);
			show(g);
		}
	}
}

int main(){
	int K,N;
	cin>>K>>N;
	N--;
	Poly<mint> mod = [&](){
		vector<mint> v(K+1,-1);
		v[K]=1;
		return Poly<mint>(v);
	}();
	Poly<mint> a = vector<mint>{1};
	Poly<mint> x = vector<mint>{0,1};
	while(N){
//		show(N);
		if(N%2) (a*=x)%=mod;
		x*=x;
		x%=mod;
		N/=2;
	}
	mint ans=0;
	rep(i,K) ans+=a.at(i);
	cout<<ans<<endl;
}
