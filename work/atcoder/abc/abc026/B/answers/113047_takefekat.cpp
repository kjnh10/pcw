#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {

    ll N;
    cin >> N;
    vector<ll> a(N+1,0);

    for(int i=0; i<N; i++) {
	cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    // pi r^2
    double ans = 0;
    
    for(int i=0; i<=N; i++) {
	if(i&1) ans -= a[i]*a[i];
	else    ans += a[i]*a[i];
    }
    ans *= M_PI;
    printf("%.10lf\n",abs(ans));

    return 0;
}
