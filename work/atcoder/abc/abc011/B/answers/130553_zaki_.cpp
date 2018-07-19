#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  string s;cin>>s;
  char a=toupper(s[0]);
  cout<<a;
  for(int i=1;i<s.length();i++){
      char b=tolower(s[i]);
      cout<<b;
  }
  cout<<endl;
}