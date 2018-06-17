#include <bits/stdc++.h>
using namespace std;
int main() 
{
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios::sync_with_stdio(0);cin.tie(0);
    long n,x;
    map<long,long> m;
    cin>>n;
    while(n--)
    {
        cin>>x;
        m[x-1]++;
        m[x+1]++;
        m[x]++;
    }
    long h=0;
    for(auto i:m)
        h=max(h,i.second);
    cout<<h;
    return 0;
}   