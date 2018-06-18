#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int N;
int s, g;
vector<int> l, r;
typedef pair<int, int> P;

void input() {
  cin >> N;
  cin >> s >> g;
  l.resize(N + 1);
  r.resize(N + 1);
  for (int i = 0; i <= N; ++i) {
    cin >> l[i] >> r[i];
  }
}

double ang(P p1, P p2) {
  double dx = p2.first - p1.first;
  double dy = p2.second - p1.second;
  //return atan2(dy, dx);
  return -dx/dy;
}

double dist(P p1, P p2) {
  double dx = p2.first - p1.first;
  double dy = p2.second - p1.second;
  return sqrt(dx * dx + dy * dy);
}

double solve() {
  double d = 0.0;
  int lc = 0;
  int rc = 0;
  vector<P> lv, rv;
  lv.push_back(P(s, 0));
  rv.push_back(P(s, 0));

  for (int i = 1; i <= N; ++i) {
    P ln = P(l[i], i);
    P rn = P(r[i], i);
    if (i == N) {
      ln = P(g, N);
      rn = P(g, N);
    }

    while (lv.size() > lc + 1) {
      P lp = lv[lc];
      P lq = lv[lc + 1];
      double t1 = ang(lp, lq);
      double t2 = ang(lp, rn);
      if (t1 > t2) {
        break;
      }
      d += dist(lp, lq);
      ++lc;
      rv.clear();
      rv.push_back(lq);
      rc = 0;
    }

    while (rv.size() > rc + 1) {
      P rp = rv[rc];
      P rq = rv[rc + 1];
      double t1 = ang(rp, rq);
      double t2 = ang(rp, ln);
      if (t1 < t2) {
        break;
      }
      d += dist(rp, rq);
      ++rc;
      lv.clear();
      lv.push_back(rq);
      lc = 0;
    }

    {
      int j = lc;
      while (j + 1 < lv.size()) {
        P lp = lv[j];
        P lq = lv[j + 1];
        double t1 = ang(lp, lq);
        double t2 = ang(lp, ln);
        if (t1 >= t2) {
          break;
        }
        ++j;
      }
      while (j + 1 < lv.size()) {
        lv.pop_back();
      }
      lv.push_back(ln);
    }

    {
      int j = rc;
      while (j + 1 < rv.size()) {
        P rp = rv[j];
        P rq = rv[j + 1];
        double t1 = ang(rp, rq);
        double t2 = ang(rp, rn);
        if (t1 <= t2) {
          break;
        }
        ++j;
      }
      while (j + 1 < rv.size()) {
        rv.pop_back();
      }
      rv.push_back(rn);
    }
  }

  double ld = 0.0;
  for (int i = lc; i < lv.size() - 1; ++i) {
    ld += dist(lv[i], lv[i + 1]);
  }
  double rd = 0.0;
  for (int i = rc; i < rv.size() - 1; ++i) {
    rd += dist(rv[i], rv[i + 1]);
  }
  d += min(ld, rd);
  return d;
}

int main() {
  input();
  double ans = solve();
  cout << setprecision(15) << ans << endl;
  return 0;
}
