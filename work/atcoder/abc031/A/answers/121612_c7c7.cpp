#include<iostream>
using namespace std;
int main(){
long long a,b,c;
cin>>a>>b;
c=(a+1)*b;
a=a*(b+1);
if(a>c)cout<<a<<endl;
else cout<<c<<endl;
}