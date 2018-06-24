#include<iostream>
#include<sstream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cfloat>
#include<functional>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<bitset>
#include<list>
#include<numeric>
#include<complex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<long long, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<long long, long long> ll_ll;
typedef pair<double, double> d_d;
typedef vector<int> Vint;

#define PI 3.141592653589793238462643383279
#define mod 1000000007LL
#define rep(i, n) for(i = 0;i < n;++i)
#define rep1(i, n) for(i = 1;i < n;++i)
#define rep2d(i, j, n) for(i = 0;i < n;++i)for(j = i + 1;j < n;++j)
#define per(i, n) for(i = n - 1;i > -1;--i)
#define int(x) int x; scanf("%d",&x)
#define int2(x, y) int x, y; scanf("%d%d",&x, &y)
#define int3(x, y, z) int x, y, z; scanf("%d%d%d",&x, &y, &z)
#define int4(v, x, y, z) int v, x, y, z; scanf("%d%d%d%d", &v, &x, &y, &z)
#define int5(v, w, x, y, z) int v, w, x, y, z; scanf("%d%d%d%d%d", &v, &w, &x, &y, &z)
#define ll2(x, y) ll x, y; cin >> x >> y;
#define scn(n, a) rep(i, n)cin >> a[i]
#define sc2n(n, a, b) rep(i, n)cin >> a[i] >> b[i]
#define pri(x) cout << x << "\n"
#define pri2(x, y) cout << x << " " << y << "\n"
#define pri3(x, y, z) cout << x << " " << y << " " << z << "\n"
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define endl "\n"
#define kabe puts("---------------------------")
#define kara puts("")
#define debug(x) cout << " --- " << x << "\n"
#define debug2(x, y) cout << " --- " << x << " " << y << "\n"
#define debug3(x, y, z) cout << " --- " << x << " " << y << " " << z << "\n"
#define X first
#define Y second
#define eps 0.0001
#define prid(x) printf("%.15lf\n", x)
#define N 202020

ll p[N] = {1}, pinv[N];
ll modpow(ll x, int a){
  if(a == 0)return 1;
  else if(a == 1)return x;
  else {
    ll res = modpow(x, a / 2);
    res = res * res % mod;
    if(a % 2 == 0)return res;
    else return res * x % mod;
  }
}

void use(void){
  int i;
  rep1(i, N)p[i] = p[i - 1] * i % mod;
  rep(i, N)pinv[i] = modpow(p[i], mod - 2);
  return;
}

ll getC(int n, int r){
  return (p[n] * pinv[r] % mod) * pinv[n - r] % mod;
}

signed main(void){
  int i, j, k;
  use();
  for(int testcase = 0;testcase >= 0;testcase++){
    int4(h, w, a, b);

    ll res = 0;
    rep(i, h - a){
      ll tmp = 1;
      //(tate : i, yoko : b) wo keiyu
      tmp = getC(i + b - 1, b - 1) * getC(h - i + w - b - 2, h - i - 1) % mod;
      res = (res + tmp) % mod;
    }
    pri(res);

/*/

//*/ break;
  }
  return 0;
}
