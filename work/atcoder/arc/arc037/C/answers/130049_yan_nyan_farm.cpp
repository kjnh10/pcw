#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,sum=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int in;
        cin>>in;
        sum+=((in>80)?0:80-in);
    }
    cout<<sum<<endl;
    return 0;
}
