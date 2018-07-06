#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  string s1,s2;
  cin>>s1>>s2;
  for(int i=0;i<s1.length();i++){
    if(s1[i]=='@'){
      if(s2[i]=='a'||s2[i]=='t'||s2[i]=='c'||s2[i]=='o'||s2[i]=='d'||s2[i]=='e'||s2[i]=='r'){
        s1[i]=s2[i];
      }
      else if(s2[i]=='@') s1[i]='@';
    }
    if(s2[i]=='@'){
      if(s1[i]=='a'||s1[i]=='t'||s1[i]=='c'||s1[i]=='o'||s1[i]=='d'||s1[i]=='e'||s1[i]=='r'){
        s2[i]=s1[i];
      }
      else if(s1[i]=='@') s2[i]='@';
    }
  }
  if(s1==s2) cout<<"You can win"<<endl;
  else cout<<"You will lose"<<endl;
  return 0;
}
