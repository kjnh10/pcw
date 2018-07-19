#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=44;
const int oo=1e8;
int a[mx],b[mx],c[mx];
int f[44][440][440];
int n,ma,mb;
int solve(int i,int x,int y){
  if(f[i][x][y]!=-1)  return f[i][x][y];
  if(i==n){
    if(x*mb==y*ma && y!=0)return 0;      
    return oo;
  }
  f[i][x][y]=min(solve(i+1,x,y),c[i]+solve(i+1,x+a[i],y+b[i]));
  return f[i][x][y];
}
int main(){
  cin>>n>>ma>>mb;
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i]>>c[i];
  }
  memset(f,-1,sizeof f);
  int ans=solve(0,0,0);
  if(ans>=oo)ans=-1;
  cout<<ans<<endl;
  return 0;
}
