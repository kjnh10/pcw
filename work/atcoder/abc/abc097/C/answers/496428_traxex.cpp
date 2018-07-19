#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define forn(i,n) for(ll i=0;i<ll(n);++i)
#define all(x) (x).begin(),(x).end()

int main() {
    ios::sync_with_stdio(false);
    string s;
    ll k;
    cin >> s >> k;
    set<string> S;
    ll n = s.size();
    forn(i, n) {
        for (ll j = i; j < n; ++j) {
            string t = s.substr(i, j-i+1);
            if ((ll)S.size() < k || t < *S.rbegin()) {
                S.insert(t);
            }
            else break;
            while ((ll)S.size() > k) {
                S.erase(prev(S.end()));
            }
        }
    }
    cout << *S.rbegin() << '\n';
}
