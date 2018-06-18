#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

typedef long long ll;

using namespace std;

int arr[100005];

int n;

void solve() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    int cur = 0;

    for (int i = 1; i <= n + 1; ++i) {
        cur += abs(arr[i] - arr[i - 1]);
    }

    for (int i = 1; i <= n; ++i) {
        int del = abs(arr[i] - arr[i - 1]) + abs(arr[i + 1] - arr[i]);
        int add = abs(arr[i + 1] - arr[i - 1]);

        printf("%d\n", cur - del + add);
    }
}

int main() {
    #ifdef BThero
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // BThero

    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}