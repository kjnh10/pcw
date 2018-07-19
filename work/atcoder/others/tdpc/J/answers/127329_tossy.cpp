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
#define long long long // for codeforces

int main(){
  int n;
  cin>>n;
  vector<int> vec(n);
  rep(i,n) cin>>vec[i];
  sort(all(vec));
  int i_mask = 0;
  rep(i,n) i_mask += 1<<vec[i];

  vector<double> dp(i_mask+1, INF);
  dp[0] = 0;
  repl(mask,1,i_mask+1){
    // mask 残りの場所
    for(int i=1; i<=14; i++){
      // i になげる
      int cnt = 0;
      double acc = 0;
      for(int d=i-1; d<=i+1; d++) if(mask&(1<<d)){
        cnt++;
        acc += dp[mask - (1<<d)];
      }
      if(cnt>0) dp[mask] = min(dp[mask], (acc+3.0)/cnt);
    }
//    dbg(mp(bitset<15>(mask), dp[mask]));
  }

  printf("%.7f\n", dp[i_mask]);

  return 0;
}
