#include<iostream>
using namespace std;
int main(){
long long a,b,c;
cin>>a>>b>>c;
while(1){
if(c%a==0&&c%b==0)break;
c++;
}
cout<<c<<endl;
}