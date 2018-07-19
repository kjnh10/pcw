#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

char s[12525];
int x,y;

bool dp[2][25252];
const int C = 12525;

int main(){
  scanf("%s%d%d",s,&x,&y);
  int n = strlen(s);
  vi vx, vy;
  int first = 0;
  int it = 0;
  while(it < n && s[it]=='F'){
    first++;
    it++;
  }
  it++;
  bool xxx = false;
  while(it < n){
    int tmp = 0;
    while(it < n && s[it] == 'F'){
      tmp++;
      it++;
    }
    (xxx ? vx : vy).push_back(tmp);
    it++;
    xxx = xxx ^ 1;
  }
  // x check
  REP(i,25252)dp[0][i] = false;
  dp[0][C+first] = true;
  for(int xx : vx){
    REP(i,25252)dp[1][i] = false;
    REP(i,25252)if(dp[0][i]){
      dp[1][i+xx] = true;
      dp[1][i-xx] = true;
    }
    REP(i,25252)dp[0][i] = dp[1][i];
  }
  if(!dp[0][C+x]){
    puts("No");
    return 0;
  }
  // y check
  REP(i,25252)dp[0][i] = false;
  dp[0][C] = true;
  for(int yy : vy){
    REP(i,25252)dp[1][i] = false;
    REP(i,25252)if(dp[0][i]){
      dp[1][i+yy] = true;
      dp[1][i-yy] = true;
    }
    REP(i,25252)dp[0][i] = dp[1][i];
  }
  if(!dp[0][C+y]){
    puts("No");
    return 0;
  }
  puts("Yes");
  return 0;
}
