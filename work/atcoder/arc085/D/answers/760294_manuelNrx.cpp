#include <bits/stdc++.h>
using namespace std;

const int DIM = 2005;

int arr[DIM];

int main(void)
{
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, x, y;
    cin >> n >> x >> y;
    
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    
    cout << max(abs(arr[n] - y), (n == 1) ? -1 : abs(arr[n - 1] - arr[n]));
    
    return 0;
}
