#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  bool flag=true;
  string s;cin>>s;
  for(int i=0;i<s.length();i++){
      if(s[i]=='o'||s[i]=='k'||s[i]=='u') continue;
      else if(s[i]=='c'&&i<s.length()-1){
          i++;
          if(s[i]=='h') continue;
          else flag=false;
      }
      else flag=false;
  }
  if(flag) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}