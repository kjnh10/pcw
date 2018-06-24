#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(Int i=0;i<h;i++) cin>>s[i];
  vector<string> t(h,string(w,'.'));
  for(Int i=0;i<h;i++){
    for(Int j=0;j<w;j++){
      if(s[i][j]!='#') continue;
      if(j+1<w&&s[i][j+1]=='#'){
	t[i][j]='#';
	t[i][j+1]='#';
      }
      if(i+1<h&&s[i+1][j]=='#'){
	t[i][j]='#';
	t[i+1][j]='#';
      }
    }
  }
  cout<<(s==t?"Yes":"No")<<endl;
  
  return 0;
}
