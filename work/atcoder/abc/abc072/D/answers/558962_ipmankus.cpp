#include<bits/stdc++.h>
using namespace std;
long long x[100003];
int main()
{
    long long i,n,z=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>x[i];
    }
    for(i=1;i<=n;++i)
    {
        if(x[i]==i)
        {
            swap(x[i],x[i+1]);
            z++;
        }
    }
    cout<<z<<endl;
    
}