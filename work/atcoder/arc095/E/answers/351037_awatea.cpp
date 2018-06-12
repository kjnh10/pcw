#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int h, w;
char s[12][13];
string ss[12];
int a[12];
int b[12];

void dfs1(int x, bool f) {
    if (x == w) {
        puts("YES");
        exit(0);
    } else if (b[x] != -1) {
        dfs1(x + 1, f);
    } else {
        int i, j;
        
        for (i = x + 1; i < w; i++) {
            if (b[i] != -1) continue;
            
            for (j = 0; j < h; j++) {
                if (s[j][x] != s[a[j]][i]) break;
            }
            
            if (j == h) {
                b[x] = i;
                b[i] = x;
                
                dfs1(x + 1, f);
                
                b[x] = b[i] = -1;
            }
        }
        
        if (!f) {
            for (j = 0; j < h; j++) {
                if (s[j][x] != s[a[j]][x]) break;
            }
            
            if (j == h) {
                b[x] = x;
                
                dfs1(x + 1, true);
                
                b[x] = -1;
            }
        }
    }
}

void dfs2(int x, bool f) {
    if (x == h) {
        dfs1(0, w % 2 == 0);
    } else if (a[x] != -1) {
        dfs2(x + 1, f);
    } else {
        int i;
        
        for (i = x + 1; i < h; i++) {
            if (a[i] != -1) continue;
            if (ss[x] != ss[i]) continue;
            
            a[x] = i;
            a[i] = x;
            
            dfs2(x + 1, f);
            
            a[x] = a[i] = -1;
        }
        
        if (!f) {
            a[x] = x;
            
            dfs2(x + 1, true);
            
            a[x] = -1;
        }
    }
}

int main() {
    int i;
    
    scanf("%d %d", &h, &w);
    
    for (i = 0; i < h; i++) scanf("%s", s[i]);
    
    for (i = 0; i < h; i++) {
        ss[i] = s[i];
        sort(ss[i].begin(), ss[i].end());
    }
    
    for (i = 0; i < h; i++) a[i] = -1;
    for (i = 0; i < w; i++) b[i] = -1;
    
    dfs2(0, h % 2 == 0);
    
    puts("NO");
    
    return 0;
}
