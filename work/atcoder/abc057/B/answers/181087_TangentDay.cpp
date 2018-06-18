#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    int n, m;
    cin >> n >> m;
    VI a(n), b(n), c(m), d(m);
    REP(i,n) cin >> a[i] >> b[i];
    REP(i,m) cin >> c[i] >> d[i];
    REP(i,n){
        int mi = 1e9, ans;
        REP(j,m){
            int p = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if (p < mi){
                ans = j+1;
                mi = p;
            }
        }
        cout << ans << endl;
    }

    return 0;
}