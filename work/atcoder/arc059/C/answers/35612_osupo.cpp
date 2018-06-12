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
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

int main() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sm = TEN(17);
    for (int x = -200; x < 200; x++) {
        ll nw = 0;
        for (int i = 0; i < n; i++) {
            nw += (x-a[i])*(x-a[i]);
        }
        sm = min(sm, nw);
    }
    cout << sm << endl;
    return 0;
}