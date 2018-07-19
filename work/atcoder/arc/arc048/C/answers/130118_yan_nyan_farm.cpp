#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if(abs(a-b)!=abs(abs(a)-abs(b))){
        cout<<abs(a-b)-1<<endl;
    }else{
        cout<<abs(a-b)<<endl;
    }
    return 0;
}
