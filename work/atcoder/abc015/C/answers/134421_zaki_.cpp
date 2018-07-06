#include <bits/stdc++.h>

using namespace std;
int n,k;
int t[6][6];
bool flag=true;

void dfs(int i,int val){
    if(i==n){
        if(val==0) flag=false;
    }
    else{
        for(int j=1;j<=k;j++){
            dfs(i+1,val^t[i+1][j]);
        }
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n>>k;
  for(int i=1;i<=n;i++)for(int j=1;j<=k;j++) cin>>t[i][j];
  dfs(0,0);
  if(flag) cout<<"Nothing"<<endl;
  else cout<<"Found"<<endl;
}
