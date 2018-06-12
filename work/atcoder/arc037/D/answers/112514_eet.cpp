#include<bits/stdc++.h>
using namespace std;
struct UnionFind{
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int size){init(size);}
  void init(int size){
    r.resize(size,0);
    p.resize(size,0);
    for(int i=0;i<size;i++) r[i]=1,p[i]=i;
  }
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }
};
int main(){
  int n,m;
  cin>>n>>m;
  int e[n];
  memset(e,0,sizeof(e));
  UnionFind uf(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    e[u]++;e[v]++;
    uf.unite(u,v);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(uf.find(i)!=i) continue;
    int tmp=0,res=0;
    for(int j=0;j<n;j++)
      if(uf.find(j)==i) tmp++,res+=e[j];
    if((tmp-1)*2==res) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
