#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define x first
#define y second
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define mod 1000000007
#define maxn 100100

using namespace std;

ll n, a[300100], dp[300100], dp2[300100], sum, mn = 1e17;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    for (int i = 1; i <= n; i++) dp[i] = dp[i-1] + a[i];
    for (int i = 1; i < n; i++) mn = min(mn, abs(sum - 2*dp[i]));
    cout << mn;
        
}