#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX_N=1e5;
const int MOD=1000000007;
const double EPS=1e-12;
const double PI = 3.14159265358979323846;

int a,b,c;

double f(double t){
    return a*t+b*sin(c*t*PI);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>a>>b>>c;
  double low=0,high=10000;
  for(int i=0;i<100;i++){
      double mid=(low+high)/2;
      if(f(mid)<100) low=mid;
      else high=mid;
  }
  //cout<<low<<endl;
  cout<<fixed<<setprecision(10)<<low<<endl;
}
