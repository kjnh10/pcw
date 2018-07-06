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

int main(){
  string s;
  cin>>s;
  long k;
  cin>>k;
  int n = s.size();

  vector<vector<long>> dp(n+1, vector<long>(26,0));
  // dp[i][j] : i文字目以降で，先頭文字j+'a'は何文字作れるか

  for(int i=n-1; i>=0; i--) rep(j,26){
    if(s[i]==j+'a'){
      dp[i][j]=1;
      rep(p,26) dp[i][j] = min(dp[i][j] + dp[i+1][p], k+1); // overflow 対策
    } else {
      dp[i][j] = dp[i+1][j];
    }
  }
//rep(i,n) dbg(mp(s[i],dp[i]));
  long sum = 0;
  rep(i,n){
    sum += dp[0][i];
    if(sum > k) break;
  }
  if(sum < k){
    cout<<"Eel"<<endl;
    return 0;
  }

  string ans = "";
  int i=0, j=0;
  while(k>0){
    if(dp[i][j] < k){
      k -= dp[i][j];
      j++;
    } else {
      ans.pb('a'+j);
      int d=0;
      while(s[i+d]!=j+'a') d++;
      i += d+1;
      j = 0;
      k--;
    }
  }

  cout << ans << endl;

  return 0;
}
