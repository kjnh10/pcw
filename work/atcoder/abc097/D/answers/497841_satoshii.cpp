#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
  UnionFind(const int n);
  void unite(int x, int y);
  int find(int x);
  int size_of(int x); // x が含まれるグループの要素数を返す。
private:
  vector<int> par;
};

UnionFind::UnionFind(const int n) : par(n, -1) {}

int UnionFind::find(int x) {
  return par[x] < 0 ? x : (par[x] = find(par[x]));
}

void UnionFind::unite(int x, int y) {
  x = find(x), y = find(y);
  if(x == y) { return; }
  if(par[x] > par[y]) { swap(x, y); }
  par[x] += par[y];
  par[y] = x;
}

int UnionFind::size_of(int x) { return -par[find(x)]; }

int main(void) {
  int n, m; scanf("%d%d", &n, &m);
  UnionFind uf(n);
  vector<int> v(n); // v[n]
  for(int i=0; i<n; ++i) {
    scanf("%d", &v[i]);
    --v[i];
  }
  for(int i=0; i<m; ++i) {
    int a, b; scanf("%d%d", &a, &b);
    --a, --b;
    uf.unite(a, b);
  }
  int res = 0;
  for(int i=0; i<n; ++i) {
    if(uf.find(i) == uf.find(v[i])) { ++res; }
  }
  printf("%d\n", res);
  return 0;
}
