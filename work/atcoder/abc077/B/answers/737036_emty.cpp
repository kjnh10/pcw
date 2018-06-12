#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    ll ans = 1;
    for (ll i = 1; i <= sqrt(N); i++) {
        if (i * i <= N) {
            ans = i * i;
        }
    }
    cout << ans << endl;

    return 0;
}
