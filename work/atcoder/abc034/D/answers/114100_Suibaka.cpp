#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using P = pair<double, double>;

int main() {
    int K, N;
    cin >> N >> K;
    vector<P> v(N);
    for(int i=0; i<N; ++i) {
        cin >> v[i].first >> v[i].second;
        v[i].second /= 100;
    }
    double b = 0, u = 1.0;
    for(int i=0; i<100; ++i) {
        double m = (b + u) / 2;
        sort(v.begin(), v.end(), [m](P const& p1, P const& p2) {
            return p1.first * (p1.second - m) > p2.first * (p2.second - m);
        });
        double t = 0;
        for(int i=0; i<K; ++i) {
            t += v[i].first * (v[i].second - m);
        }
        if(t >= 0) {
            b = m;
        } else {
            u = m;
        }
    }
    cout << fixed << setprecision(10) << b * 100 << endl;
}
