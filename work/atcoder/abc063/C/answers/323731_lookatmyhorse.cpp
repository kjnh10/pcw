#include <bits/stdc++.h>

using namespace std;

int n,i,k,sum,mn=0x3f3f3f3f;

int main() 
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>k;
        sum+=k;
        if (k<mn && k%10!=0) mn=k;
    }
    if (sum%10!=0) cout<<sum; else if (mn!=0x3f3f3f3f) cout<<sum-mn; else cout<<0;
}