#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 1000000000000000000LL //1e18
#define SIZE 200010

/* UnionFind */

struct UnionFind{
  vector<int> data;
  vector<int> si;
  UnionFind(int s):data(s,-1),si(s,1) {}
  
  bool set(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y) return false;
    data[y]=x;
    si[x] += si[y];
    si[y] = 0;
    return true;
  }
  
  bool check(int x,int y){
    x=root(x);
    y=root(y);
    return x==y;
  }
  
  int root(int x){
    if(data[x]==-1) return x;
    return data[x]=root(data[x]);
  }

  int size(int x){
    return si[root(x)];
  }
};

int n,m,q;

int main(){
  int a,b,y,v,w;
  int ans[SIZE];
  
  pair<int,pair<int,int> > way[SIZE];
  pair<pair<int,int>,int> query[SIZE];
  
  scanf("%d%d",&n,&m);

  for(int i=0;i<m;i++){
    scanf("%d%d%d",&a,&b,&y);
    a--;
    b--;
    way[i] = {y,{a,b}};
  }

  scanf("%d",&q);

  for(int i=0;i<q;i++){
    scanf("%d%d",&v,&w);
    v--;
    query[i] = {{w,v},i};
  }

  sort(way,way+m,greater<pair<int,pair<int,int> > >());
  sort(query,query+q,greater<pair<pair<int,int>,int> >());

  UnionFind uf(n);

  int t = 0;
  
  for(int i=0;i<q;i++){

    while(t<m && way[t].first > query[i].first.first){
      uf.set(way[t].second.first,way[t].second.second);
      t++;
    }

    ans[query[i].second] = uf.size(query[i].first.second);
  }

  for(int i=0;i<q;i++){
    printf("%d\n",ans[i]);
  }
    
  
  return 0;
}
