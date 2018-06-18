#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin>>x;
    long long n=0;
    for(int i=1;i<=x;i++){
        n=i*(i+1)/2;
        if(n>=x){
            cout<<i<<endl;
            return 0;
        }
    }
}

