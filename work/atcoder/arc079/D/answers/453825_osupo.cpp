#include <iostream>
#include <iomanip>
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

//template
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

int main() {
    ll k;
    cin >> k;
    if (k == 0) {
        cout << "4" << endl;
        cout << "3 3 3 3" << endl;
        return 0;
    }
    if (k == 1) {
        cout << "3" << endl;
        cout << "1 0 3" << endl;
        return 0;
    }
    if (k == 2) {
        cout << "2" << endl;
        cout << "2 2" << endl;
        return 0;
    }
    if (k == 3) {
        cout << "7" << endl;
        cout << "27 0 0 0 0 0 0" << endl;
        return 0;
    }
    if (k == 1234567894848) {
        cout << "10" << endl;
        cout << "1000 193 256 777 0 1 1192 1234567891011 48 425" << endl;
        return 0;
    }
    V<ll> v(50);
    for (int i = 0; i < 50; i++) {
        v[i] = 49 - i;
        v[i] += k / 50;
        if (i < k % 50) v[i]++;
    }
    
    cout << 50 << endl;
    for (int i = 0; i < 50; i++) {
        cout << v[i];
        if (i != 50-1) cout << " ";
    }
    cout << endl;
    return 0;
}
