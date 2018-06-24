// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a);i<_b;++i)
#define ROF(i,b,a) for(int _a=(a),i=(b);i>_a;--i)
#define REP(n) for(int _n=(n);_n--;)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue<T>
#define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
#define IO(){ios_base::sync_with_stdio(0);cin.tie(0);}
#define nl '\n'
#define cint1(a) int a;cin>>a
#define cint2(a,b) int a,b;cin>>a>>b
#define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int>VI;typedef vector<LL>VL;typedef vector<PII>VP;
template<class A,class B>inline bool mina(A &x,const B &y){return(y<x)?(x=y,1):0;}
template<class A,class B>inline bool maxa(A &x,const B &y){return(x<y)?(x=y,1):0;}

template<class Int, Int mod>
class ModInt {
public:
	Int x;
	ModInt(): x(0) {}
	ModInt(int a, bool m=1) { if(m) {x=a%mod; if(x<0)x+=mod;} else x=a; }
	ModInt(LL  a, bool m=1) { if(m) {x=a%mod; if(x<0)x+=mod;} else x=a; }
	inline ModInt &operator+=(ModInt that) { if((x += that.x) >= mod) x -= mod; return *this; }
	inline ModInt &operator-=(ModInt that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	inline ModInt &operator*=(ModInt that) { x = LL(x) * that.x % mod; return *this; }
	inline ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
	inline ModInt operator-() const { return ModInt(-this->x); }
	ModInt inverse() const {LL a=x,b=mod,u=1,v=0;while(b){LL t=a/b;a-=t*b;u-=t*v;swap(a,b);swap(u,v);} return ModInt(u);}
	inline friend ostream& operator << (ostream &out, ModInt m) {return out << m.x;}

#define op(o1,o2) ModInt operator o1(ModInt that) const { return ModInt(*this) o2 that; }
	op(+,+=) op(-,-=) op(*,*=) op(/,/=)
#undef op
#define op(o) bool operator o(ModInt that) const { return x o that.x; }
	op(==) op(!=) op(<) op(<=) op(>) op(>=)
#undef op
};

const int moder = 1e9+7;
typedef ModInt<int,moder> Mint;

#define MAXN (300005)

Mint F[MAXN];
Mint FI[MAXN];

Mint Cnr(int n, int r)
{
	if(r < 0 || r > n) return 0;
	return F[n] * FI[r] * FI[n-r];
}

int main()
{
	IO();
	F[0] = 1;
	FOR(i,1,MAXN) F[i] = F[i-1] * i;
	FI[MAXN-1] = F[MAXN-1].inverse();
	ROF(i,MAXN-2,-1) FI[i] = FI[i+1] * (i+1);

	cint2(H,W);
	cint2(A,B);

	Mint sol;
	FOR(i,B+1,W+1) sol += Cnr(i-1+H-A-1, i-1) * Cnr(A-1+W-i, A-1);

	cout << sol << nl;

	return 0;
}