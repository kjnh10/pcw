#include<bits/stdc++.h>
using namespace std;
int n,r=-1;
int main(){
    cin>>n;
    for(int i=0;i<=7;i++){
        if((1<<i)<=n)r=(1<<i);
    }
    cout<<r<<endl;
    return 0;
}