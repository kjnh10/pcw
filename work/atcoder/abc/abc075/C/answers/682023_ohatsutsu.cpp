#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define MAX 100005
 
int V,E;
vector<int> G[MAX];
 
int depth[MAX];
int cnt[MAX];
int visited[MAX];
 
vector<P> ans;
 
void dfs(int pos,int prev){
  visited[pos]=true;
  for(int i=0;i<(int)G[pos].size();i++){
    int to=G[pos][i];
    if(to==prev)continue;
    if(!visited[to]){
      depth[to]=depth[pos]+1;
      dfs(to,pos);
      cnt[pos]+=cnt[to];
      if(cnt[to]==0)ans.push_back( P( min(pos,to) , max(pos,to) ) );
    }else if(depth[to]<depth[pos]){
      cnt[pos]++;
      cnt[to]--;
    }
  }
}
 
int main(){
  scanf("%d %d",&V,&E);
  for(int i=0;i<E;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0,-1);
  sort(ans.begin(),ans.end());
   
  cout<<ans.size()<<endl;
  return 0;
}
