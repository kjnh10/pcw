#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int n,a,b,ans=0;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        int x=i;
        int sum=0;
        while(x){
            sum+=x%10;
            x=x/10;
        }
        if(sum>=a&&sum<=b) ans+=i;
    }
    cout<<ans<<endl;
    return 0;
}
