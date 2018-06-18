#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,turn=0;
    cin>>a>>b;
    int diff=(int)abs(a-b);
    if(diff%10>7){
        turn+=((int)abs(10-diff%10)+1);
        diff-=diff%10;
    }
    else if(diff%5==4){
        turn+=2;
        diff-=4;
    }
    turn+=(int)abs(diff/10)+(int)abs(diff%10/5)+diff%10%5;
    cout<<turn<<endl;
    return 0;
}

