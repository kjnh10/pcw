#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int h, w, t, sy, sx, gy, gx;
  char s[11][11];
  cin >> h >> w >> t;
  rep(i, h) rep(j, w) {
    cin >> s[i][j];
    if(s[i][j] == 'S') sy = i, sx = j;
    else if(s[i][j] == 'G') gy = i, gx = j;
  }

  int dy[] = {1, 0, -1, 0};
  int dx[] = {0, 1, 0, -1};
  int lb = 0, ub = t;
  struct state {
    int y, x, d;
    state(int y = 0, int x = 0, int d = -1):y(y), x(x), d(d){}
    bool operator < (const state& s) const {
      return d > s.d;
    }
  };
  while(lb + 1 < ub) {
    int mb = (lb + ub) / 2;
    int d[11][11];
    fill(d[0], d[11], inf);
    priority_queue<state> q;
    d[sy][sx] = 0;
    q.emplace(sy, sx, 0);
    while(q.size()) {
      state st = q.top(); q.pop();
      int y = st.y, x = st.x;
      if(y == gy && x == gx) break;
      if(d[y][x] < st.d) continue;
      rep(i, 4) {
	int ny = y + dy[i], nx = x + dx[i];
	if(0 <= ny && ny < h && 0 <= nx && nx < w) {
	  if(s[ny][nx] != '#' && d[y][x] + 1 < d[ny][nx]) {
	    d[ny][nx] = d[y][x] + 1;
	    q.emplace(ny, nx, d[ny][nx]);
	  } else if(s[ny][nx] == '#' && d[y][x] + mb < d[ny][nx]) {
	    d[ny][nx] = d[y][x] + mb;
	    q.emplace(ny, nx, d[ny][nx]);
	  }
	}
      }
    }
    if(d[gy][gx] <= t) lb = mb;
    else ub = mb;
  }
  cout << lb << endl;

  return 0;
}
