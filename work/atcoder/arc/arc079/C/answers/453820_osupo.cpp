#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) {return (n==0)?1:10*TEN(n-1);}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b); a--; b--;
        g[b].push_back(a);
    }

    for (int d: g[n-1]) {
        for (int e: g[d]) {
            if (e == 0) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
