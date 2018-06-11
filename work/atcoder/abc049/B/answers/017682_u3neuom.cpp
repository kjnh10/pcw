#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

inline void deBugMode() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE
}

inline void optimizeIt() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

inline int ABS(const int &x) {
    return max(x, -x);
}

const int NMax = 1e5 + 5;
const int LIM = 1e5;
const int MOD = 1000000007;

int main(){
    //deBugMode();
    optimizeIt();

    int n, m;
    string s;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        cout << s << "\n" << s << "\n";
    }

    return 0;

}
