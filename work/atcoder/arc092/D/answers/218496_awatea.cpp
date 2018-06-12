#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[200000];
vector <int> v[30][2];

int main() {
    int n, ans = 0, i, j, k;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        for (j = 0; j < 30; j++) v[j][(x >> j) & 1].push_back(x & ((1 << j) - 1));
    }
    
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 2; j++) {
            sort(v[i][j].begin(), v[i][j].end());
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 30; j++) {
            int p = ((a[i] >> j) & 1);
            int q = (a[i] & ((1 << j) - 1));
            
            for (k = 0; k < 2; k++) {
                int c;
                
                if (v[j][k].size() == 0) continue;
                
                c = lower_bound(v[j][k].begin(), v[j][k].end(), (1 << j) - q) - v[j][k].begin();
                
                if (p ^ k) {
                    if (c & 1) ans ^= (1 << j);
                } else {
                    if ((v[j][k].size() - c) & 1) ans ^= (1 << j);
                }
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
