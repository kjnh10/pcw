#include <iostream>/*{{{*/
#include <bits/stdc++.h>
#define rep(i, x) for(int i = 0; i < (int)(x); i++)
#define reps(i,x) for(int i = 1; i <= (int)(x); i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i >= n;i--)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define FILL(x,y) memset(x,y,sizeof(x))
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define debug(x) cerr << __LINE__ << ": " << #x << " -> " << x << '\n'
#define INF 999999999
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};/*}}}*/

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;

  rep(i, n){
    string t;
    cin >> t;
    bool flag = false;
    rep(j, t.size()-s.size()+1){
      if (s[0] != t[j]) continue;

      int er=0;
      rep(k, s.size()+1){
        if (er==0){
          if (s[k]!=t[j+k] && k<=s.size()-1){
            er+=1;
          }
        }
        else{
          if (s[k-1]!=t[j+k]){
            er++;
            break;
          }
        }
      }
      if (er <= 1){
        flag = true;
      }
    }
    if (flag) cout << "valid" << endl;
    else cout << "invalid" << endl;
  }

  return 0;
}
