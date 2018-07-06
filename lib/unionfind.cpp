#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  vector<int> parent;
  vector<int> size;

  UnionFind(int n) : parent(n), size(n, 1) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int operator[](int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = operator[](parent[x]);
    }
  }

  bool merge(int x, int y) {
    x = operator[](x);
    y = operator[](y);
    if (x == y) return false;
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    return true;
  }
};
