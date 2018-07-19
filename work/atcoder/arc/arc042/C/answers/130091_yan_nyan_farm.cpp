#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int used[n+1];
    int a[m];
    fill(used,used+n+1,-1);
    for(int i=0; i<m; i++){
        cin>>a[i];
        used[a[i]]=i;
    }
    for(int i=m-1; i>=0; i--){
        if(i==used[a[i]])cout<<a[i]<<endl;
    }
    for(int i=1; i<n+1; i++){
        if(used[i]==-1){
            cout<<i<<endl;
        }
    }
    return 0;
}
