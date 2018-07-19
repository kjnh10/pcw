#include <bits/stdc++.h>

using namespace std;
const int INF = numeric_limits<int>::max() / 2;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m;cin>>n>>m;
  int d[n][n];
  for(int i=0;i<n;i++)for(int j=0;j<n;j++){
      if(i==j) d[i][j]=0;
      else d[i][j]=INF;
  }
  for(int i=0;i<m;i++){
      int a,b;cin>>a>>b;
      a--;b--;
      d[a][b]=1;
      d[b][a]=1;
  }
  for(int k=0;k<n;k++){
      for(int i=0;i<n;i++)for(int j=0;j<n;j++){
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
  }
 for(int i=0;i<n;i++){
     int res=0;
     for(int j=0;j<n;j++)if(d[i][j]==2) res++;
     cout<<res<<endl;
 }
}
