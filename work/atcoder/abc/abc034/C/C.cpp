using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define infile "./test/sample-1.in"
// {{{ define basic macro
#define rep(i, x) for(int i = 0; i < (int)(x); i++)
#define reps(i,x) for(int i = 1; i <= (int)(x); i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i >= n;i--)
#define foreach(x,a) for(auto& (x) : (a) )
#define all(x) (x).begin(),(x).end()
#define sum(v) accumulate(all(v), 0)
#define sz(x) ((int)(x).size())
// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
#define fill(x,y) memset(x,y,sizeof(x))
#define pb(a) push_back(a)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ten(n) ((int)1e##n)

template <class T = int>
T in() {T x; cin>>x; return (x);}

struct Fast {
  Fast(){
    std::cin.tie(0);
    ios::sync_with_stdio(false);
  }
} fast;
// }}}

// dump macro{{{
// http://www.creativ.xyz/dump-cpp-652
#define DUMPOUT cerr // 変数ダンプ先。coutかcerr

#ifdef PCM
// 引数はいくつでもどんな型でも可（ストリーム出力演算子があればOK）
#define dump(...) DUMPOUT<<"  "; \
  DUMPOUT<<#__VA_ARGS__; \
  DUMPOUT<<":=> "; \
  dump_func(__VA_ARGS__); DUMPOUT<<"in ["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;
#define dump_1d(x,n) DUMPOUT <<"  " \
  <<#x<<"["<<#n<<"]"<<":=> {"; \
  rep(i,n){ DUMPOUT << x[i] << (((i)==(n-1))?"}":", "); } DUMPOUT <<" in [" << __LINE__ << "]" << endl;

#define dump_2d(x,n,m) DUMPOUT <<"  " \
    <<#x<<"["<<#n<<"]"<<"["<<#m<<"]"<<":=> \n"; \
    rep(i,n)rep(j,m){ DUMPOUT << ((j==0)?"     |":" ") << x[i][j] << (((j)==(m-1))?"|\n":" "); } \
    DUMPOUT <<"  in [" << __LINE__ << "]" << endl;
#else
#define dump(...) 42
#define dump_1d(...) 42
#define dump_2d(...) 42
#endif

// デバッグ用変数ダンプ関数
void dump_func() {
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail)
{
    DUMPOUT << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    }
    else {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
    os << "{";
    for (int i = 0; i<sz(vec); i++) {
        os << vec[i] << (i + 1 == sz(vec) ? "" : ", ");
    }
    os << "}";
    return os;
}/*}}}*/

typedef long long ll;/*{{{*/
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;
typedef tuple<int,int,int> iii;
typedef set<int> si;
typedef complex<double> pnt;
typedef vector<pnt> vpnt;
typedef priority_queue<pii,vii,greater<pii> > spq;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};/*}}}*/
#define INF 2147483647
#define INFLL 1000000000000000000LL
#define MOD 1000000007
#define int long long

// mod lib {{{
#define MOD 1000000007
#define MAX_P 200005
ll fact[MAX_P]; // fact[n]: n! (mod)
ll inv[MAX_P];  // inv[n]: n^(-1) in mod world
ll finv[MAX_P]; // finv[n]: (n!)^(-1) in mod world

void init(ll mod){
  fact[0]=1;
  for(ll i=1;i<MAX_P;i++)
    fact[i]=(fact[i-1]*i)%mod;

  inv[1]=1;
  for(ll i=2;i<MAX_P;i++)
    inv[i]=inv[mod%i]*(mod-mod/i)%mod;

  finv[0]=1;
  for(ll i=1;i<MAX_P;i++)
    finv[i]=finv[i-1]*inv[i]%mod;
}

ll extgcd(ll a,ll b,ll& x,ll& y){
  ll d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
ll mod_inverse(ll a,ll mod){  // ユークリッドの拡張互除法による逆元
  ll x,y;
  extgcd(a,mod,x,y);
  return (mod+x%mod)%mod;
}

ll mod_pow(ll x,ll n,ll mod){
  ll res=1;
  while(n){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}

ll mod_inverse2(ll a,ll mod){  // フェルマーの小定理による逆元
  return mod_pow(a,mod-2,mod);
}

ll mod_fact(ll n,ll mod,ll& e){
  e=0;
  if(n==0) return 1;
  ll res=mod_fact(n/mod,mod,e);
  e+=n/mod;
  if(n/mod%2!=0)return res*(mod-fact[n%mod]) %mod;
  return res*fact[n%mod]%mod;
}

ll mod_comb(ll n,ll k,ll mod){
  if(n==k||k==0) return 1;
  ll e1,e2,e3;
  ll a1=mod_fact(n,mod,e1),a2=mod_fact(k,mod,e2),a3=mod_fact(n-k,mod,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inverse(a2*a3%mod,mod)%mod;
}

ll mod_comb2(ll n,ll k,ll mod){
  ll res=1;
  for(ll i=0;i<k;i++){
    res*=(n-i)%mod;
    res%=mod;
    res*=mod_inverse(i+1,mod);
    res%=mod;
  }
  return res;
}

//only for prime mod
ll mod_comb3(ll n,ll k,ll mod){
  if(k<0||k>n) return 0;
  return fact[n]*finv[k]%mod*finv[n-k]%mod;
}

ll montmort(ll n,ll mod){
  ll res=0,inv=1;
  for(ll k=2;k<=n;k++){
    (inv*=mod_inverse(k,mod))%=mod;
    if(k%2) (res+=mod-inv)%=mod;
    else (res+=inv)%=mod;
  }
  for(ll i=1;i<=n;i++)
    (res*=i)%=mod;
  return res;
}

// calculate P(t) from given points in [0,N]
ll LagrangePolynomial(vector<ll> &y,ll t,const ll mod){
  init(mod);
  ll n=y.size()-1;
  ll num=1;
  for(ll i=0;i<=n;i++)
    num=num*((t-i)%mod)%mod;
  ll res=0;
  for(ll i=0;i<=n;i++){
    ll tmp=(y[i]*num%mod)*mod_inverse((t-i)%mod,mod)%mod;
    tmp=tmp*finv[i]%mod;
    tmp=tmp*finv[n-i]%mod;
    if((n-i)&1) tmp=mod-tmp;
    res=(res+tmp)%mod;
  }
  return res;
}
// }}}

int solve(){
  int h,w; cin>>h>>w;

  init(MOD);
  cout << mod_comb3(h+w-2, h-1, MOD) << endl;

  return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}
