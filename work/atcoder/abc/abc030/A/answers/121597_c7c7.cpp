#include<iostream>
using namespace std;
int main(){
double a,b,c,d;
cin>>a>>b>>c>>d;
b/=a;d/=c;
if(b==d)cout<<"DRAW"<<endl;
else if(b>d)cout<<"TAKAHASHI"<<endl;
else cout<<"AOKI"<<endl;
}