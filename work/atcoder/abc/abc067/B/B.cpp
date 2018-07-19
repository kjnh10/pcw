#include <iostream>/*{{{*/
#include <bits/stdc++.h>
#define rep(i, x) for(int i = 0; i < (int)(x); i++)
#define reps(i,x) for(int i = 1; i <= (int)(x); i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i >= n;i--)
#define ALL(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fill(x,y) memset(x,y,sizeof(x))
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

  int n,k;
  cin >> n>>k;
  vector<int> v(n);
  rep(i,n)cin >> v[i];
  sort(ALL(v), greater<int>());
  int c=0;
  rep(i,k) c+=v[i];
  cout << c << endl;

  return 0;
}
