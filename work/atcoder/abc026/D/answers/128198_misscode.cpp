#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1145141919810364364
#define REP(i,n) for (int i=0;i<(n);i++)
typedef pair<int,int> P;

signed main() {
  double PI=3.141592653589793;
  int A,B,C;
  cin>>A>>B>>C;
  double tmp1=0,tmp2=10000.0;
  for(int i=0;i<100000;i++){
    double tmp=(tmp2+tmp1)/2.0;
    double x=A*tmp+B*sin(C*tmp*PI);
    if(x>100.0) tmp2=tmp;
    else tmp1=tmp;
  }
  printf("%.10lf\n",tmp2);

//  cout<<A*tmp2+B*sin(C*tmp2*PI)<<endl;
}
