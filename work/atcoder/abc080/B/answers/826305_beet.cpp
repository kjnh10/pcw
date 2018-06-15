#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  int x,c=0;
  string s;
  cin>>x;
  s=to_string(x);
  for(int i=0;i<(int)s.size();i++) c+=s[i]-'0';
  cout<<(x%c==0?"Yes":"No")<<endl;
  return 0;
}
