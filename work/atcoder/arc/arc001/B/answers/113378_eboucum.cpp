#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
int d[41];

int main(){
  int a,b;
  cin >> a >> b;

  queue<pii> q;
  q.push(pii(a,0));

  while(true){
    pii e = q.front(); q.pop();
    if(! (0<= e.first && e.first <= 40)) continue;
    if(d[e.first] > 0) continue;

    d[e.first] = e.second;
    if(e.first == b) break;

    q.push(pii(e.first+1,  e.second+1));
    q.push(pii(e.first-1,  e.second+1));
    q.push(pii(e.first+5,  e.second+1));
    q.push(pii(e.first-5,  e.second+1));
    q.push(pii(e.first+10, e.second+1));
    q.push(pii(e.first-10, e.second+1));
  }

  if(a == b)
    cout << 0 << endl;
  else
    cout << d[b] << endl;

  return 0;
}