#include <iostream>/*{{{*/
#include <bits/stdc++.h>
#define rep(i, x) for(int i = 0; i < (int)(x); i++)
#define REPS(i,x) for(int i = 1; i <= (int)(x); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i >= n;i--)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define FILL(x,y) memset(x,y,sizeof(x))
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define PB(a) push_back(a)
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

  int h,w;cin>>h>>w;
  string s[h+2];

  FOR(i, 1, h+1){
    string tmp;
    cin>>tmp;
    s[i] = "." + tmp + ".";
  }

  FOR(i,1,h+1){
    FOR(j,1,w+1){
      int count = 0;
      if (s[i][j] == '.'){
        for(auto p:{-1,0,1}){
          for(auto q:{-1,0,1}){
            if (s[i+p][j+q]=='#') count++;
          }
        }
        s[i][j] = '0'+count;
      }
    }
  }

  FOR(i, 1, h+1){cout << s[i].substr(1, w) << endl;}

  return 0;
}
