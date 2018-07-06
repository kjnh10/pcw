#include<bits/stdc++.h>
using namespace std;
#define int long long

int N;
int solve(string str){
  if(str.length()==N){
    cout<<str<<endl;
    return 0;
  }
  else{
    solve(str+"a");
    solve(str+"b");
    solve(str+"c");
    return 0;
  }
}
signed main(){
    cin>>N;
    solve("a");
    solve("b");
    solve("c");
    return 0;
}
