#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long int; using f64 = double; using str = string;
template <typename T> using vec = vector<T>;
template <typename T> using heap = priority_queue<T, vec<T>, greater<T>>;
#define times(n, i) for (i32 i = 0; i < (n); ++i)
#define range(a, b, i) for (i32 i = (a); i < (b); ++i)
#define upto(a, b, i) for (i32 i = (a); i <= (b); ++i)
#define downto(a, b, i) for (i32 i = (a); i >= (b); --i)
#define all(xs) (xs).begin(), (xs).end()
#define sortall(xs) sort(all(xs))
#define reverseall(xs) reverse(all(xs))
#define uniqueall(xs) (xs).erase(unique(all(xs)), (xs).end())
#define even(x) (((x) & 1) == 0)
#define odd(x) (((x) & 1) == 1)
#define append emplace_back
const i64 MOD = 1000000007;

template <typename T> tuple<T, T, T> gcdext(T a, T b) {
    T s0 = 1, s1 = 0;
    T t0 = 0, t1 = 1;
    T q = 1;
    while (b != 0) {
        q = a / b;
        swap(a, b); b = b % a;
        swap(s0, s1); s1 = s1 - q*s0;
        swap(t0, t1); t1 = t1 - q*t0;
    }
    return a < 0 ? make_tuple(-a, -s0, -t0) : make_tuple(a, s0, t0);
}
template <typename T> T invmod(T n, T m) {
    auto gxy = gcdext(n, m);
    auto g = get<0>(gxy), x = get<1>(gxy), y = get<2>(gxy);
    if (g != 1 || m == 0) throw domain_error(NULL);
    return (x+m)%m;
}
vec<i64> facts;
template <typename T> void initfacts(T n, T m) {
    facts = vec<i64>(n+1); facts[0] = 0; facts[1] = 1;
    upto(2, n, i) { facts[i] = (facts[i-1] * i) % m; }
}
template <typename T> T combmod(T n, T r, T m) {
    if (n<0 || r<0 || n<r) return 0;
    if (r == 0 || n == r) return 1;
    return ((facts[n]*invmod(facts[n-r], m) % m) * invmod(facts[r], m)) % m;
}

i32 main()
{
    i64 n, k; cin >> n >> k;
    initfacts(n+k, MOD);
    cout << combmod(k+n-1, n-1, MOD) << endl;

    return 0;
}