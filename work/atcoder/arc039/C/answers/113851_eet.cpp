#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string a,b,c;
  cin>>a>>b;
  int ans=stoi(a)-stoi(b);
  for(int i=0;i<3;i++){
    c=a;
    for(int j=0;j<10;j++){
      if(i+j==0) continue;
      c[i]=j+'0';
      ans=max(ans,stoi(c)-stoi(b));
    }
  }
  for(int i=0;i<3;i++){
    c=b;
    for(int j=0;j<10;j++){
      if(i+j==0) continue;
      c[i]=j+'0';
      ans=max(ans,stoi(a)-stoi(c));
    }
  }
  cout<<ans<<endl;
  return 0;
}
