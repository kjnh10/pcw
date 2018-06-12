#include <bits/stdc++.h>
using namespace std;

int n,m;
int u[10010],v[10010];

int uni[110];

void init(int n){
  for(int i=0;i<n;i++){
    uni[i]=-1;
  }
}

int root(int n){
  if(uni[n]<0)return n;

  return uni[n]=root(uni[n]);
}

bool unite(int a,int b){
  a=root(a);
  b=root(b);
  if(a==b){
    uni[a]-=1000;
    return false;
  }
  if(uni[a]>uni[b])swap(a,b);

  uni[a]+=uni[b];
  uni[a]-=1000;
  uni[b]=a;
}


int main(){
  cin>>n>>m;
  int x,y;

  init(n);
  for(int i=0;i<m;i++){
      cin>>x>>y;
      x--;y--;
      unite(x,y);

      // for(int i=0;i<n;i++){
      //   cout<<"uni["<<i<<"]= "<<uni[i]<<endl;
      // }
      // cout<<endl;
  }
  int res=0;
  for(int i=0;i<n;i++){
    if(uni[i]<=-1){
      if(uni[i]%1000==(uni[i]/1000)-1)res++;
    }
  }
  cout<<res<<endl;

}
