#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool C(vector<ll>& H, vector<ll>& S, ll m) {
    int N = H.size();
    vector<ll> sum(N);
    bool res = true;
    for(int i=0; i<N; ++i) {
        ll t = (m - H[i])/S[i];
        if(m - H[i] < 0) {
            res = false;
        } else if(t < N) {
            sum[t] += 1;
        }
    }
    for(int i=0; i<N; ++i) {
        if(i >= 1) {
            sum[i] += sum[i-1];
        }
        if(sum[i] > i+1) {
            res = false;
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<ll> H(N), S(N);
    for(int i=0; i<N; ++i) {
        cin >> H[i] >> S[i];
    }
    ll l = 0, r = 1e18;
    while(r - l > 1) {
        ll m = (l + r) / 2;
        if(C(H, S, m)) {
            r = m;
        } else {
            l = m;
        }
    }
    if(C(H, S, l)) {
        cout << l << endl;
    } else {
        cout << r << endl;
    }
}
