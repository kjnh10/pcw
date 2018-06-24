#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef long double ldb;
typedef pair<int,int> pii;

LL A[51];
vector<pii> ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>A[i];
    int mi = 0, ma = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(A[mi]>A[i])
            mi = i;
        if(A[ma]<A[i])
            ma = i;
    }
    if(ma && abs(A[ma])>=abs(A[mi]))
    {
        for(int i = 2; i <= n; ++i)
        {
            while(A[i]<A[i-1])
            {
                A[i] += A[ma];
                ans.emplace_back(ma, i);
                if(A[i]>A[ma])
                    ma = i;
            }
        }
    }
    else if(abs(A[mi])>A[ma])
    {
        for(int i = n-1; i >= 1; --i)
        {
            while(A[i]>A[i+1])
            {
                A[i] += A[mi];
                ans.emplace_back(mi, i);
                if(A[i]<A[mi])
                    mi = i;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(pii i:ans)
        cout<<i.first<<' '<<i.second<<endl;
    return 0;
}
