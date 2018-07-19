#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,l;cin>>n>>l;
  int tab=1,c=0;
  string s;cin>>s;
  for(int i=0;i<n;i++){
      if(s[i]=='+'){
          tab++;
          if(tab>l){c++;tab=1;}
      }
      else{
          tab--;
      }
  }
  cout<<c<<endl;
}
