#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> d;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        d.push_back(t);
    }
    sort(d.begin(),d.end(),greater<int>());
    int ans=0;
    for(int i=0;i<k;i++){
        ans+=d[i];
    }
    cout<<ans<<endl;
    return 0;
}