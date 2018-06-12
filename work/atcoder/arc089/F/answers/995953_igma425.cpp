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
using mint = ModInt<1000000007>;

const int MN=70;
const int MK=70;
mint Co[1000][1000];
mint C(int a,int b){
	assert(0<=b&&b<=a);
	return Co[a][b];
}
mint dp[MN+1][MN+1][MN+1]={};	//phase, the num of component already put, the sum of len (!!excluding y as!!)
mint calc(int N,int x,int y,vector<int> canuse){		//x:the num of ab~ y:the num of a
	rep(i,MN+1) rep(j,MN+1) rep(k,MN+1) dp[i][j][k] = 0;
//	printf("x=%d,y=%d\n",x,y);
	if(x==0&&y==0) return 1;
	dp[0][0][0]=1;		//put y as
	int I=(N+1)/2;
	int J=x;
	int S=N-2*y-x+1;
	// show(I);
	// show(J);
	// show(S);
	rep(i,I){
		rep(j,J+1){
			rep(s,S+1){
				for(int k=0;j+k<=J && s+k*(i*2+1)<=S;k++){
					if(k>0&&canuse[j+k-1]<(s-j)/2+i*k) break;
					dp[i+1][j+k][s+k*(i*2+1)]+=dp[i][j][s]*C(j+y+k,k);
				}
			}
		}
	}
	mint ret=0;
	rep(s,S+1){
		ret+=dp[I][x][s]*C(N+2*x+1,s+3*x+2*y);
	}
//	show(ret);
	return ret;
}
mint solve(int N,string s){
	rep(i,1000){
		Co[i][0]=Co[i][i]=1;
		for(int j=1;j<i;j++) Co[i][j]=Co[i-1][j-1]+Co[i-1][j];
	}
	int K=s.size();
	vector<int> as;
	rep(i,K) if(s[i]=='r') as.pb(i);
	mint ans=0;
	rep(x,N+1) rep(y,N+1){
		bool used[MK]={};
		int bid[MN]={};
		bool OK=1;
		if(x+y>as.size()) continue;
		rep(i,x){
			used[as[i]]=1;
			bool ok=0;
			for(int j=as[i]+1;j<K;j++) if(s[j]=='b'&&!used[j]){
				bid[i]=j;
				used[j]=1;
				ok=1;
				break;
			}
			if(!ok){
				OK=0;
				break;
			}
		}
		if(!OK) continue;
		rep(i,y) used[as[x+i]]=1;
		vector<int> lefts;
		int imos[MK+1]={};
		rep(i,K) imos[i+1]=imos[i]+(!used[i]);
		rep(i,x) lefts.pb(imos[K]-imos[bid[x-i-1]]);
		ans+=calc(N,x,y,lefts);
	}
	return ans;
}

typedef vector<int> vi;
set<vi> st,nst;
mint brute(int N,string s){
	vi be(N);
	st.insert(be);
	for(char c:s){
		int x=(c=='r'?1:2);
		for(vi v:st){
			rep(l,N) for(int r=l;r<N;r++){
				vi nv=v;
				bool ok=1;
				for(int i=l;i<=r;i++){
					if(v[i]==0&&x==2){
						ok=0;
						break;
					}
					nv[i]=x;
				}
				if(ok) nst.insert(nv);
			}
			nst.insert(v);
		}
		st=nst;
		nst.clear();
	}
	return st.size();
}

int main(){
	int N,K;
	string s;
	cin>>N>>K>>s;

	cout<<solve(N,s)<<endl;
//	show(brute(N,s));
}