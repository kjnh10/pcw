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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

template<class Str>
vector<int> mp(Str s) {
    int n = (int)s.size();
    vector<int> R(n+1); R[0] = -1;
    for (int i = 0, j = -1; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) j = R[j];
        j++;
        R[i+1] = j;
    }
    return R;
}

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    bool allsame = true;
    for (int i = 0; i < n; i++) {
        if (s[0] != s[i]) {
            allsame = false;
            break;
        }
    }
    if (allsame) {
        printf("%d\n", n);
        printf("%d\n", 1);
        return 0;
    }

    auto table = mp(s);
    int fr = n - table[n];
    if (fr == n or n % fr) {
        printf("%d\n", 1);
        printf("%d\n", 1);
        return 0;
    }
    
    bool ok[n+1];
    fill_n(ok, n+1, true);
    ok[0] = false; ok[n] = false;
    for (int i = 1; i < n; i++) {
        int f = i - table[i];
        if (!(f == i or i % f)) {
            ok[i] = false;
        }
    }
    reverse(s.begin(), s.end());
    table = mp(s);
    for (int i = 1; i < n; i++) {
        int f = i - table[i];
        if (!(f == i or i % f)) {
            ok[n-i] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (ok[i]) ans++;
    }
    printf("%d\n", 2);
    printf("%d\n", ans);
    return 0;
}