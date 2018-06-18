#include<bits/stdc++.h>
using namespace std;

int main(){
    int y;
    bool judge;
    cin>>y;
    if(y%100==0){
        if(y%400==0){
            judge=true;
        }
        else{
            judge=false;
        }
    }
    else if(y%4==0){
        judge=true;
    }else{
        judge=false;
    }
    if(judge){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
