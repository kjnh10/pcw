#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <iterator>
using namespace std;

long long M=1000000007;
long long INF=4000000000000000001;
typedef pair<int,int> pii;

vector<double> mem;
double solve(int n){
  if(mem[n]>0)return mem[n];
  if(n==0)return 0;
  double res=1000000000000000;
  for(int i=0;i<14;++i){
    int a=n&(1<<i),b=n&(1<<(i+1)),c=n&(1<<(i+2));
    int t=0;
    t+=a>0;
    t+=b>0;
    t+=c>0;
    if(t==3){
      res=min(res,1.0+solve(n-a)/3.0+solve(n-b)/3.0+solve(n-c)/3.0);
    }
    if(t==1)res=min(res,3.0+solve(n-a-b-c));
    if(t==2){
      double tmp=0;
      if(a>0)tmp+=solve(n-a);
      if(b>0)tmp+=solve(n-b);
      if(c>0)tmp+=solve(n-c);
      res=min(res,1.5+tmp/2.0);
    }
  }
  mem[n]=res;
  return res;
}

int main(int argc, char const *argv[]) {
  int n;cin>>n;
  int b=0;
  for(int i=0;i<n;++i){
    int tmp;cin>>tmp;
    b|=(1<<tmp);
  }
  mem = vector<double>(1<<16);
  cout<<setprecision(20)<<solve(b)<<endl;
  return 0;
}
