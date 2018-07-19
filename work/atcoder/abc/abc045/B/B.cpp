#include <iostream>  /*{{{*/
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPS(i, n) for(int i = 1; i <= (int)(n); i++)
#define RREP(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define RREPS(i, n) for(int i=((int)(n));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i >= n;i--)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define FILL(x,y) memset(x,y,sizeof(x))
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define PB(a) push_back(a)
#define INF 999999999
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
/*}}}*/

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s[3];
  int idx[3]={};
  int curr=0;

  REP(i, 3) cin >> s[i];
  while (1) {
    curr = s[curr][idx[curr]++] - 'a';
    if (idx[curr] == s[curr].size()){
      cout << (char)('A'+curr) << endl;
      return 0;
    }
  }

  return 0;
}
