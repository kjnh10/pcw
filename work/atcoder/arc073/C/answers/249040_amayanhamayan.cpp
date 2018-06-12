#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)


typedef long long ll;
int N, T, t[201010];
//-----------------------------------------------------------------------------------
int main() {
    cin >> N >> T;
    rep(i, 0, N) scanf("%d", &t[i]);

    ll ans = 0;
    int pre = t[0];
    rep(i, 1, N) {
        ans += min(T, t[i] - pre);
        pre = t[i];
    }
    ans += T;

    cout << ans << endl;
}