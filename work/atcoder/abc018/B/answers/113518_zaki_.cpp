#include <bits/stdc++.h>

using namespace std;

string rev(string s,int l,int r){
    string res="";
    int len=s.length();
    for(int i=0;i<l-1;i++) res+=s[i];
    for(int j=l-1;j<r;j++) res+=s[r+l-2-j];
    for(int i=r;i<len;i++) res+=s[i];
    return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;string s;cin>>s>>n;
  for(int i=0;i<n;i++){
      int l,r;cin>>l>>r;
      s=rev(s,l,r);
  }
  //s=rev(s,3,5);
  cout<<s<<endl;
}

