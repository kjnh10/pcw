#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const ll linf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < (1 << (sz(s) - 1)); ++i) {
        int last = -1;
        ll res = 0;
        for (int j = 0; j + 1 < sz(s); ++j) {
            if ((i & (1 << j)) != 0) {
                ll cur = 0;
                for (int z = last + 1; z <= j; ++z) {
                    cur = cur * 10 + s[z] - '0';
                }
                res += cur;
                last = j;
            }
        }
        ll cur = 0;
        for (int j = last + 1; j < sz(s); ++j) {
            cur = cur * 10 + s[j] - '0';
        }
        res += cur;
        ans += res;
    }
    cout << ans << endl;
    return 0;
}
