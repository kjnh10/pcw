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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

int n;
V<int> p;
VV<int> g;

array<int, 2> chk(const V<int> &a, int v) {
    set<int> s;
    for (int d: g[v]) s.insert(a[d]);
    array<int, 2> ans;
    int u = 0;
    while (s.count(u)) u++;
    ans[0] = u;
    u++;
    while (s.count(u)) u++;
    ans[1] = u;
    return ans;
}

V<int> pre(const V<int> &b) {
    V<int> a = b;
    queue<int> q;
    V<ll> deg = V<ll>(n);
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) continue;
        for (int d: g[i]) if (a[d] == -1) deg[i]++;
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        a[v] = chk(a, v)[0];
        if (a[p[v]] != -1) continue;
        deg[p[v]]--;
        if (!deg[p[v]]) q.push(p[v]);
    }
    return a;
}

bool solve() {
    scanf("%d", &n);
    p = V<int>(n);
    g = VV<int>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &(p[i])); p[i]--;
        g[p[i]].push_back(i);
    }
    auto a = pre(V<int>(n, -1));
    int v = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            v = i;
            break;
        }
    }
    
    auto p = chk(a, v);
    a[v] = p[0];
    if (chk(pre(a), v)[0] == a[v]) {
        return true;
    }
    a[v] = p[1];
    if (chk(pre(a), v)[0] == a[v]) {
        return true;
    }
    return false;
}

int main() {
    if (!solve()) {
        cout << "IM";
    }
    cout << "POSSIBLE" << endl;
}
