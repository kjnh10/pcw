#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int a[n];
    int sum=0;
    for(int i=0; i<n; i++)cin>>a[i];
    sort(a,a+n,greater<int>());
    for(int i=0; i<n; i+=2){
        sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}
