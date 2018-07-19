#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <functional>
#include <cstring>
#include <cmath>
#include <random>
using namespace std;

int main() {
    int k, n;
    cin >> k;
    n = 1 << k;
    vector<double> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<double> p(n * 2);
    double *p0 = &p[0], *p1 = &p[n];
    for (int i = 0; i < n; i++) {
        p0[i] = 1;
    }
    for (int h = 1; h < n; h *= 2) {
        for (int i = 0; i < n; i += h * 2) {
            for (int j = i; j < i + h; j++) {
                double pj = 0, ph = 0;
                for (int k = 0; k < h; k++) {
                    pj += p0[i + h + k] / (1 + pow(10, (r[i + h + k] - r[j]) / 400));
                    ph += p0[i + k] / (1 + pow(10, (r[i + k] - r[j + h]) / 400));
                }
                p1[j] = p0[j] * pj;
                p1[j + h] = p0[j + h] * ph;
            }
        }
        swap(p0, p1);
    }
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(9) << p0[i] << '\n';
    }
    cout << flush;
    return 0;
}
