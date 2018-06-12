#include<bits/stdc++.h>
using namespace std;

int n,m;
map<string,int> mp;



int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
       string s;
       cin>>s;
       mp[s]++;
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        mp[s]--;
    }
    int ans=0;
    for (map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
        ans=max(ans,it->second);
    cout<<ans<<endl;
}
