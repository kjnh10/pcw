#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

const int N = 222222;
int n;
int a[N];
bool v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int i = 1;
    int ans = 0;
    while(1) {
        v[i] = true;
        i = a[i];
        ans++;
        if(v[i]) {
            cout << -1 << endl;
            return 0;
        }
        if(i == 2) {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}