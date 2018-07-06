#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF -1145141919810
#define REP(i,n) for (int i=0;i<(n);i++)
typedef pair<int,int> P;

signed main(){
  int N; cin>>N;
  string str; cin>>str;
  string tmp="b";
  if(str=="b"){
    cout<<"0"<<endl;
    return 0;
  }
  for(int i=0;;i++){
    if(i!=0){
      tmp="b"+tmp+"b";
      if(tmp==str){
        cout<<3*i<<endl;
        return 0;
      }
    }
    tmp="a"+tmp+"c";
    if(tmp==str){
      cout<<3*i+1<<endl;
      return 0;
    }
    tmp="c"+tmp+"a";
    if(tmp==str){
      cout<<3*i+2<<endl;
      return 0;
    }

    if(tmp.length()>str.length()){
      cout<<"-1"<<endl;
      return 0;
    }
  }
}
