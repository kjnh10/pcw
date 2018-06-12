#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vl> mat;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

int N;
vl A,B;
ll ans = 0;

void test(int x) {
    vl a,b;
    ll M = 1LL<<(x+1);
    F0R(i,N) {
        a.pb(A[i]%M);
        b.pb(B[i]%M);
    }
    sort(all(a)), sort(all(b));
    
    ll ret = 0;
    int lo = N, hi = N;
    for (ll t: a) {
        if (t < M/2) {
            while (lo > 0 && t+b[lo-1] >= M/2) lo --;
            while (hi > 0 && t+b[hi-1] >= M) hi --;
            ret += hi-lo;
        } else break;
    }
    
    for (auto& x: a) x ^= M/2;
    sort(all(a));
    for (auto& x: b) x ^= M/2;
    sort(all(b));
    
    lo = N, hi = N;
    for (ll t: a) {
        if (t < M/2) {
            while (lo > 0 && t+b[lo-1] >= M/2) lo --;
            while (hi > 0 && t+b[hi-1] >= M) hi --;
            ret += hi-lo;
        } else break;
    }
    
    if (ret&1) ans ^= M/2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; A.resize(N), B.resize(N);
    F0R(i,N) {
        cin >> A[i];
        // A[i] = rand();
    }
    F0R(i,N) {
        // B[i] = rand();
        cin >> B[i];
    }
    F0R(i,29) test(i);
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)