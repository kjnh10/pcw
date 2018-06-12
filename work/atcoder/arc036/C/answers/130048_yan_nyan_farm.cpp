#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,day=-1,flag=true;
    cin>>n>>k;
    int t[n];cin>>t[0]>>t[1];
    for(int i=2; i<n; i++){
        cin>>t[i];
        if(t[i]+t[i-1]+t[i-2]<k&&flag){
            day=i+1;
            flag=false;
        }
    }
    cout<<day<<endl;
    return 0;
}
