#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<numeric>
#include<queue>
using namespace std;

vector<int> nodes;
int countUp(vector< pair<int, int> > edges, vector<int> mincost, int cost, int pos, int goal){
  if( cost == mincost[ pos ] && nodes[ pos ] >= 0 ) return nodes[ pos ];
  if( cost != mincost[ pos ] ) return 0;

  if( pos == goal ) return 1;

  long long int cnt = 0;
  for(int i=0; i<edges.size(); i++){
    if( pos == edges[i].first ){
      cnt += countUp(edges, mincost, cost + 1, edges[i].second, goal);
      nodes[pos] = cnt;
    }
    if( pos == edges[i].second ){
      cnt += countUp(edges, mincost, cost + 1, edges[i].first, goal);
      nodes[pos] = cnt;
    }
  }
  cnt %= 1000000007;

  return cnt;

}

int main(void) {

  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  a--; b--;
  int m;
  cin >> m;
  vector< pair<int, int> > p(m);
  for(int i=0; i<m; i++){
    int x, y;
    cin >> x >> y;
    p[i].first = x-1;
    p[i].second = y-1;
  }

  vector<int> cost(n, 1000000000);
  cost[a] = 0;

  queue< pair<int, int> > q;
  q.push( make_pair(a, 0) );
  while( !q.empty() ){

    pair<int, int> pos = q.front();
    q.pop();
    for(int i=0; i<m; i++){
      int x = p[i].first;
      int y = p[i].second;
      if( pos.first == x && pos.second + 1 < cost[ y ] ){
        cost[ y ] = pos.second + 1;
        q.push( make_pair(y, pos.second + 1) );
      }
      if( pos.first == y && pos.second + 1 < cost[ x ] ){
        cost[ x ] = pos.second + 1;
        q.push( make_pair(x, pos.second + 1) );
      }
    }

  }
  // cerr << cost[ b ] << endl;
  // for(int i=0; i<n; i++) cerr << cost[i] << " ";
  // cerr << endl;

  nodes.resize(n, -1);
  cout << countUp(p, cost, 0, a, b) << endl;

  return 0;
}








//
