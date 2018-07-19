#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    ll mx = 1e9, Mx = -1e9, my = 1e9, My = -1e9;
    for(int i=0; i<N; ++i) {
        cin >> x[i] >> y[i];
        mx = min(mx, x[i] - y[i]), Mx = max(Mx, x[i] - y[i]);
        my = min(my, x[i] + y[i]), My = max(My, x[i] + y[i]);
    }
    ll t = max(Mx - mx, My - my) / 2;
    vector<ll> can_x = {Mx - t, t + mx},
               can_y = {My - t, t + my};
    for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) {
            bool ok = true;
            ll xx = (can_x[i] + can_y[j]) / 2,
               yy = (can_y[j] - can_x[i]) / 2;
            for(int k=1; k<N; ++k) {
                ok &= abs(x[k]-xx) + abs(y[k]-yy) == abs(x[k-1]-xx) + abs(y[k-1]-yy);
            }
            if(ok) {
                cout << xx << " " << yy << endl;
                return 0;
            }
        }
    }
    assert(false);
}
