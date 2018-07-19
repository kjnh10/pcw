#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    double t = 0;
    partial_sort(r.begin(), r.begin() + k, r.end(), greater<>());
    for (int i = k - 1; i >= 0; i--) {
        t = (t + r[i]) * 0.5;
    }

    cout << fixed << t << endl;

    return 0;
}
