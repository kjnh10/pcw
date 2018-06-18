#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef long double ldb;
typedef pair<int,int> pii;

int A[200001];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n; ++i)
    {
        int inp;
        cin>>inp;
        ++A[inp];
    }
    sort(A, A+n+1);
    int ans = 0;
    for(int i = 0; i <= n-k; ++i)
        ans += A[i];
    cout<<ans;
    return 0;
}
