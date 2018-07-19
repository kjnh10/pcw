#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define forn(i,n) for(ll i=0;i<ll(n);++i)
#define all(x) (x).begin(),(x).end()

class DisjointSets {
public:
    explicit DisjointSets(ll N) : id_(N) {
        forn(i, N) id_[i] = i;
    }

    void join(ll a, ll b) {
        if (a > b) swap(a, b);
        id_[id(b)] = id(a);
    }

    ll id(ll a) {
        if (id_[a] == a) return a;
        ll i = id(id_[a]);
        id_[a] = i;
        return i;
    }

private:
    vll id_;
};

int main() {
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vll p(N);
    forn(i, N) cin >> p[i], --p[i];
    DisjointSets uf(N);
    forn(i, M) {
        ll x, y;
        cin >> x >> y;
        --x, --y;
        uf.join(x, y);
    }
    ll ok = 0;
    forn(i, N) {
        ok += uf.id(p[i]) == uf.id(i);
    }
    cout << ok << '\n';
}