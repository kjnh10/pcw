#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void re(string s){
    if(s=="Left") cout<<" <";
    else if(s=="Right") cout<<" >";
    else cout<<" A";
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;cin>>s;
  if(s=="Left") cout<<"<";
  else if(s=="Right") cout<<">";
  else cout<<"A";
  while(cin>>s){
     re(s);
  }
  cout<<endl;
}