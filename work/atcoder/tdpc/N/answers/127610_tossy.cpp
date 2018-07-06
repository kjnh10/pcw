#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600
#define MOD 1000000007

// x^n mod p
long mod_pow(long x, long n, long p=MOD){
  long res=1;
  x %= p;
  while(n>0){
    if(n&1) res=res*x%p;
    x=x*x%p;
    n>>=1;
  }
  return res;
}
long mod_inv(long x, long p=MOD){ return mod_pow(x%p, p-2); }


int main(){
  int n;
  cin>>n;
  vector<int> a(n),b(n);
  vector<vector<int>> vec(n);
  rep(i,n-1){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
    vec[a[i]].pb(b[i]);
    vec[b[i]].pb(a[i]);
  }

  vector<long> fact(n+1), finv(n+1);
  fact[0] = 1;
  finv[0] = 1;
  rep(i,n) fact[i+1] = (i+1)*fact[i]%MOD;
  rep(i,n) finv[i+1] = mod_inv(fact[i+1]);

  // <pattern, #edge>
  function<pair<long,long>(int,int)> dfs = [&](int from, int d){
    long pt = 1;
    long ne = 0;
    for(auto to : vec[d]) if(to!=from){
      auto r = dfs(d, to);
      pt = pt*r.fi %MOD *finv[r.se] %MOD;
      ne += r.se;
    }
    pt = pt * fact[ne] % MOD;
    return mp(pt, ne+1);
  };

  long ans = 0;
  rep(i,n-1){
    auto r1 = dfs(a[i], b[i]); r1.se--;
    auto r2 = dfs(b[i], a[i]); r2.se--;
    long tmp = r1.fi * r2.fi %MOD * fact[r1.se+r2.se] %MOD * finv[r1.se] %MOD * finv[r2.se] %MOD;
    ans += tmp;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
