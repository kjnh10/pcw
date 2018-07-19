#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct BiMatch{
  Int L,R;
  vector<vector<Int> > G;
  vector<Int> match,level;
  
  BiMatch(){}
  BiMatch(Int L,Int R):L(L),R(R),G(L+R),match(L+R,-1),level(L){}
  
  void add_edge(Int u,Int v){
    G[u].push_back(v+L);
    G[v+L].push_back(u);
  }
  
  bool bfs(){
    queue<Int> q;
    for(Int i=0;i<L;i++){
      level[i]=-1;
      if(match[i]<0){
	level[i]=0;
	q.emplace(i);
      }
    }
    while(!q.empty()){
      Int v=q.front();q.pop();
      for(Int u:G[v]){
	Int w=match[u];
	if(w<0) return true;
	if(level[w]<0){
	  level[w]=level[v]+1;
	  q.emplace(w);
	}
      }
    }
    return false;
  }

  bool dfs(Int v){
    for(Int u:G[v]){
      Int w=match[u];
      if(w<0||(level[w]>level[v]&&dfs(w))){
	match[v]=u;
	match[u]=v;
	return true;
      }
    }
    return false;
  }
  
  Int build(){
    Int res=0;
    while(bfs())
      for(Int i=0;i<L;i++)
	if(match[i]<0&&dfs(i))
	  res++;
    return res;
  }
  
};

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n),b(n);
  vector<Int> c(n),d(n);
  for(Int i=0;i<n;i++) cin>>a[i]>>b[i];
  for(Int i=0;i<n;i++) cin>>c[i]>>d[i];
  
  BiMatch bm(n,n);
  for(Int i=0;i<n;i++){
    for(Int j=0;j<n;j++){
      if(a[i]<c[j]&&b[i]<d[j]) bm.add_edge(i,j);
    }
  }

  cout<<bm.build()<<endl;
  return 0;
}
