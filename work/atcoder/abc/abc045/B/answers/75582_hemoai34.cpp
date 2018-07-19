#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;

#define PI 3.141592653589793238462643383279
#define mod 1000000007LL
#define rep(i, n) for(i = 0;i < n;++i)
#define rep1(i, n) for(i = 1;i < n;++i)
#define per(i, n) for(i = n - 1;i > -1;--i)
#define int(x) int x; scanf("%d",&x)
#define int2(x, y) int x, y; scanf("%d%d",&x, &y)
#define int3(x, y, z) int x, y, z; scanf("%d%d%d",&x, &y, &z)
#define int4(v, x, y, z) int v, x, y, z; scanf("%d%d%d%d", &v, &x, &y, &z)
#define int5(v, w, x, y, z) int v, w, x, y, z; scanf("%d%d%d%d%d", &v, &w, &x, &y, &z)
#define ll2(x, y) ll x, y; cin >> x >> y;
#define scn(n, a) rep(i, n)cin >> a[i]
#define sc2n(n, a, b) rep(i, n)cin >> a[i] >> b[i]
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define endl "\n"
#define kabe puts("---------------------------")
#define kara puts("")
#define debug(x) cout << " --- " << (x) << "\n"
#define debug2(x, y) cout << " --- " << (x) << " " << (y) << "\n"
#define debug3(x, y, z) cout << " --- " << (x) << " " << (y) << " " << (z) << "\n"
#define X first
#define Y second
#define eps 0.0001
#define prid(x) printf("%.15lf\n", x)


signed main(void){
  int i, j;
  for(int testcase = 0;testcase >= 0;testcase++){
    string a, b, c;
    cin >> a >> b >> c;
    int t = 1; //abc > 123
    int ah = 0, bh = 0, ch = 0;
    for(;;){
      if(t == 1){
        if(a.size() == ah){
          pri("A");
          break;
        }
        if(a[ah] == 'a')t = 1;
        if(a[ah] == 'b')t = 2;
        if(a[ah] == 'c')t = 3;
        ++ah;
      }else if(t == 2){
        if(b.size() == bh){
          pri("B");
          break;
        }
        if(b[bh] == 'a')t = 1;
        if(b[bh] == 'b')t = 2;
        if(b[bh] == 'c')t = 3;
        ++bh;
      }else{
        if(c.size() == ch){
          pri("C");
          break;
        }
        if(c[ch] == 'a')t = 1;
        if(c[ch] == 'b')t = 2;
        if(c[ch] == 'c')t = 3;
        ++ch;
      }
    }


/*/

//*/ break;
  }
  return 0;
}
