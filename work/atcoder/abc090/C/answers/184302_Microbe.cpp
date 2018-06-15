#include <bits/stdc++.h>  

using namespace std;

#define int long long
#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define INF 1e9
#define LINF 1e18

typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<P, P> PP;

const int MOD = 1e9 + 7;
const int dy[]={0, 0, 1, -1};
const int dx[]={1, -1, 0, 0};

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    if(N == 1 && M == 1) cout << 1 << endl;
    else if(N == 1) cout << M - 2 << endl;
    else if(M == 1) cout << N - 2 << endl;
    else cout << N * M - N * 2 - M * 2 + 4 << endl;
    return 0;
}