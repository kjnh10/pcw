#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    EACH(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    REP(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector< vector<T> >& vec) {
    REP(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll W, n, K; cin >> W >> n >> K;
    vector<ll> w(n), v(n);
    REP(i, n) cin >> w[i] >> v[i];
    vector< vector< vector<ll> > > dp(n+1, vector<vector<ll>>(K+1, vector<ll>(W+1, -1)));
    dp[0][0][0] = 0;
    REP(i, n) REP(j, K+1) REP(k, W+1) {
        if (dp[i][j][k] < 0) continue;
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
        ll nj = j + 1;
        ll nk = k + w[i];
        if (nj <= K && nk <= W) {
            dp[i+1][nj][nk] = max(dp[i+1][nj][nk], dp[i][j][k] + v[i]);
        }
    }
    ll ans = -1;
    REP(i, K+1) REP(j, W+1) {
        ans = max(ans, dp[n][i][j]);
    }
    cout << ans << endl;
}
