#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

int a[3];

int main() {
    rep(i,3) cin >> a[i];
    sort(a, a+3);
    int ans = 0;
    ans = a[2]-a[1];
    a[0] += (a[2]-a[1]);
    ans += (a[2]-a[0])/2;
    if ((a[2]-a[0])%2 == 1) ans += 2;
    cout << ans << endl;
}






























