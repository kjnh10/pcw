#include <bits/stdc++.h>
using namespace std;


int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(a+b<c*2){
        cout<<x*a+y*b<<endl;
        return 0;
    }
    else{
        int price=c*2*min(x,y);
        if(x>y){
            price+=min(a,c*2)*(x-y);
        }
        else price+=min(b,c*2)*(y-x);
        cout<<price<<endl;
    }
    return 0;
}