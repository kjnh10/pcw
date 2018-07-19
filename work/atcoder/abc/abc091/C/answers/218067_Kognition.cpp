#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
// const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int MAXN = 210;
const int INF = 1000000000;

// destination, capacity
vector<pair<int, int> > g[MAXN];

int max_flow(int s, int t, int n) {
    vector<int> ff(n + 1, 0);
    vector<int> fa(n + 1, 0);
    vector<int> fi(n + 1, 0);
    vector<bool> z(n + 1, 0);
    
    int i = 0, now, ans = 0;
    
    i = s;
    now = INF;
    
    while (true) {
        z[i] = true;
        ff[i] = now;
        bool flag = false;
        auto p = g[i].begin();
        while (p != g[i].end()) {
             if (p->second > 0 && !z[p->first]) {
                flag = true;
                if (p->second < now) now = p->second;
                fa[p->first] = i;
                fi[p->first] = p - g[i].begin();
                i = p->first;
                if (i == t) {
                    ans += now;
                    while (i != s) {
                        int tmp = i;
                        i = fa[i];
                        p = g[i].begin() + fi[tmp];
                        p->second -=now;
                        g[tmp].push_back(make_pair(i, now));
                    }
                    now = INF;
                    z = vector<bool> (n + 1, false);
                }
                break;
            }
            ++p;
        }
        if (flag) continue;
        if (!flag && i == s) break;
        
        if (i != s) {
            i = fa[i];
            now = ff[i];
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    int n;
    cin >> n;
    vector<pii> red(n+1), blue(n+1);
    FOR(i, 1, n) cin >> red[i].first >> red[i].second;
    FOR(i, 1, n) cin >> blue[i].first >> blue[i].second;
    int src = 2*n+1;
    int tgt = src+1;
    FOR(i, 1, n) {
    	g[src].push_back({i, 1});
    	g[n+i].push_back({tgt, 1});
    	FOR(j, 1, n) {
    		if(red[i].first < blue[j].first && red[i].second < blue[j].second) {
    			g[i].push_back({n+j, 1});
    		}
    	}
    }
    cout << max_flow(src, tgt, tgt) << endl;

    return 0;
}