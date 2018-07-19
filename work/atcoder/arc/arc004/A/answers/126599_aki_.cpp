#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    double x[n+1]={},y[n+1]={};
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    double res=-1;
    for(int i=0;i<n;i++)for(int j=1;j<n;j++){
        res=max(res,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
    cout<<fixed<<setprecision(10)<<sqrt(res)<<endl;
}