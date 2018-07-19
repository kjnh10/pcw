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
typedef pair<long long,long long> pll;

int n;
vector<vector<long long>> f;
vector<vector<long long>> mem;
vector<vector<long long>> dp;
long long solve(int i,int j){
  if(dp[i][j]>-(1ll<<60))return dp[i][j];
  if(i==n-1){
    return 0;
  }
  long long res;
  if(j==n-1){
    res=solve(i+1,j)+mem[i][j];
  }
  else if(j==i){
    res=max(solve(i+1,j+1)+mem[i][j],solve(i,j+1));
  }
  else{
    res=max(solve(i+1,j)+mem[i][j],solve(i,j+1));
  }
  dp[i][j]=res;
  // cout<<i<<" "<<j<<" "<<res<<endl;
  return res;
}

int main(int argc, char const *argv[]) {
  cin>>n;
  f=vector<vector<long long>>(n,vector<long long>(n));
  dp=vector<vector<long long>>(n,vector<long long>(n,-(1ll<<60)));
  mem=vector<vector<long long>>(n,vector<long long>(n,0));
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j)cin>>f[i][j];
  }
  for(int i=0;i<n;++i){
    for(int j=i+1;j<n;++j)mem[i][j]=mem[i][j-1]+f[i][j];
  }
  long long res=0;
  for(int i=0;i<n;++i)res=max(res,solve(0,i));
  cout<<2*res<<endl;


  return 0;
}
