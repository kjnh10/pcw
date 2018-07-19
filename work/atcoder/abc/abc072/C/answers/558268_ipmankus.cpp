#include<bits/stdc++.h>
using namespace std;
long long frek[200003];
int main()
{
    long long i,n,x,ans=-1;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        frek[x-1]++;
        frek[x]++;
        frek[x+1]++;
        ans=max(ans,frek[x]);
         ans=max(ans,frek[x+1]);
          ans=max(ans,frek[x-1]);
    }
    cout<<ans<<endl;
}
