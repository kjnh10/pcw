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
	Poly operator*(const Poly &r) const{
		int N=size(),M=r.size();
		if(N==0||M==0) return Poly();
		vector<D> ret(N+M-1);
		rep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);
		return Poly(ret);
	}
	Poly operator*(const D &r) const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i]=v[i]*r;
		return Poly(ret);
	}
	Poly operator%(const Poly &y) const{
		Poly x = *this;
		while(y.size()<=x.size()){
			int N=x.size(),M=y.size();
			D coef = x.v[N-1]/y.v[M-1];
			x -= (y<<(N-M))*coef;
		}
		return x;
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

	Poly& operator+=(const Poly &r) {return *this = *this+r;}
	Poly& operator-=(const Poly &r) {return *this = *this-r;}
	Poly& operator*=(const Poly &r) {return *this = *this*r;}
	Poly& operator*=(const D &r) {return *this = *this*r;}
	Poly& operator%=(const Poly &y) {return *this = *this%y;}
	Poly& operator<<=(const int &n) {return *this = *this<<n;}
	Poly& operator>>=(const int &n) {return *this = *this>>n;}

	friend ostream& operator<<(ostream &o,const Poly& x){
//		o<<x.size();
//		o<<x.v[0];
		if(x.size()==0) return o<<0;
		rep(i,x.size()) if(x.v[i]!=D(0)){
			o<<x.v[i]<<"x^"<<i;
			if(i!=x.size()-1) o<<" + ";
		}
		return o;
	}
};

/*
template<class D>
string to_string(const Poly<D> &p){
	if(p.size()==0) return "0";
	string s="";
	rep(i,p.size()) if(p.v[i]!=D(0)){
		s += to_string(p.v[i])+"x^"+to_string(i);
		if(i!=p.size()-1) s+=" + ";
	}
	return s;
}
*/

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
		if(N%2) (a*=x)%=mod;
		x*=x;
		x%=mod;
		N/=2;
	}
	mint ans=0;
	rep(i,K) ans+=a.at(i);
	cout<<ans<<endl;
}
