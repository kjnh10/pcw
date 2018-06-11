#include <bits/stdc++.h>
using namespace std;

#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)a.size())

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

//DisjointSet(int n), DisjointSet.initSet(int n)
//DisjointSet.find(int n)
//DisjointSet.isSameSet(int i, int j)
//DisjointSet.merge(int i, int j)
// {{{ Disjoint Set
struct DisjointSet {
  vector<int> pset, setSize;
  int setNum;

  DisjointSet() {}
  DisjointSet(int n) {
    initSet(n);
  }

  void initSet(int n) {
    pset.resize(n);
    setSize.assign(n, 1);
    setNum = n;
    for (int i = 0; i < n; i++) pset[i] = i;
  }

  int find(int n) { return pset[n] == n ? n : (pset[n] = find(pset[n])); }

  bool isSameSet(int i, int j) { return find(i) == find(j); }

  void merge(int i, int j) {
    if(isSameSet(i, j)) return;
    setNum--;
    i = find(i);
    j = find(j);
    if(setSize[i] < setSize[j]) {
      pset[i] = j;
      setSize[j] += setSize[i];
    } else {
      pset[j] = i;
      setSize[i] += setSize[j];
    }
  }
};
// }}}

const int N = 2e5 + 5;

int n, md, mw;
int ans[N];
pii ed[N / 2];
pii ew[N / 2];
DisjointSet dd;
DisjointSet dw;
DisjointSet dmix;
vi ids[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> md >> mw;
  for (int i = 0; i < md; i++) {
    cin >> ed[i].first >> ed[i].second;
    ed[i].first--;
    ed[i].second--;
  }
  for (int i = 0; i < mw; i++) {
    cin >> ew[i].first >> ew[i].second;
    ew[i].first--;
    ew[i].second--;
  }
  dd.initSet(n);
  for (int i = 0; i < md; i++) {
    dd.merge(ed[i].first, ed[i].second);
  }
  dw.initSet(n);
  for (int i = 0; i < mw; i++) {
    if (dd.find(ew[i].first) == dd.find(ew[i].second)) {
      dw.merge(ew[i].first, ew[i].second);
    }
  }
  for (int i = 0; i < n; i++) {
    ids[dd.find(i)].push_back(dw.find(i));
  }
  for (int i = 0; i < n; i++) {
    sort(ALL(ids[i]));
    ids[i].erase(unique(ALL(ids[i])), end(ids[i]));
  }
  dmix.initSet(n);
  for (int i = 0; i < mw; i++) {
    if (dd.find(ew[i].first) != dd.find(ew[i].second)) {
      dmix.merge(dw.find(ew[i].first), dw.find(ew[i].second));
    }
  }
  for (int i = 0; i < n; i++) {
    map<int, int> m;
    for (int j : ids[i]) {
      m[dmix.find(j)] += dw.setSize[dw.find(j)];
    }
    for (int j : ids[i]) {
      ans[j] = m[dmix.find(j)];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[dw.find(i)] << (i + 1 == n ? '\n' : ' ');
  }
  return 0;
}

