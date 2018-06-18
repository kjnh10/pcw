#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define ALL(v)     (v.begin()), (v.end())

const int INF = 1000000000;
const int H_MAX = 2000;
const int W_MAX = 2000;

int H, W;
char c[H_MAX][W_MAX + 1];

typedef long long ll;

struct CS {
  int oc, xc, fr;
  bool operator < (const CS &cs) const {
    return oc + xc < cs.oc + cs.xc;
  }
};

int og, xg;
ll mt;
vector<CS> css;

void add_rng(int fr, int oc, int xc, int om, int xm) {
  mt += (om - xm);
  if (fr > 1) css.push_back({ oc - 1, xc - 1, fr - 1 });
}

void cnt_mvs(int i) {
  int fr;
  int oc = 0, xc, xs;
  int om, xm;
  char *v = c[i];
  int s = -1, t = 0;
  while (true) {
    while (t < W && v[t] == '.') t++;
    if (t == W) {
      if (s < 0) {
        // noop
      } else if (v[s] == 'o') {
        og = min(og, t - s - 1);
      } else if (v[s] == 'x') {
        if (oc > 0) add_rng(fr, oc, xc, om, xm);
      }
      break;
    } else if (v[t] == 'o') {
      if (s < 0) {
        oc = 1; om = 0;
      } else if (v[s] == 'o') {
        om += (t - s - 1) * oc++;
      } else if (v[s] == 'x') {
        if (oc > 0) add_rng(fr, oc, xc, om, xm);
        oc = 1; om = 0;
      }
    } else if (v[t] == 'x') {
      if (s < 0) {
        xg = min(xg, t);
      } else if (v[s] == 'o') {
        fr = t - s - 1;
        xc = 1; xm = 0; xs = t;
      } else if (v[s] == 'x') {
        if (oc > 0) xm += t - xs - xc++;
      }
    }
    s = t++;
  }
}

void solve() {
  og = INF; xg = INF;
  REP(i, H) cnt_mvs(i);
  if (og < INF || xg < INF) {
    printf("%s\n", og <= xg ? "o" : "x");
    return;
  }

  sort(ALL(css));
  bool turn = true;
  while (!css.empty()) {
    CS &cs = css.back();
    cs.fr--;
    mt += turn ? cs.oc : -cs.xc;
    turn = !turn;
    if (cs.fr <= 0)  css.pop_back();
  }

  if (mt != 0) {
    printf("%s\n", mt > 0 ? "o" : "x");
  } else {
    printf("%s\n", turn ? "x" : "o");
  }
}

void input() {
  scanf("%d%d", &H, &W);
  REP(i, H) scanf("%s", c[i]);
}

int main() {
  input();
  solve();
  return 0;
}
