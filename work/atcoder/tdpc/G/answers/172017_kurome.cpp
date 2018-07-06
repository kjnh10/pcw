#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for(int (i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)

typedef long long ll;
const int N = 1e6;
const ll K = 1e18;
const int L = 26;
const ll INF = K + 10;
char s[N+1], res[N+1];
int n, n_res;
ll kk;
ll dp[N+1][L];

//s[]の[pos]以降で，辞書順 k-th にある先頭の文字('a'+first)を探索
//first...-1:不明, 0-25:すでに探索すべき'a'+firstが確定
void recover(int pos, int first, ll k) {
  //先頭が'a'...'z'のどれかをまず探索
  if (first == -1) {
    REP(i,L) {
      if (k <= dp[pos][i]) {
        recover(pos, i, k);
        return;
      }
      k -= dp[pos][i];
    }
  }

  //先頭であることが確定した 'a'+first をs[]上の[pos]以降で探索
  while (s[pos] != 'a'+first) pos++;
  res[n_res++] = s[pos]; k--;

  if (k > 0) recover(pos+1, -1, k);
}

int main() {
  scanf("%s ", s);
  n = (int)strlen(s);
  scanf("%lld ", &kk);

	//dp[i][c] = "sのi文字目以降の部分列で、文字cから始まるものの個数"を入れるテーブルを作成
  memset(dp, 0, sizeof(dp));
  REP(i,n) REP(j,L) {
    if (s[n-1-i]=='a'+j)  {
      dp[n-1-i][j] = 1;
      REP(k,L) dp[n-1-i][j] = min(dp[n-1-i][j] + dp[n-i][k], INF);
    } else
      dp[n-1-i][j] = dp[n-i][j];
  }

  ll sum = 0;
  REP(i,L) sum = min(sum + dp[0][i], INF);
  if (sum < kk) {
    puts("Eel");
    return 0;
  }

  memset(res, 0, sizeof(res)); n_res = 0;
  recover(0, -1, kk);
  printf("%s\n", res);

  return 0;
}