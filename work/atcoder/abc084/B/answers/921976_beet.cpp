#include<bits/stdc++.h>
using namespace std;
using Int = long long;
void no(){cout<<"No"<<endl;exit(0);}
signed main(){
  Int a,b;
  string s;
  cin>>a>>b>>s;
  if(s[a]!='-') no();
  for(Int i=0;i<a+b+1;i++){
    if(i==a) continue;
    if(!isdigit(s[i])) no();
  }
  cout<<"Yes"<<endl;
  return 0;
}
