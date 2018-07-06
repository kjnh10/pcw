#include <bits/stdc++.h>

using namespace std;

bool judge(char c){
    return (c=='a'||c=='t'||c=='c'||c=='o'||c=='d'||c=='e'||c=='r');
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s,t;cin>>s>>t;
  int len=s.length();
  bool res=true;
  for(int i=0;i<len;i++){
      if(s[i]!=t[i]){
          if(s[i]=='@'&&judge(t[i])) continue;
          else if(t[i]=='@'&&judge(s[i]))continue;
          else res=false;
      }
  }
  if(res) cout<<"You can win"<<endl;
  else cout<<"You will lose"<<endl;
}