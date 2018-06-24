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
int n, x, ans;
char s[105];
int main() {
    scanf("%d %s", &n, s);
    for (int i=0;i<n;i++) {
        if (s[i]=='I') x++;
        else x--;
        ans=max(ans,x);
    }
    printf("%d\n", ans);
    return 0;
}