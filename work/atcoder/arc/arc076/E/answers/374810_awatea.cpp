#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
int f[100000];

int convert(int x, int y) {
    if (y == 0) return x;
    if (x == r) return r + y;
    if (y == c) return r + c + r - x;
    return r + c + r + c - y;
}

int main() {
    int n, i;
    vector <pair<int, int> > v;
    vector <int> w;
    
    scanf("%d %d %d", &r, &c, &n);
    
    for (i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        if (x1 != 0 && x1 != r && y1 != 0 && y1 != c) continue;
        if (x2 != 0 && x2 != r && y2 != 0 && y2 != c) continue;
        
        v.push_back(make_pair(convert(x1, y1), i));
        v.push_back(make_pair(convert(x2, y2), i));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        int x = v[i].second;
        
        if (f[x] == 1) {
            if (w.back() != x) {
                puts("NO");
                
                return 0;
            }
            
            w.pop_back();
            f[x] = 0;
        } else {
            w.push_back(x);
            f[x] = 1;
        }
    }
    
    puts("YES");
    
    return 0;
}
