#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=998244353;

ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
template <int mod=MOD> struct modInt{
  int v;
  modInt(int v=0):v(v){}
  modInt operator+(const modInt &n){return v+n.v<mod ? v+n.v : v+n.v-mod;}
  modInt operator-(const modInt &n){return v-n.v<0 ? v-n.v+mod : v-n.v;}
  modInt operator*(const modInt &n){return ll(v)*n.v%mod;}
  modInt operator/(const modInt &n){return ll(v)*modpow(n.v%mod,-1,mod)%mod;}
  modInt operator+(const ll &n){return v+n<mod ? v+n : v+n-mod;}
  modInt operator-(const ll &n){return v-n<0 ? v-n+mod : v-n;}
  modInt operator*(const ll &n){return ll(v)*(n%mod)%mod;}
  modInt operator/(const ll &n){return ll(v)*modpow(n%mod,-1,mod)%mod;}
  modInt& operator+=(const modInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const modInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const modInt &n){v=ll(v)*n.v%mod; return *this;}
  modInt& operator/=(const modInt &n){v=ll(v)*modpow(n.v,-1,mod)%mod; return *this;}
  modInt& operator+=(const ll &n){v+=n; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const ll &n){v-=n; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const ll &n){v=ll(v)*n%mod; return *this;}
  modInt& operator/=(const ll &n){v=ll(v)*modpow(n,-1,mod)%mod; return *this;}
};
template<int mod> ostream& operator<<(ostream &os,const modInt<mod> &n){return os<<n.v;};
template<int mod> modInt<mod> operator+(const ll &n,const modInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<int mod> modInt<mod> operator-(const ll &n,const modInt<mod> &m){return n-m.v<0 ? n-m.v+mod : n-m.v;}
template<int mod> modInt<mod> operator*(const ll &n,const modInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<int mod> modInt<mod> operator/(const ll &n,const modInt<mod> &m){return ll(m.v)*modpow(n%mod,-1,mod)%mod;}
typedef modInt<MOD> mint;
template <int mod> modInt<mod> modpow(modInt<mod> r,ll n){ modInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}
vector<mint> fact,finv,inv;


int solve(bitset<4000> x,int n,
					 bitset<4000> a,int m){
	rrep(i,4000){
		if(a[i] && !x[i]) return 1;
		if(!a[i] && x[i]) break;
	}
	if(n<m) return 1;
	//rrep(j,20)cout<<x[j];cout<<endl;
	ll re=0;
	bitset<4000> sum; sum.reset();
	rreps(i,m,n){
		(re*=2)%=MOD;
		if(x[i]) (re+=1)%=MOD;
		if(x[i]!=sum[i]) sum^=a<<(i-m+1);
	}
	(re*=2)%=MOD;
	rep(_,2){
		int ok=1;
		// rrep(j,20)cout<<sum[j];cout<<endl;
		// rrep(j,20)cout<<x[j];cout<<endl;
		rrep(i,4000){
			if(i>=m) assert(x[i]==sum[i]);
			if(sum[i] && !x[i]){ ok=0; break;}
			if(!sum[i] && x[i]){ break;}
		}
		// out(ok,1);
		if(ok) (re+=1)%=MOD;
		sum^=a;
	}
	//out(re,ret,1);
	return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
	string x;
	cin>>n>>x;
	vector<pair<bitset<4000>,int>> as(n);
	rep(i,n){
		string s;
		cin>>s;
		as[i].Y=s.size();
		as[i].X.reset();
		rep(j,s.size()) as[i].X[j]=(s[s.size()-1-j]-'0');
	}
	// rep(i,as.size()){rrep(j,20)cout<<as[i].X[j];cout<<endl;}cout<<endl;
	while(as.size()>1){
		sort(rall(as),[&](auto &l,auto &r){
				return l.Y<r.Y;
			});
		while(1){
			int upd=0;
			rep(i,as.size())rep(j,i)if(as[i]==as[j]){
				as.erase(as.begin()+j);
				upd=1;
				break;
			}
			rep(i,as.size())if(as[i].Y==0){
				as.erase(as.begin()+i);
				upd=1;
			}
			if(!upd) break;
		}
		while(as.size() && as.back().Y==0) as.pop_back();
		if(as.size()<=1) break;
		as[0].X^=as[1].X<<(as[0].Y-as[1].Y);
		as[0].Y=0;
		rep(i,4000){
			if(as[0].X[i]) as[0].Y=i+1;
		}
	}
	// rep(i,as.size()){rrep(j,20)cout<<as[i].X[j];cout<<","<<as[i].Y<<endl;}cout<<endl;
	assert(as.size()==1);
	
	bitset<4000> st; st.reset();
	rep(j,x.size()) st[j]=(x[x.size()-1-j]-'0');
	cout<<solve(st,x.size(),as[0].X,as[0].Y)<<endl;
  return 0;
}
