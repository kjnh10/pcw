#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001
#define MOD ((ll)1e9 + 7)

int n, k;

vector<int> divisor(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.pb(i);
      if (i != n / i) res.pb(n / i);
    }
  }
  return res;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n >> k;

  vector<int> v = divisor(k);
  sort(all(v));

  ll sum[v.size()] = {}, ans = 0;
  repr(i, v.size()) {
    ll tmp = n / v[i];
    sum[i] = ((tmp + 1) * tmp / 2) % MOD;
    repl(j, i + 1, v.size()) {
      if (v[j] % v[i] == 0) {
        sum[i] = ((sum[i] - sum[j] * (v[j] / v[i])) % MOD + MOD) % MOD;
      }
    }

    ans = (ans + sum[i]) % MOD;
  }

  print((ans * k) % MOD);

  return 0;
}