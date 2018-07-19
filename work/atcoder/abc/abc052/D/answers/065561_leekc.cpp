#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;
#define pi 3.14159265358979323846264
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vl vector <long long>
#define vpii vector <pair <int, int> >
#define ll long long
#define fi first
#define se second
ll n, a, b, ar[100005];
ll ans;
int main() {
    scanf("%lld %lld %lld", &n, &a, &b);
    for (int i=1;i<=n;i++) scanf("%lld", &ar[i]);
    for (int i=2;i<=n;i++) ans+=min((ar[i]-ar[i-1])*a, b);
    printf("%lld\n", ans);
    return 0;
}