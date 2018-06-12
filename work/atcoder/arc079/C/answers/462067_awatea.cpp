#include <cstdio>
#include <set>

using namespace std;

set <int> s[200000];

int main() {
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        s[x].insert(y);
        s[y].insert(x);
    }
    
    for (i = 1; i < n - 1; i++) {
        if (s[i].count(0) && s[i].count(n - 1)) {
            puts("POSSIBLE");
            
            return 0;
        }
    }
    
    puts("IMPOSSIBLE");
    
    return 0;
}
