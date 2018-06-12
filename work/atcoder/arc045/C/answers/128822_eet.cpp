#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;
  bool f=0;
  while(cin>>s){
    if(f) cout<<" ";
    f=1;
    if(s=="Left") cout<<"<";
    if(s=="Right") cout<<">";
    if(s=="AtCoder") cout<<"A";
  }
  cout<<endl;
  return 0;
}
