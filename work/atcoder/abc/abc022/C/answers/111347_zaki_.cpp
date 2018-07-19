#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = numeric_limits<ll>::max() / 2;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m;cin>>n>>m;
  std::vector<ll> vec;
  ll d[n+1][n+1],kyori[n+1];
  for(int i=0;i<n;i++)for(int j=0;j<n;j++){
      if(i!=j)d[i][j]=INF;
      else d[i][j]=0;
  }
  for(int i=0;i<m;i++){
      ll u,v,l;cin>>u>>v>>l;
      u--;v--;
      if(u!=0&&v!=0){
          d[u][v]=l;
          d[v][u]=l;
      }
      else if(u==0){
          kyori[v]=l;
          vec.push_back(v);
      }
      else if(v==0){
          kyori[u]=l;
          vec.push_back(u);
      }
  }
  for(int k=0;k<n;k++){
      for(int i=0;i<n;i++)for(int j=0;j<n;j++){
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
  }
  ll res=INF;
  for(int i=0;i<(int)vec.size();i++)for(int j=i+1;j<(int)vec.size();j++){
      res=min(res,d[vec[i]][vec[j]]+kyori[vec[i]]+kyori[vec[j]]);
  }
  if(res>1e9){
      cout<<-1<<endl;
      return 0;
  }
  cout<<res<<endl;
  return 0;
}

