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
  string s;
  cin>>s;
  int n = s.size();

  vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
  // [i,j)
  rep(i,n+1) dp[i][i] = 0;

  for(int d=3; d<=n; d+=3){
    rep(i,n-d+1){
      int j = i+d;
      for(int k=i+3; k<=j; k+=3) if(dp[i][k]>=0 && dp[k][j]>=0) dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]);
      if(s[i]=='i' && s[j-1]=='i'){
        if(s[i+1]=='w' && dp[i+2][j-1]>=0) dp[i][j] = max(dp[i][j], dp[i+2][j-1]+1);
        if(s[j-2]=='w' && dp[i+1][j-2]>=0) dp[i][j] = max(dp[i][j], dp[i+1][j-2]+1);
      }
    }
  }

  vector<vector<int>> dp2(n+1, vector<int>(n+1, 0));

  repl(d,1,n+1) rep(i,n-d+1){
    int j = i+d;
    for(int k=i; k<=j; k++){
      dp2[i][j] = max(dp2[i][j], dp2[i][k]+dp2[k][j]);
      dp2[i][j] = max(dp2[i][j], dp[i][j]);
    }
  }

  cout << dp2[0][n] << endl;

  return 0;
}
