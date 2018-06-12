#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int main(){
  int N; cin>>N;
  int cnt=0;
  rep(i,N){
    int a; cin>>a;
    while(a%2==0){
      a/=2;
      cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}
