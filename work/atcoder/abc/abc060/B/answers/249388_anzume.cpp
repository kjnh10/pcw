#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cctype>
#define rep(i,a,b) for(int (i)=(a);i<(b);i++)
#define INF 1000000000
using namespace std;
bool debug=false;

int main(){
  long long a,b,c;
  long long sum=0;
  cin>>a>>b>>c;
  bool ok=false;
  for(int i=1;i<=110;i++){
    sum+=a;
    if(sum%b==c)ok=true;
  }
  if(ok)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
