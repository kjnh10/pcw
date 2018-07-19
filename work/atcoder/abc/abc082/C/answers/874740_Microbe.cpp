#include <bits/stdc++.h>  

using namespace std;

//#define int long long
#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define INF (1 << 30)
#define fi first
#define se second

typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<P, P> PP;

const int MOD = 1e9 + 7;
const int dy[]={0, 0, 1, -1};
const int dx[]={1, -1, 0, 0};

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int n, a[100000];
map<int, int> mp;


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        ++mp[a[i]];
    }
    int res = 0;
    rep(i, n) {
        if(a[i] > mp[a[i]]) {
            res += mp[a[i]];
            mp[a[i]] = a[i];
        }
        else if(a[i] < mp[a[i]]) {
            res += mp[a[i]] - a[i];
            mp[a[i]] = a[i];
        }
    }
    cout << res << endl;
    return 0;
}