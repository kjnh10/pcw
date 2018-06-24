#include <bits/stdc++.h>

// limit
#define mod1 22439423LL
#define mod2 42342432LL
#define mod3 56454765LL
#define mod4 66867574LL
#define oo 1000000007LL
#define OO 1000000000000000007LL
#define maxN 100007

// loop
#define fto(i, x, y) for(int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for(int i = (x); i >= (y); --i)
#define ftoa(i, x, y, a) for(int i = (x); i <= (y); i += a)
#define fdtoa(i, x, y, a) for(int i = (x); i >= (y); i -= a)
#define ftosqrt(i, x, y) for(int i = (x); i*i <= (y); ++i)
#define ftoit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define fdtoit(rit, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)

// debug
#define debug cout << "*" << endl;
#define bug1d(a, x, y) { cout << #a << ": "; fto(_, x, y) cout << a[_] << ' '; cout << endl; }
#define bug2d(a, x, y, u, v) { cout << #a << ": " << endl; fto(i, x, y) {fto(j, u, v) cout << a[i][j] << ' '; cout << endl;}; cout << endl;}
#define bug(a) cout << #a << " = " << a << endl;
#define bug2(a, b) cout << #a << " = " << a << "; "; cout << #b << " = " << b << endl;
#define bug3(a, b, c) cout << #a << " = " << a << "; "; cout << #b << " = " << b << "; "; cout << #c << " = " << c << endl;

// operation
#define mp make_pair
#define pb push_back
#define pf push_front
// structure
#define ii pair<int, int>
#define iii pair<ii, int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define matrix vector<vi>

// get value
#define FF first
#define SS second

// data type
#define ll long long
#define ull unsigned long long

// function
#define lb lower_bound
#define ub upper_bound

// const value
#define pi 3.14159265358979323846264338327950288419716939937510

using namespace std;

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T min(T a, T b, T c, T d) {
    return min(a, min(b, min(c, d)));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
T max(T a, T b, T c, T d) {
    return max(a, max(b, max(c, d)));
}

bool cmp(const ii& a, const ii& b) {return (a.FF > b.FF || (a.FF == b.FF && a.SS >= b.SS));}
ll GCD(ll a, ll b) {return (a%b) ? GCD(b, a%b) : b;}

const string namePro = "tmp";

ll a[maxN];

int main() {

    int n; scanf("%d", &n);
    fto (i, 1, n) scanf("%lld", &a[i]);

    ll res1 = 0LL;
    ll res2 = 0LL;

    ll preSum = -1LL;
    ll sum = 0LL;
    fto (i, 1, n) {
        sum += a[i];
        if (sum >= 0LL && preSum > 0LL) {
            res1 += sum+1LL;
            sum = -1LL;
        }
        else if (sum <= 0LL && preSum < 0LL) {
            res1 -= sum-1LL;
            sum = 1LL;
        }
        preSum = sum;
    }

    preSum = 1LL;
    sum = 0LL;
    fto (i, 1, n) {
        sum += a[i];
        if (sum >= 0LL && preSum > 0LL) {
            res2 += sum+1LL;
            sum = -1LL;
        }
        else if (sum <= 0LL && preSum < 0LL) {
            res2 -= sum-1LL;
            sum = 1LL;
        }
        preSum = sum;
    }

    cout << min(res1, res2) << endl;
    return 0; 
}