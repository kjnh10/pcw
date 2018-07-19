#include <cstdio>
#include <cstring>
#include <vector>

const int mod = 1000000007;

typedef long long int ll;

std::vector<int> g[1000];

constexpr int modpow(int x, int n){
  if(n == 0) return 1;
  int y = (ll) x * x % mod;
  if(n & 1) return (ll) x * modpow(y, n/2) % mod;
  else return modpow(y, n/2);
}

struct Table {
  constexpr Table(): fact(), ifact() {
    fact[0] = 1;
    for(int i=1;i<=1000;i++){
      fact[i] = (ll) i * fact[i-1] % mod;
    }
    ifact[1000] = modpow(fact[1000], mod-2);
    for(int i=999;i>=0;i--){
      ifact[i] = (ll) (i+1) * ifact[i+1] % mod;
    }
  }

  int fact[1001];
  int ifact[1001];
};

constexpr auto ftable = Table();

struct prop {
  int num;
  int val;
};

void dfs(int x, int p, prop &q){
  q.num=1;
  q.val=1;
  for(auto c: g[x]){
    if(c != p){
      prop cp;
      dfs(c, x, cp);
      q.val = (ll) q.val * ((ll) ftable.ifact[cp.num] * cp.val % mod) % mod;
      q.num += cp.num;
    }
  }
  q.val = (ll) q.val * ftable.fact[q.num-1] % mod;
}

int main(){
  int n, ans;

  scanf("%d", &n);
  for(int i=0;i<n-1;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  ans = 0;
  for(int i=0;i<n;i++){
    prop p;
    dfs(i, -1, p);
    ans = (ans + p.val)%mod;
  }

  printf("%lld\n", (ll) ans*ftable.ifact[2]%mod);

  return 0;
}
