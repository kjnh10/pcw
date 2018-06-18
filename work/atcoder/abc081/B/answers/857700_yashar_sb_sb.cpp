#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef long double ldb;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int ans = 1e9;
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        int c = 0;
        while(a%2==0)
        {
            ++c;
            a /= 2;
        }
        ans = min(c, ans);
    }
    cout<<ans;
    return 0;
}
