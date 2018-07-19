#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;

constexpr ll M = 1e9+7;

ll f(ll N) {
    ll res = 1;
    while(N > 0) {
        res *= N--;
        res %= M;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> T(N);
    for(int i=0; i<N; ++i) {
        cin >> T[i];
    }
    sort(T.begin(), T.end());
    ll t = 0, passed = 0;
    ll cnt = 1;
    for(int i=0; i<N; ++i) {
        ll n = upper_bound(T.begin(), T.end(), T[i]) - lower_bound(T.begin(), T.end(), T[i]);
        if(i == 0 || (i != 0 && T[i-1] != T[i])) {
            cnt *= f(n);
            cnt %= M;
        }
        passed += T[i];
        t += passed;
    }
    cout << t << endl;
    cout << cnt << endl;
}
