#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin>>s;
  int n=s.length(),f=1;
  for(int i=0;i<n/2;i++){
    if(s[i]=='*'||s[n-1-i]=='*') continue;
    if(s[i]==s[n-1-i]) continue;
    f=0;
    break;
  }
  cout<<(f?"YES":"NO")<<endl;
  return 0;
}
