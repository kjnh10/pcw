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

i32 n, m, p, q, r;
tuple<i32,i32,i32> xyz[324];

i32 main()
{
    cin >> n >> m >> p >> q >> r;
    times(r, i) {
        i32 x, y, z; cin >> x >> y >> z;
        xyz[i] = make_tuple(x-1, y-1, z);
    }
    
    i64 ans = 0;
    times(1<<n, g) {
        i32 gcnt = 0;
        times(n, i) {
            gcnt += (g>>i) & 1;
        }
        if (gcnt != p) continue;
        vec<pair<i32, i32>> v(m);
        times(r, i) {
            i32 x = get<0>(xyz[i]);
            i32 y = get<1>(xyz[i]);
            i32 z = get<2>(xyz[i]);
            if (((g>>x) & 1) == 1) {
                v[y].second = y;
                v[y].first -= z;
            }
        }
        sortall(v);
        i64 h = 0;
        times(q, i) {
            h += -v[i].first;
        }
        ans = max(ans, h);
    }

    cout << ans << endl;
    return 0;
}