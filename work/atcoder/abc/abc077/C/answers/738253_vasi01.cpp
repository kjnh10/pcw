#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> a, b, c;
void mainp()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int aa;
        cin>>aa;
        a.push_back(aa);
    }
    for(int i=0; i<n; i++)
    {
        int aa;
        cin>>aa;
        b.push_back(aa);
    }
    for(int i=0; i<n; i++)
    {
        int aa;
        cin>>aa;
        c.push_back(aa);
    }
    
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    
    long long ret=0;
    for(int i=0; i<n; i++)
    {
        int l=0, r=n-1, ans=-1;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid]<b[i])
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        ans++;
        
        l=0, r=n-1;
        int ans2=n;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(c[mid]>b[i])
            {
                ans2=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        
        ans2=n-ans2;
        
        ret+=ans*1ll*ans2;
    }
    
    cout<<ret<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mainp();
    return 0;
}