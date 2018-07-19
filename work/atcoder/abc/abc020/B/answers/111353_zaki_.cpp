#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  string a,b,s="";cin>>a>>b;
  s+=a;s+=b;
  int num=stoi(s);
  num*=2;
  cout<<num<<endl;
}