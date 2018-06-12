#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n,m;
  cin>>n>>m;
  int a[m];
  for(int i=0;i<m;i++) cin>>a[i];
  reverse(a,a+m);
  int x=0,p[n],u[n];
  memset(u,0,sizeof(u));
  for(int i=0;i<m;i++){
    if(u[a[i]-1]) continue;
    u[a[i]-1]=1;
    p[x++]=a[i];
  }
  for(int i=0;i<n;i++)
    if(!u[i]) p[x++]=i+1;
  for(int i=0;i<n;i++) cout<<p[i]<<endl;
  return 0;
}
