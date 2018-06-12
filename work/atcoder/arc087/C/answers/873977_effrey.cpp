#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pii pair<int, int>
#define fr(n) for (int i = 0; i < n; i++)
#define fr1(n) for (int i = 1; i <= n; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, a[100005] = {}, b, c = 0;
    cin >> n;
    fr(n) {
        cin >> b;
        if (b <= 100000) a[b]++;
    }
    fr1(100000) if (a[i] >= i) c += i;
    cout << n - c;
}
