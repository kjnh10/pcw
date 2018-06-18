#include<bits/stdc++.h>
#define N 100010
#define ll long long
#define inf 1e9
#define M 1000000007
#define pii pair<ll, ll>

using namespace std;
map <int,int>mp;
ll mulmod(ll a,ll b,ll c)
{
	return ((((a>>20)*b%c)<<20)+(a&((1<<(20))-1))*b)%c;
}
ll moddexp(ll a, ll b)//This function calculates a to the power b mod M
{
    ll res=1,y=a;
    while(b>0)
    {
        if(b&1)
            res=mulmod(res,y,M);
        y=mulmod(y,y,M);
        b/=2;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    if(n&1)
    {
        int c=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int temp=(*it).first;
            if(temp!=c)
                {
                    cout<<0<<endl;
                    return 0;
                }
            if(c)
            {
                if(mp[temp]!=2)
                {
                    cout<<0<<endl;
                    return 0;
                }
            }
            else
            {
                if(mp[temp]!=1)
                {
                    cout<<0<<endl;
                    return 0;
                }
            }
            c+=2;
        }
    }
    else
    {
        int c=1;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int temp=(*it).first;
            if(temp!=c)
            {
                cout<<0<<endl;
                return 0;
            }
            if(mp[temp]!=2)
            {
                cout<<0<<endl;
                return 0;
            }
            c+=2;
        }
    }

        ll temp=n/2;
        ll ans=moddexp(2,temp);
        cout<<ans<<endl;

    return 0;
}
