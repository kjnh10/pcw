#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    int d[n+1],sum=0,ma=-1;
    for(int i=0;i<n;i++){
        cin>>d[i];
        sum+=d[i];
        ma=max(ma,d[i]);
    }
    int res=sum-ma;
    cout<<sum<<endl;
    if(res>=ma) cout<<0<<endl;
    else cout<<ma-res<<endl;
}
