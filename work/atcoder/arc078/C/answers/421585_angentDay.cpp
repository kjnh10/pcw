#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    int n;
    cin >> n;
    VL a(n);
    ll sum = 0;
    REP(i,n){
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    ll ans = 1e18, x = 0;
    REP(i,n-1){
        x += a[i];
        ans = min(ans, abs(sum - 2 * x));
    }
    cout << ans << endl;

    return 0;
}