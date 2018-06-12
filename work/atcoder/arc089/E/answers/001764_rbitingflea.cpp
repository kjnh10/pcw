#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 300, link = 101, inf = ~0U >> 2;

int a, b, d[11][11], d2[11][11];
int n, m, x[link + 1], y[link + 1];
pair<pair<int, int>, int> edge[1000000];

void AddEdge(int u, int v, int c) {
  edge[m++] = {{u, v}, c};
}

int main(void) {
  scanf("%d%d", &a, &b);
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      scanf("%d", d[i] + j);
    }
  }
  n = 2;
  x[0] = 0;
  for (int i = 1; i <= link; ++i) {
    x[i] = n++;
    AddEdge(x[i - 1], x[i], -1);
  }
  y[0] = 1;
  for (int i = 1; i <= link; ++i) {
    y[i] = n++;
    AddEdge(y[i], y[i - 1], -2);
  }
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      d2[i][j] = inf;
    }
  }
  for (int dx = 0; dx <= link; ++dx) {
    for (int dy = 0; dy <= link; ++dy) {
      int delta = -inf;
      for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
          delta = max(delta, d[i][j] - dx * i - dy * j);
        }
      }
      if (delta >= 0 && delta <= 100) {
        AddEdge(x[dx], y[dy], delta);
        for (int i = 1; i <= a; ++i) {
          for (int j = 1; j <= b; ++j) {
            d2[i][j] = min(d2[i][j], dx * i + dy * j + delta);
          }
        }
      }
    }
  }
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      if (d2[i][j] != d[i][j]) {
        puts("Impossible");
        return 0;
      }
    }
  }
  puts("Possible");
  printf("%d %d\n", n, m);
  for (int i = 0; i < m; ++i) {
    printf("%d %d ", edge[i].first.first + 1, edge[i].first.second + 1);
    if (edge[i].second == -1) {
      puts("X");
    } else if (edge[i].second == -2) {
      puts("Y");
    } else {
      printf("%d\n", edge[i].second);
    }
  }
  puts("1 2");
  return 0;
}
