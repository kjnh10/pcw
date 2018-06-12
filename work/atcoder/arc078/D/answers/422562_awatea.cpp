#include <cstdio>
#include <vector>

using namespace std;

int d[2][100000];
vector <int> v[100000];

void dfs(int x, int y, int z, int w) {
    int i;
    
    d[w][x] = z;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        dfs(v[x][i], x, z + 1, w);
    }
}

int main() {
    int n, c1 = 0, c2 = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(0, -1, 0, 0);
    dfs(n - 1, -1, 0, 1);
    
    for (i = 0; i < n; i++) {
        if (d[0][i] <= d[1][i]) {
            c1++;
        } else {
            c2++;
        }
    }
    
    if (c1 > c2) {
        puts("Fennec");
    } else {
        puts("Snuke");
    }
    
    return 0;
}
