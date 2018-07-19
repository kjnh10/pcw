#include <iostream>/*{{{*/
#include <bits/stdc++.h>
#define REP(i, x) for(int i = 0; i < (int)(x); i++)
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

  int y,n;

  cin >> n >> y;

  FOR(i, 0, n+1){
    FOR(j, 0, n+1){
      if(i+j>n){
        continue;
      }
      else{
        if(i*10000 + j*5000 + (n-i-j)*1000 == y){
          cout << i << " " << j << " " << n-i-j << endl;
          return 0;
        }
      }
    }
  }
  cout << "-1 -1 -1" << endl;


  return 0;
}
