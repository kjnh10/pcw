#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

pair<ll, int> mibit(ll l, ll r, int k) {
    if (l < 0)return mp(0ll, 0);
    pair<ll, int> res;
    for (int i = k; i >= 0; --i) {
        res.first |= r&(1ll << i);
        res.second += r >> i & 1;
        if ((l >> i & 1) != (r >> i & 1))break;
    }
    return res;
}

typedef vector<pair<long long, long long>> Intervals;
Intervals mergeIntervals(Intervals a) {
    Intervals res;
    sort(a.begin(), a.end());
    for (const auto & b : a) {
        if (res.size() == 0 || res.back().second < b.first)
            res.push_back(b);
        else
            res.back().second = max(res.back().second, b.second);
    }
    return res;
}

int N;
ll K;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    vll A(N);
    rep(i, N)cin >> A[i];
    sort(all(A));

    map<vll, Intervals> S;

    for (int k = 0; k <= 60; ++k) {
        vll B(N), C(N+1, -1), CC;
        ll div = 1ll << k;
        rep(i, N) {
            B[i] = A[i] / div;
            C[i] = A[i] % div;
        }
        CC = C;
        sort(all(C));
        C.erase(unique(all(C)), C.end());

        rep(i, sz(C) - 1) {
            ll P;
            int bitcnt;
            tie(P, bitcnt) = mibit(C[i], C[i + 1], k);
            if (k + bitcnt > K)continue;
            vll D = B;
            bool ok = true;
            rep(j, N) {
                D[j] += P > CC[j] ? -1 : 0;
                if (D[j] < 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok)continue;

            ll rem = K - bitcnt - k;
            ll r = D[0] + 1, l = max(0ll, D[0] - rem); //[l, r)
            ll d0 = D[0];
            rep(j, N)D[j] -= d0;

            S[D].push_back(mp(l, r));
        }
    }

    const ll MO = (ll)1e9 + 7;
    ll ans = 0;
    each(p, S) {
        auto intervals = mergeIntervals(p.second);
        each(lr, intervals) {
            ans += (lr.second - lr.first) % MO;
        }
    }
    ans %= MO;
    cout << ans << endl;
}
