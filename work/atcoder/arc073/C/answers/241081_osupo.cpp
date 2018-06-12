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
    int n; ll x;
    cin >> n >> x;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sm = x;
    for (int i = 0; i < n-1; i++) {
        sm += min(x, a[i+1] - a[i]);
    }
    cout << sm << endl;
    return 0;
}
